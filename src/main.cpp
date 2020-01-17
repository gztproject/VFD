#include <Arduino.h>
#include <config.h>
#include <Display.h>
#include <Drive.h>

enum States
{
  boot = 0,
  manual = 10,
  setDmx = 20,
  dmx = 30
};
int state = 0;
int lastMillis = 0;

void setup()
{

// As we are using pin 1 (TX) for output and 2 (RX) for DMX input we cannot use Serial, it is only here for testing purpouses.
#ifdef SERIAL_DEBUG
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
    if (millis() - lastMillis > 5000)
    {
      state = manual;
      lastMillis = millis();
      break;
    }
    Display::printString("GZT");
    break;
  }

  case manual:
  {
    int pot = round(100.0 * (analogRead(POT) * 1.0 / 1024.0));
    int pot2 = round(100.0 * (analogRead(A6) * 1.0 / 1024.0));

    Display::printNumber(pot);
    if (pot > 0)
    {
      Drive::setWidth(pot2);
      Drive::setFrequency(pot / 2);
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
    break;
  }

  case dmx:
  {
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
