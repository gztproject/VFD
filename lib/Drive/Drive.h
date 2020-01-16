#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>

#define ACTIVE_LOW true //true in the actual implementation, using inverse for testing.
#define MAX_FREQUENCY 50
#define MIN_FREQUENCY 5

#define MAX_DUTY_CYCLE 50
#define MIN_DUTY_CYCLE 0

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
    static void setFrequency(uint8_t f);
    static void setWidth(uint8_t w);
    static void energize();
    static void turnOff();
    static void tick();

private:
    static void setInterrupt();
    static uint8_t out1;
    static uint8_t out2;
    static uint8_t frequency;
    static uint8_t width;
    static bool active;
    static uint8_t cnt;
};
#endif