#ifndef DISPLAY_H
#define DISPLAY_H
#include "SevSeg.h"

class Display
{
public:
    static void init(byte a, byte b, byte c, byte d, byte e, byte f, byte g, byte dp, byte ca1, byte ca2, byte ca3);
    static void printNumber(int n);
    static void printDMX(int n);
    static void printString(const char *str);
    static void refresh();

private:
    static bool blinkSw;
    Display(){};
};
#endif