#include <DMX.h>

uint16_t DMX::address;
uint8_t DMX::values[NUM_CHANS];
uint8_t DMX::readings[DMX_SMOOTHING * NUM_CHANS];
uint8_t DMX::readIndex;

void DMX::init(uint16_t addr)
{
    address = addr;
    DMXSerial.init(DMXReceiver);
    DMXSerial.maxChannel(address + NUM_CHANS - 1);
    for (int i = 0; i <= NUM_CHANS; i++)
    {
        DMXSerial.write(address + i, 0);
    }
    readIndex = 0;
    for (int i = 0; i < DMX_SMOOTHING * NUM_CHANS; i++)
    {
        readings[i] = 0;
    }
}

void DMX::read()
{
    for (int i = 0; i < NUM_CHANS; i++)
    {
        if (DMX_SMOOTHING == 0)
        {
            values[i] = DMXSerial.read(address + i);
        }
        else
        {
            readings[(i * DMX_SMOOTHING) + readIndex] = DMXSerial.read(address + i);
            uint32_t total = 0;
            for (int j = 0; j < DMX_SMOOTHING; j++)
            {
                total += readings[(i * DMX_SMOOTHING) + j];
            }
            values[i] = (total / DMX_SMOOTHING);
        }
    }
    readIndex = readIndex < DMX_SMOOTHING - 1 ? readIndex + 1 : 0;
}

bool DMX::hasDMX()
{
    return DMXSerial.noDataSince() < DMX_TIMEOUT;
}

uint16_t DMX::getAddress()
{
    return address;
}