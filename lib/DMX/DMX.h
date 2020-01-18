#ifndef DMX_H
#define DMX_H
#include <Arduino.h>
#include <DMXSerial.h>

#define NUM_CHANS 1
#define DMX_TIMEOUT 5000

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
    DMX(){};
};
#endif