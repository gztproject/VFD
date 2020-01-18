#include <DMX.h>

uint16_t DMX::address;
uint8_t DMX::values[NUM_CHANS];

void DMX::init(uint16_t addr)
{
    address = addr;
    DMXSerial.init(DMXReceiver);
    for (int i = 0; i <= NUM_CHANS; i++)
    {
        DMXSerial.write(address + i, 0);
    }
}

void DMX::read()
{
    for (int i = 0; i < NUM_CHANS; i++)
    {
        values[i] = DMXSerial.read(address + i);
    }
}

bool DMX::hasDMX()
{
    return DMXSerial.noDataSince() < DMX_TIMEOUT;
}

uint16_t DMX::getAddress()
{
    return address;
}