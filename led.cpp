#include <Wire.h>
#include "led.h"
#include "scales.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////DIS_SHIT
const bool led(unsigned int lednum, unsigned int value, bool GPIOOnline)
{
  if (GPIOOnline == 0) return GPIOOnline;
  
  Wire.beginTransmission((uint8_t)(0x40 + (lednum >> 4)));
  Wire.write(6 + ((lednum & 15) << 2));
  if (value == 0) {
    Wire.write(0);
    Wire.write(0);
    Wire.write(0);
    Wire.write(0x10);
    } else if (value < 4096) {
    Wire.write(0);
    Wire.write(0);
    Wire.write(value);
    Wire.write(value >> 8);
    } else {
    Wire.write(0);
    Wire.write(0x10);
    Wire.write(0);
    Wire.write(0);
  }
  int r = Wire.endTransmission();
  if (r != 0)
  {
    GPIOOnline = 0;
  }
  return GPIOOnline;
}



const bool led_synth(int stepCount, int drumDivider, bool GPIOOnline, int buttonMapping[])
{
  for (int x = 0; x < 64; x++)
  {
    if (x % 8 == ((stepCount / drumDivider) % 8))
    {
      GPIOOnline = led(buttonMapping[x], 0, GPIOOnline);
    }
    else
    {
      if (getbit(x))
      GPIOOnline = led(buttonMapping[x], 4095, GPIOOnline);
      else
      GPIOOnline = led(buttonMapping[x], 0, GPIOOnline);
    }
  }
  return GPIOOnline; 
}

const bool led_drum(int stepCount, int drumDivider, bool GPIOOnline, int buttonMapping[])
{
  for (int x = 64; x < 104; x++)
  {
    if (x % 8 == ((stepCount / drumDivider) % 8))
    {
      GPIOOnline = led(buttonMapping[x], 0, GPIOOnline);
    }
    else
    {
      if (getbit(x))
      GPIOOnline = led(buttonMapping[x], 4095, GPIOOnline);
      else
      GPIOOnline = led(buttonMapping[x], 0, GPIOOnline);
    }
  }
  return GPIOOnline;
}
