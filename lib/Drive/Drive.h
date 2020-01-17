#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>

//#define SERIAL_DEBUG

#define ACTIVE_LOW true //true in the actual implementation, using inverse for testing.
#define MAX_DRIVE_FREQUENCY 50
#define MIN_DRIVE_FREQUENCY 5

#define MAX_DRIVE_DUTY_CYCLE 40
#define DEFAULT_DRIVE_DUTY_CYCLE 40
#define MIN_DRIVE_DUTY_CYCLE 0

#define PWM_FACTOR 1000
#define PWM_WINDOW 10


/**
 * Outputs two frequency and width controlled PWM pulses with 180° phase difference.
 * 
 * (30% duty cycle shown here)
 * 
 *      |  |------|  |------|  |------|  |------|  |--
 * Out1:|  |      |  |      |  |      |  |      |  |
 *      |__|      |__|      |__|      |__|      |__|
 *      0123456789012345678901234567890123456789012345
 *      -----|  |------|  |------|  |------|  |------|
 * Out2:     |  |      |  |      |  |      |  |      |
 *           |__|      |__|      |__|      |__|      |
**/
class Drive
{
public:
    static void init(uint8_t output1, uint8_t output2);
    static int8_t setFrequency(uint8_t f);
    static int8_t setWidth(uint8_t w);
    static void energize();
    static void turnOff();
    static void tick();

private:
    static void setInterrupt();
    static void populatePwmLookup();
    static uint8_t out1;
    static uint8_t out2;
    static uint8_t frequency;
    static uint16_t width;
    static bool active;
    static uint16_t cnt; //Counts the interrupts and resets at PWM_FREQUENCY
    static uint16_t pwmCnt;
    static uint8_t pwmLookup[];
};
#endif