#ifndef DMX_H
#define DMX_H
#include <Arduino.h>
#include "config.h"
#include <DMXSerial.h>

#define NUM_CHANS 1
#define DMX_TIMEOUT 3000
#define BREAKSPEED 220000

class DMX
{
public:
    static uint8_t values[];
    static void init(uint16_t addr);
    static void read();
    static bool hasDMX();
    static uint16_t getAddress();

private:
    static uint16_t address;
    static uint8_t readings[];
    static uint8_t readIndex; // the index of the current reading
    DMX(){};
};
#endif