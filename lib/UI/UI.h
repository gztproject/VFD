#ifndef UI_H
#define UI_H
#include "SevSeg.h"
#define BTN1 0x01
#define BTN2 0x02
#define BTN3 0x04

class UI
{
public:
    static void init(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t dp, uint8_t ca1, uint8_t ca2, uint8_t ca3, uint8_t btn1, uint8_t btn2, uint8_t btn3);
    static void printNumber(int n);
    static void printDMX(int n);
    static void printString(const char *str);
    static void refresh();
    static uint8_t buttons;

private:
    static uint8_t btn1pin;
    static uint8_t btn2pin;
    static uint8_t btn3pin;
    UI(){};
};
#endif