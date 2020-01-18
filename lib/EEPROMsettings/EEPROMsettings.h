#ifndef EEPROM_SETTINGS_H
#define EEPROM_SETTINGS_H
#include <Arduino.h>
#include <util/crc16.h>
#include <EEPROM.h>

//#define SERIAL_DEBUG

struct settingsContainer
{
    uint16_t dmxAddress;
    uint8_t driveDutyCycle;
};

struct EEPROMpacket
{
    settingsContainer settings;
    uint16_t checksum;
};

class EEPROMsettings
{
public:
    //Check and init EEPROM if needed;
    static void initEEPROM(uint8_t addr, settingsContainer def);
    static void saveDMXAddress(uint16_t newAddress);
    static void saveDriveDutyCycle(uint8_t dutyCycle);
    static settingsContainer getSettings();
private:
    static settingsContainer settings;
    static bool initialized;
    static uint8_t address;
    static uint16_t getChecksum(settingsContainer settings);
    EEPROMsettings(){};
};


#endif