#include <Arduino.h>
#include <config.h>
#include <EEPROMsettings.h>
#include <Display.h>
#include <Drive.h>
#include <DMX.h>

//#define SERIAL_DEBUG

enum States
{
  boot = 0,
  logo = 10,
  manual = 20,
  setDmx = 30,
  setDutyCycle = 40,
  dmx = 50
};
uint8_t state = 0;
uint16_t lastMillis = 0;

void setup()
{

// As we are using pin 1 (TX) for output and 2 (RX) for DMX input we cannot use Serial, it is only here for testing purpouses.
#ifdef SERIAL_DEBUG
#warning Serial debugging has been enabled! This disables IGBT outputs and  DMX input.
  Serial.begin(115200);
  while (!Serial)
  {
  }
#endif

  Display::init(DISP_A, DISP_B, DISP_C, DISP_D, DISP_E, DISP_F, DISP_G, DISP_DP, DISP_CA1, DISP_CA2, DISP_CA3);
  lastMillis = millis();
  Drive::init(TRIG_POS, TRIG_NEG);
}

void loop()
{

  switch (state)
  {
  case boot:
  {
    settingsContainer defaults = {
        1,                       //Default DMX address
        DEFAULT_DRIVE_DUTY_CYCLE //Default duty cycle from Drive.h
    };
    EEPROMsettings::initEEPROM(EEPROM_ADDRESS, defaults);

    DMX::init(EEPROMsettings::getSettings().dmxAddress);
    Drive::setWidth(EEPROMsettings::getSettings().driveDutyCycle);
    state = logo;
    lastMillis = millis();
    break;
  }

  case logo:
  {
    if (millis() - lastMillis > 5000)
    {
      state = manual;
      break;
    }
    Display::printString("GZT");
    break;
  }

  case manual:
  {
    if (DMX::hasDMX())
    {
      state = dmx;
      break;
    }
    int pot = round(100.0 * (analogRead(POT) * 1.0 / 1024.0));

    Display::printNumber(pot);
    if (pot > 0)
    {
      Drive::setFrequency(MAX_DRIVE_FREQUENCY * (pot * 1.0 / 100.0));
      Drive::energize();
    }
    else
    {
      Drive::turnOff();
    }

    break;
  }

  case setDmx:
  {
    uint16_t newAddress = 503; //ToDo: UI input
    EEPROMsettings::saveDMXAddress(newAddress);
    DMX::init(EEPROMsettings::getSettings().dmxAddress);
    break;
  }

  case setDutyCycle:
  {
    uint8_t newDriveDutyCycle = DEFAULT_DRIVE_DUTY_CYCLE; //ToDo: UI input
    EEPROMsettings::saveDriveDutyCycle(newDriveDutyCycle);
    Drive::turnOff();
    Drive::setWidth(EEPROMsettings::getSettings().driveDutyCycle);
    Drive::energize();
    break;
  }

  case dmx:
  {
    if (!DMX::hasDMX())
    {
      state = manual;
      break;
    }
      Display::printDMX(DMX::getAddress());

    DMX::read();
    Drive::setFrequency(MAX_DRIVE_FREQUENCY * (DMX::values[0] * 1.0 / 255.0));
    break;
  }

  default:
  {
    Display::printString("Err");
    break;
  }
  }
  Display::refresh();
}
