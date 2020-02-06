#include "UI.h"
SevSeg sevseg;
uint8_t UI::btn1pin = BTN1PIN;
uint8_t UI::btn2pin = BTN2PIN;
uint8_t UI::btn3pin = BTN3PIN;
uint8_t UI::potPin = POTPIN;
uint8_t UI::buttons = 0x00;
uint8_t UI::readings[FADER_SMOOTHING];
uint8_t UI::readIndex;

void UI::init()
{
    uint8_t numDigits = 3;
    uint8_t digitPins[] = {DISP_CA1, DISP_CA2, DISP_CA3};
    uint8_t segmentPins[] = {DISP_A, DISP_B, DISP_C, DISP_D, DISP_E, DISP_F, DISP_G, DISP_DP};

    bool resistorsOnSegments = true;       // 'false' means resistors are on digit pins
    uint8_t hardwareConfig = COMMON_ANODE; // See README.md for options
    bool updateWithDelays = false;         // Default 'false' is Recommended
    bool leadingZeros = false;             // Use 'true' if you'd like to keep the leading zeros
    bool disableDecPoint = false;          // Use 'true' if your decimal point doesn't exist or isn't connected

    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
                 updateWithDelays, leadingZeros, disableDecPoint);
    sevseg.setBrightness(90);

    readIndex = 0;
    for (int thisReading = 0; thisReading < FADER_SMOOTHING; thisReading++)
    {
        readings[thisReading] = 0;
    }
}

void UI::printNumber(int n)
{
    sevseg.setNumber(n, -1);
}

void UI::printDMX(int n)
{
    sevseg.setNumber(n, 0);
}

void UI::printString(const char *str)
{
    sevseg.setChars(str);
}

void UI::refresh()
{
    sevseg.refreshDisplay(); // Must run repeatedly

    buttons = (analogRead(btn1pin) < 512) ? BTN1 : 0;
    buttons |= (analogRead(btn2pin) < 512) ? BTN2 : 0;
    buttons |= (analogRead(btn3pin) < 512) ? BTN3 : 0;
}

uint8_t UI::readPot()
{
    if (FADER_SMOOTHING == 0)
        return round(100.0 * (readPotCorrected() * 1.0 / 1024.0));

    //total = total - readings[readIndex];
    readings[readIndex] = round(100.0 * (readPotCorrected() * 1.0 / 1024.0));
    //total = total + readings[readIndex];
    uint32_t total = 0;
    for (int i = 0; i < FADER_SMOOTHING; i++)
    {
        total += readings[i];
    }

    readIndex = readIndex < FADER_SMOOTHING - 1 ? readIndex + 1 : 0;

    return round(total / FADER_SMOOTHING);
}

uint16_t UI::readPotCorrected()
{
    float value = analogRead(potPin);
    float topOffset = (MAX_FADER_READING * 1024.0 / 100.0);
    float linError = 1024.0 - topOffset;

    return value + (linError * (value / topOffset));
}