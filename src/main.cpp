#include <Arduino.h>
#include <config.h>
#include <EEPROMsettings.h>
#include <UI.h>
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
  dmx = 50,
  error = 99,
};
uint8_t state = 0;
uint16_t lastMillis = 0;
int16_t newAddress = -1;
int8_t newDriveDutyCycle = -1;
uint8_t pot = 0;

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

  UI::init(DISP_A, DISP_B, DISP_C, DISP_D, DISP_E, DISP_F, DISP_G, DISP_DP, DISP_CA1, DISP_CA2, DISP_CA3, BTN1PIN, BTN2PIN, BTN3PIN);
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
    UI::printString("GZT");
    break;
  }

  case manual:
  {
    if (DMX::hasDMX())
    {
      state = dmx;
      Drive::turnOff();
      break;
    }

    if (millis() - lastMillis < MENU_SHOW_TIME)
    {
      UI::printString("FAd");
      break;
    }

    if (UI::buttons & BTN3)
    {
      state = setDmx;
      lastMillis = millis();
      newAddress = -1;
      break;
    }

    UI::printNumber(pot);
    break;
  }

  case setDmx:
  {
    if (millis() - lastMillis < MENU_SHOW_TIME && newAddress == -1)
    {
      UI::printString("Add");
      break;
    }

    if (newAddress == -1)
      newAddress = DMX::getAddress();
    
    if (UI::buttons & BTN2 && millis() - lastMillis > 100)
    {
      newAddress++;
      lastMillis = millis();
    }

    if (UI::buttons & BTN1 && millis() - lastMillis > 100)
    {
      newAddress--;
      lastMillis = millis();
    }

    newAddress = newAddress == 513 - NUM_CHANS ? 1 : newAddress == 0 ? 512 - NUM_CHANS : newAddress;
    newAddress = constrain(newAddress, 1, 512 - NUM_CHANS);
    UI::printDMX(newAddress);
    
    if (millis() - lastMillis > MENU_TIMEOUT)
    {
      state = manual;
      lastMillis = millis();
      break;
    }

    if (UI::buttons & BTN3)
    {
      EEPROMsettings::saveDMXAddress(newAddress);
      DMX::init(EEPROMsettings::getSettings().dmxAddress);
      state = setDutyCycle;
      newDriveDutyCycle = -1;
      lastMillis = millis();
      break;
    }

    break;
  }

  case setDutyCycle:
  {
    if (millis() - lastMillis < MENU_SHOW_TIME && newDriveDutyCycle == -1)
    {
      UI::printString("DTY");
      break;
    }
    
    if (newDriveDutyCycle == -1)
      newDriveDutyCycle = Drive::getWidth();

    if (UI::buttons & BTN2 && millis() - lastMillis > 100)
    {
      newDriveDutyCycle++;
      lastMillis = millis();
    }
    if (UI::buttons & BTN1 && millis() - lastMillis > 100)
    {
      newDriveDutyCycle--;
      lastMillis = millis();
    }
    newDriveDutyCycle = constrain(newDriveDutyCycle, MIN_DRIVE_DUTY_CYCLE, MAX_DRIVE_DUTY_CYCLE);
    UI::printNumber(newDriveDutyCycle);

    if (millis() - lastMillis > MENU_TIMEOUT)
    {
      state = DMX::hasDMX() ? dmx : manual;
      lastMillis = millis();
      break;
    }   

    if (UI::buttons & BTN3)
    {
      EEPROMsettings::saveDriveDutyCycle(newDriveDutyCycle);
      bool restart = Drive::isActive();
      restart ? Drive::turnOff() : (void)0;
      Drive::setWidth(EEPROMsettings::getSettings().driveDutyCycle);
      restart ? Drive::energize() : (void)0;
      state = manual;
      lastMillis = millis();
      break;
    }

    break;
  }

  case dmx:
  {
    if (!DMX::hasDMX())
    {
      state = manual;
      Drive::turnOff();
      break;
    }

    if (millis() - lastMillis < MENU_SHOW_TIME)
    {
      UI::printString("DNX");
      break;
    }

    if (UI::buttons & BTN3)
    {
      state = setDmx;
      newAddress = -1;
      lastMillis = millis();
      break;
    }

    UI::printDMX(DMX::getAddress());

    break;
  }

  default:
  {
    state = error;
    UI::printString("Err");
    while (1)
    {
      UI::refresh();
    }
  }
  }

  if (!(DMX::hasDMX() || state == error))
  {
    pot = round(100.0 * (analogRead(POTPIN) * 1.0 / 1024.0));

    if (pot > 0)
    {
      Drive::setFrequency(MAX_DRIVE_FREQUENCY * (pot * 1.0 / 100.0));
      Drive::energize();
    }
    else
    {
      Drive::turnOff();
    }
  }

  if (DMX::hasDMX() && state != error)
  {
    DMX::read();
    uint8_t freq = MAX_DRIVE_FREQUENCY * (DMX::values[0] * 1.0 / 255.0);
    if (freq > 0)
    {
      Drive::setFrequency(freq);
      Drive::energize();
    }
    else
    {
      Drive::turnOff();
    }
  }
  UI::refresh();
}
