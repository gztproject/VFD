#ifndef UI_H
#define UI_H
#include <Arduino.h>
#include "config.h"
#include "SevSeg.h"
#define BTN1 0x01
#define BTN2 0x02
#define BTN3 0x04

class UI
{
public:
    static void init();
    static void printNumber(int n);
    static void printDMX(int n);
    static void printString(const char *str);
    static void refresh();
    static uint8_t readPot();
    static uint8_t buttons;

private:
    static uint8_t btn1pin;
    static uint8_t btn2pin;
    static uint8_t btn3pin;
    static uint8_t potPin;
    static uint8_t readings[];
    static uint8_t readIndex; // the index of the current reading
    static uint16_t readPotCorrected();
    UI(){};
};
#endif