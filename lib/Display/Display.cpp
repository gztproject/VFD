#include "Display.h"
SevSeg sevseg;
bool Display::blinkSw = false;

void Display::init(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte dp, byte ca1, byte ca2, byte ca3)
{    
    byte numDigits = 3;
    byte digitPins[] = {ca1, ca2, ca3};
    byte segmentPins[] = {a, b, c, d, e, f, g, dp};
    bool resistorsOnSegments = false;   // 'false' means resistors are on digit pins
    byte hardwareConfig = COMMON_ANODE; // See README.md for options
    bool updateWithDelays = false;      // Default 'false' is Recommended
    bool leadingZeros = false;          // Use 'true' if you'd like to keep the leading zeros
    bool disableDecPoint = false;       // Use 'true' if your decimal point doesn't exist or isn't connected

    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
                 updateWithDelays, leadingZeros, disableDecPoint);
    sevseg.setBrightness(90);
}

void Display::printNumber(int n)
{
    sevseg.setNumber(n, 1);    
}

void Display::printDMX(int n)
{
    sevseg.setNumber(n, 0);  
}

void Display::printString(const char *str)
{
    sevseg.setChars(str);    
}

void Display::refresh()
{
    sevseg.refreshDisplay(); // Must run repeatedly
}