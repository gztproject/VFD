#include "UI.h"
SevSeg sevseg;
uint8_t UI::btn1pin = 0;
uint8_t UI::btn2pin = 0;
uint8_t UI::btn3pin = 0;
uint8_t UI::buttons = 0x00;

void UI::init(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t dp, uint8_t ca1, uint8_t ca2, uint8_t ca3, uint8_t btn1, uint8_t btn2, uint8_t btn3)
{
    uint8_t numDigits = 3;
    uint8_t digitPins[] = {ca1, ca2, ca3};
    uint8_t segmentPins[] = {a, b, c, d, e, f, g, dp};
    bool resistorsOnSegments = true;      // 'false' means resistors are on digit pins
    uint8_t hardwareConfig = COMMON_ANODE; // See README.md for options
    bool updateWithDelays = false;         // Default 'false' is Recommended
    bool leadingZeros = false;             // Use 'true' if you'd like to keep the leading zeros
    bool disableDecPoint = false;          // Use 'true' if your decimal point doesn't exist or isn't connected

    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
                 updateWithDelays, leadingZeros, disableDecPoint);
    sevseg.setBrightness(90);

    btn1pin = btn1;
    btn2pin = btn2;
    btn3pin = btn3;
}

void UI::printNumber(int n)
{
    sevseg.setNumber(n, 1);
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

    buttons = (analogRead(btn1pin) < 512)?BTN1:0;
    buttons |= (analogRead(btn2pin) < 512)?BTN2:0;
    buttons |= (analogRead(btn3pin) < 512)?BTN3:0;
}