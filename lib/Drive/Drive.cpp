#include "Drive.h"

bool Drive::active;
uint8_t Drive::out1;
uint8_t Drive::out2;
uint16_t Drive::width;
uint8_t Drive::frequency;
uint16_t Drive::cnt;
uint16_t Drive::pwmCnt;
volatile uint8_t Drive::pwmLookup[PWM_FACTOR];

void Drive::init(uint8_t output1, uint8_t output2)
{
    out1 = output1;
    out2 = output2;
    pinMode(out1, OUTPUT);
    digitalWrite(out1, ACTIVE_LOW?HIGH:LOW);
    pinMode(out2, OUTPUT);    
    digitalWrite(out2, ACTIVE_LOW?HIGH:LOW);
    frequency = MIN_DRIVE_FREQUENCY;
    width = DEFAULT_DRIVE_DUTY_CYCLE;
    populatePwmLookup();
    cnt = 0;
    pwmCnt = 0;
    active = false;
}

int8_t Drive::setFrequency(uint8_t f)
{
    if (abs(frequency - f) > 1 && f >= MIN_DRIVE_FREQUENCY && f <= MAX_DRIVE_FREQUENCY)
    {
        frequency = constrain(f, MIN_DRIVE_FREQUENCY, MAX_DRIVE_FREQUENCY);
        setInterrupt();
        return frequency;
    }
    return frequency;
}

int8_t Drive::setWidth(uint8_t w)
{
    if (active)
        return -1;
    if (width != w && w >= MIN_DRIVE_DUTY_CYCLE && w <= MAX_DRIVE_DUTY_CYCLE)
    {
        width = constrain(w, MIN_DRIVE_DUTY_CYCLE, MAX_DRIVE_DUTY_CYCLE);
        pwmCnt = 0;
        populatePwmLookup();
        return width;
    }
}

void Drive::energize()
{
    if (!active)
    {
        active = true;
        cnt = 0;
        pwmCnt = 0;
        setInterrupt();
    }
}

void Drive::turnOff()
{   
    active = false;
    digitalWrite(out1, ACTIVE_LOW?HIGH:LOW);
    digitalWrite(out2, ACTIVE_LOW?HIGH:LOW);
}

void Drive::tick()
{
    if (active)
    {
        bool pwm = pwmCnt < pwmLookup[cnt];

        bool o1 = (cnt < width * 10) && pwm;
        bool o2 = cnt > (uint16_t)(PWM_FACTOR / 2) && cnt < (width * 10) + (uint16_t)(PWM_FACTOR / 2) && pwm;

        digitalWrite(out1, !(o1 ^ !ACTIVE_LOW)?HIGH:LOW);
        digitalWrite(out2, !(o2 ^ !ACTIVE_LOW)?HIGH:LOW);
        cnt = cnt >= PWM_FACTOR - 1 ? 0 : cnt + 1;
        pwmCnt = pwmCnt >= PWM_WINDOW - 1 ? 0 : pwmCnt + 1;
    }
}

bool Drive::isActive()
{
    return active;
}

uint8_t Drive::getWidth()
{
    return width;
}

void Drive::populatePwmLookup()
{
    for (uint16_t i = 0; i < PWM_FACTOR; i++)
    {
        uint16_t quarter = i;
        if (quarter > PWM_FACTOR / 2)
            quarter = quarter - PWM_FACTOR / 2;
        if (quarter > width * 10 / 2)
            quarter = width * 10 >= quarter ? width * 10 - quarter : 0;

        pwmLookup[i] = quarter <= width * 10 ? PWM_WINDOW * sin((PI / 2) * quarter / (width * 10 / 2)) : 0;

#ifdef SERIAL_DEBUG
        Serial.print("cnt: ");
        Serial.print(i);
        Serial.print("; 1/4: ");
        Serial.print(quarter);
        Serial.print("; value: ");
        Serial.println(pwmLookup[i]);
#endif
    }
}

void Drive::setInterrupt()
{
    noInterrupts(); //stop interrupts

    //set timer0 interrupt at our desired timing
    TCCR1A = 0; // set entire TCCR2A register to 0
    TCCR1B = 0; // same for TCCR2B
    TCNT0 = 0;  //initialize counter value to 0
    /** set compare match register for timing increments (we want to check 100 times per cycle)
     * From https://oscarliang.com/arduino-timer-and-interrupt-tutorial/ :
     * Different clock sources can be selected for each timer independently. To calculate the timer frequency (for example 2Hz using Timer1) you will need:
     *   1. CPU frequency 16Mhz for Arduino
     *   2. maximum timer counter value (256 for 8bit, 65536 for 16bit timer)
     *   3. Divide CPU frequency through the chosen pre-scaler (16000000 / 256 = 62500)
     *   4. Divide result through the desired frequency (62500 / 2Hz = 31250)
     *   5. Verify the result against the maximum timer counter value (31250 < 65536 success) if fail, choose bigger pre-scaler.
     * Prescalers: 
     * |    CS12    |   CS11    |   CS10    |   Description     |
     * |    0       |   0       |   0       |   Timer stopped   |
     * |    0       |   0       |   1       |   Prescaler 1     |
     * |    0       |   1       |   0       |   Prescaler 8     |
     * |    0       |   1       |   1       |   Prescaler 64    |
     * |    1       |   0       |   0       |   Prescaler 256   |
     * |    1       |   0       |   1       |   Prescaler 1024  |
     * |    1       |   1       |   0       | EXT CLK on T1 fall|
     * |    1       |   1       |   1       | EXT CLK on T1 rise|  
     **/

    uint16_t cmp = ((16000000.0) / (1.0 * (1.0 * frequency * 1.0 * PWM_FACTOR))) - 1.0;
    //uint16_t cmp = 2500.0 * (1.0/frequency);
    // Serial.print("f = ");
    // Serial.print(frequency);
    // Serial.print(", 1/f = ");
    // Serial.print(1.0 / frequency * 1.00);
    // Serial.print(" -> ");
    // Serial.println(cmp);
    OCR1A = cmp; // (must be < 65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set prescaler
    TCCR1B |= (1 << CS10); // | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);

    interrupts(); //allow interrupts
}

ISR(TIMER1_COMPA_vect)
{
    Drive::tick();
}
