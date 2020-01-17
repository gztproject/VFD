#ifndef DRIVE_H
#define DRIVE_H
#include <Arduino.h>

//#define SERIAL_DEBUG

#define ACTIVE_LOW true //true in the actual implementation, used inverse for some testing.


#define MAX_DRIVE_FREQUENCY 50
#define MIN_DRIVE_FREQUENCY 5

/**
 * Half-period duty cycle. Multiply by 2 to get full period duty cycle.
 * We shouldn't exceed 40% here in order to give IGBT's time to discharge between pos. and neg. half-cycles.
 */
#define MAX_DRIVE_DUTY_CYCLE 40 //TLDR: Keep this under 40% not to fry the IGBTs!
#define DEFAULT_DRIVE_DUTY_CYCLE 33 // Starting off with 33% (220V/350V = 66%)
#define MIN_DRIVE_DUTY_CYCLE 0

#define PWM_FACTOR 1000 //Multiplier for the base frequency (how many subdivisions we have in 1Hz)
#define PWM_WINDOW 10 //Number of subdivisions to use as a base for PWM. 0 to disable PWM


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