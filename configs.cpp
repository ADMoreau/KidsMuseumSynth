#include <stdint.h>
#include "configs.h"
#include <Wire.h>
#include "scales.h"
#include <Audio.h>

int bank1SwitchState = 0; //////////////////////////////////////////////DRUM
int bank2SwitchState = 0;
int bank3SwitchState = 0;
int bank4SwitchState = 0;
int bank5SwitchState = 0;

int aSwitchState = 0;
int bSwitchState = 0;
int cSwitchState = 0;
int dSwitchState = 0;
int eSwitchState = 0;
int fSwitchState = 0;
int gSwitchState = 0;

int minorSwitchState = 0;
int majorSwitchState = 0;
int minorHSwitchState = 0;


  //////////////////////////////////////////////////////////////////////////////////////////////////////DIS_SHIT
const void pca9685_config(uint8_t addr)
{
  Wire.beginTransmission(addr);
  Wire.write(0);
  Wire.write(0x20);
  Wire.write(0x04);
  Wire.endTransmission();
}

  //////////////////////////////////////////////////////////////////////////////////////////////////////DIS_SHIT
const void mcp23017_config(uint8_t addr, uint16_t dir)
{
  Wire.beginTransmission(addr);
  Wire.write(0x00);
  Wire.write(dir & 255);
  Wire.write(dir >> 8);
  Wire.endTransmission();
}

const void waveforms_envelopes_init()
{
  //waveformx_init(amplitude, pulseWidth) waveform declared in function
  waveform1_init(.75, .5);
  //envelopex_init(attack, hold, decay, sustain, release)
  envelope1_init(10, 10, 25, 0.4, 70);

  waveform2_init(.75, .5);
  envelope2_init(10, 10, 25, 0.4, 70);

  waveform3_init(.75, .5);
  envelope3_init(10, 10, 25, 0.4, 70);

  waveform4_init(.75, .5);
  envelope4_init(10, 10, 25, 0.4, 70);

  waveform5_init(.75, .5);
  envelope5_init(10, 10, 25, 0.4, 70);

  waveform6_init(.75, .5);
  envelope6_init(10, 10, 25, 0.4, 70);

  waveform7_init(.75, .5);
  envelope7_init(10, 10, 25, 0.4, 70);

  waveform8_init(.75, .5);
  envelope8_init(10, 10, 25, 0.4, 70);

  waveform9_init(.75, .5);
  envelope9_init(10, 10, 25, 0.4, 70);

  waveform10_init(.75, .5);
  envelope10_init(10, 10, 25, 0.4, 70);

  waveform11_init(.75, .5);
  envelope11_init(10, 10, 25, 0.4, 70);

  waveform12_init(.75, .5);
  envelope12_init(10, 10, 25, 0.4, 70);

  waveform13_init(.75, .5);
  envelope13_init(10, 10, 25, 0.4, 70);

  waveform14_init(.75, .5);
  envelope14_init(10, 10, 25, 0.4, 70);

  waveform15_init(.75, .5);
  envelope15_init(10, 10, 25, 0.4, 70);

  waveform16_init(.75, .5);
  envelope16_init(10, 10, 25, 0.4, 70);
}

const void pca9685_config_init()
{
  pca9685_config(0x40);
  pca9685_config(0x41);
  pca9685_config(0x42);
  pca9685_config(0x43);
  pca9685_config(0x44);
  pca9685_config(0x45);
  pca9685_config(0x46);
}

const void mcp23017_config_init()
{
  mcp23017_config(0x20, 0xFFFF);
  mcp23017_config(0x21, 0xFFFF);
  mcp23017_config(0x22, 0xFFFF);
  mcp23017_config(0x23, 0xFFFF);
  mcp23017_config(0x24, 0xFFFF);
  mcp23017_config(0x25, 0xFFFF);
  mcp23017_config(0x26, 0xFFFF);
}

const void keySwitchStateRead()
{
  aSwitchState = digitalRead(25);
  bSwitchState = digitalRead(26);
  cSwitchState = digitalRead(27);
  dSwitchState = digitalRead(28);
  eSwitchState = digitalRead(29);
  fSwitchState = digitalRead(30);
  gSwitchState = digitalRead(24);
}

const void scaleSwitchStateRead()
{
  minorSwitchState = digitalRead(32);
  majorSwitchState = digitalRead(33);
  minorHSwitchState = digitalRead(34);
}

const void bankSwitchStateRead()
{
  bank1SwitchState = digitalRead(35);
  bank2SwitchState = digitalRead(36);
  bank3SwitchState = digitalRead(37);
  bank4SwitchState = digitalRead(38);
  bank5SwitchState = digitalRead(39);
}

const int scale_sel()
  {

    int scaleSel;
    if (aSwitchState == LOW){
      scaleSel = 0;
    }

    else if(bSwitchState == LOW){
      scaleSel = 1;
    }

    else if(cSwitchState == LOW){
      scaleSel = 2;
    }

    else if (dSwitchState == LOW){
      scaleSel = 3;
    }

    else if (eSwitchState == LOW){
      scaleSel = 4;
    }

    else if (fSwitchState == LOW){
      scaleSel = 5;
    }

    else if (gSwitchState == LOW){
      scaleSel = 6;
    }
    return scaleSel;
  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////DRUMS
const void bank_sel(int* bankSel)
  {
    if (bank1SwitchState == LOW){
      *bankSel = 0;
    }

    else if(bank2SwitchState == LOW){
      *bankSel = 1;
    }

    else if(bank3SwitchState == LOW){
      *bankSel = 2;
    }

    else if (bank4SwitchState == LOW){
      *bankSel = 3;
    }

    else if (bank5SwitchState == LOW){
      *bankSel = 4;
    }
  }

const int key_sel(){
  int keySel;
  if (minorSwitchState == LOW){
    keySel = 0;
  }
  else if (majorSwitchState == LOW){
     keySel = 1;
  }
  else if (minorHSwitchState == LOW){
    keySel = 2;
  }
  return keySel;
}

