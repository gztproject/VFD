#include <EEPROMsettings.h>

bool EEPROMsettings::initialized;
uint8_t EEPROMsettings::address;
settingsContainer EEPROMsettings::settings;

void EEPROMsettings::initEEPROM(uint8_t addr, settingsContainer def)
{
    initialized = true;
    address = addr;
    EEPROMpacket packet = {0};
    EEPROM.get(address, packet);
    settings = packet.settings;

#ifdef SERIAL_DEBUG
    Serial.print("Read from EEPROM address ");
    Serial.print(address);
    Serial.print(": DMX address: ");
    Serial.print(settings.dmxAddress);
    Serial.print(", duty cycle: ");
    Serial.print(settings.driveDutyCycle);
    Serial.print(", checksum:");
    Serial.print(packet.checksum);
    Serial.print(", calculated:");
    Serial.println(getChecksum(settings));
#endif

    

    if (getChecksum(settings) == packet.checksum)
        return;

#ifdef SERIAL_DEBUG
    Serial.print("CHECKSUMS DO NOT MATCH! (should be ");
    Serial.print(getChecksum(settings));
    Serial.println(").");
#endif
    settings = def;
    packet.settings = settings;
    packet.checksum = getChecksum(settings);
    EEPROM.put(address, packet);
}

settingsContainer EEPROMsettings::getSettings()
{
    if (!initialized)
    {
#ifdef SERIAL_DEBUG
        Serial.println("EEPROM NOT INITIALIZED!");
#endif
        return {0};
    }

    return settings;
}

void EEPROMsettings::saveDMXAddress(uint16_t address)
{
    if (!initialized)
        return;

    settings.dmxAddress = address;
    EEPROMpacket packet =
        {
            settings,             //settingsContainer
            getChecksum(settings) //checksum
        };
    EEPROM.put(address, packet);
}

void EEPROMsettings::saveDriveDutyCycle(uint8_t dutyCycle)
{
    if (!initialized)
        return;
    settings.driveDutyCycle = dutyCycle;
    EEPROMpacket packet =
        {
            settings,             //settingsContainer
            getChecksum(settings) //checksum
        };
    EEPROM.put(address, packet);
}

uint16_t EEPROMsettings::getChecksum(settingsContainer data)
{
    uint16_t crc = 7; // starting value as you like, must be the same before each calculation
    const byte *p = (const byte *)&data;
    for (uint16_t i = 0; i < sizeof(data); i++) // for each byte in data
    {
        crc = _crc16_update(crc, *p++); // update the crc value
    }
    return crc;
}
