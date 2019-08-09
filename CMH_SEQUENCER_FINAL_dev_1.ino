//SAFE VERSION OF FINAL VERSION 
//DEV 1

#include "scales.h"
#include "configs.h"
#include "led.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>

// Global Clock
elapsedMillis sinceTempo;
int clockDuration;
int drumDivider = 8;

//Synth variables
float tempo = 80;
int stepCount;
boolean selectedSample[8];
int lastOn;
int totalOn;
int offThreshold = 20;
boolean GPIOOnline = 1;

int bankSel = 0;
int buttonSelection=0;
int buttonSelectionD=0;

//////////////////////////////////////////////DRUM
//Drum Machine variables
int stepCountD;
boolean selectedSampleD[5];
int lastOnD;
int totalOnD;

int buttonMapping[104]=
{
0 ,8, 16, 24, 32, 40, 48, 56, 
1, 9, 17, 25, 33, 41, 49, 57, 
2, 10, 18,26, 34, 42, 50, 58, 
3, 11, 19, 27, 35, 43, 51, 59, 
4, 12, 20, 28, 36, 44, 52, 60,
5, 13, 21, 29, 37, 45, 53, 61,
6, 14, 22, 30, 38, 46, 54, 62,
7, 15, 23, 31, 39, 47, 55, 63,
64, 69, 74, 79, 84, 89, 94, 99, 
65, 70, 75, 80, 85, 90, 95, 100, 
66, 71, 76, 81, 86, 91, 96, 101, 
67, 72, 77, 82, 87, 92, 97, 102,
68, 73, 78, 83, 88, 93, 98, 103
};

boolean currentButtons[112];
boolean lastButtons[112];
int buttonCount = 0;

//MAYNE
//int stepLEDmapping[8] = { 38, 37, 36, 35, 34, 33, 32, 39 };


/////SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUSETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP/SETUP
void setup() {
  pinMode(25, INPUT_PULLUP); //Scale1
  pinMode(26, INPUT_PULLUP); //Scale2
  pinMode(27, INPUT_PULLUP); //Scale3
  pinMode(28, INPUT_PULLUP); //Scale4
  pinMode(29, INPUT_PULLUP); //Scale5
  pinMode(30, INPUT_PULLUP); //Scale6
  pinMode(31, INPUT_PULLUP); //Scale7
  pinMode(32, INPUT_PULLUP); //Key1 
  pinMode(33, INPUT_PULLUP); //Key2
  pinMode(34, INPUT_PULLUP); //Key3
  pinMode(35, INPUT_PULLUP); //DrumBank1
  pinMode(36, INPUT_PULLUP); //DrumBank2
  pinMode(37, INPUT_PULLUP); //DrumBank3
  pinMode(38, INPUT_PULLUP); //DrumBank4
  pinMode(39, INPUT_PULLUP); //DrumBank5
  pinMode(0, INPUT_PULLUP); //Waveform Select
  

  Serial1.setTX(5); //prev 26
  Serial1.setRX(21); //prev 27
  Serial1.begin(38400);
  analogReadResolution(10);
  audio_init();
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////DIS_SHIT
  // Wire
  Wire.begin();
  Wire.setClock(400000);
  pca9685_config_init();
  mcp23017_config_init();
  mixer_init();
  waveforms_envelopes_init();
    
}//////////END_SETUP/END_SETUP/END_SETUP/END_SETUP/END_SETUP/END_SETUP/END_SETUP/END_SETUP/END_SETUP/END_SETUP/END_SETUP/END_SETUP/

//////////////////////////////////////////////////////////////////////////////////////////////////////DIS_SHIT
void buttons_update(void)
{
  int numExpanders=7;
  for(int e=0;e<numExpanders;e++)
  {
      int r;
      Wire.beginTransmission(0x20+e);
      Wire.write(0x12);
      r=Wire.endTransmission(false);
      if(r!=0)
      {
        GPIOOnline=0;
        return;
      }
      Wire.requestFrom(0x20+e, 2);
      if (Wire.available() >= 2) 
      {
        word state;
        state = Wire.read();
        state |= Wire.read() << 8;
        for(int i=0;i<16;i++)
        {
          lastButtons[i+16*e]=currentButtons[i+16*e];
          currentButtons[i+16*e]=bitRead(state,i);
        }
        
      }
  }
}

///////////////////////////SYNTH_E_SIZER/SYNTH_E_SIZER/SYNTH_E_SIZER/SYNTH_E_SIZER/SYNTH_E_SIZER/SYNTH_E_SIZER/SYNTH_E_SIZER/SYNTH_E_SIZER/
void synth_e_sizer(void) 
{
  
  for(int i=0;i<104;i++) 
  {
    if(currentButtons[buttonMapping[i]]<lastButtons[buttonMapping[i]])
    {
      write_to_row(i);
    }
  }
  
  for(int i=0;i<3;i++)
  {
    if(currentButtons[i+63]<lastButtons[i+63]) 
    buttonSelection=i;
  }
  
  if(currentButtons[20]<lastButtons[20])
  buttonCount--;
  if(currentButtons[21]<lastButtons[21])
  buttonCount++;
  if(buttonCount>2)
  buttonCount=2;
  if(buttonCount<-2)
  buttonCount=-2;
  lastOn=totalOn;
  totalOn=0;
  resetandupdate_rowOn(&totalOn);
  
  float diff;
  diff = analogRead(A21) - tempo; 
  tempo = tempo + diff / 40;
  int finalTempo=tempo /10  + 80;


  /////////////////////////////////////////\/\/\/ SYNTH ROWS (0-7) MONOPHONIZER
  monophizer();
  /////////////////////////////////////////\/\/\/ SYNTH ROWS (0-7) MONOPHONIZER

          
  //START OF SEQ        
  if (sinceTempo >= (15000 / (finalTempo*8)))
  {
    if(stepCount/drumDivider%256==0)//////////////////////////////////////////////////////////////DIS SHIT
    {
      int randomSample;
      randomSample=random(5);
      if(randomSample==3)
      selectedSample[3]=random(3);
      else
      selectedSample[randomSample]=random(5);
    }

////////////////////////////////////////////////////////////////////////////////\/\/\/\/ DRUM OVERLOAD TURNER-OFF-ER-ER
    turn_off_rand(&totalOn, &offThreshold, stepCount);
////////////////////////////////////////////////////////////////////////////////\/\/\/\/ DRUM OVERLOAD TURNER-OFF-ER-ER
    
    if(totalOn>=offThreshold)
    {
      define_changeRow(lastOn, totalOn);
    }

    //"REAL" START OF SEQ
    if(stepCount%drumDivider==0)
    {//<
      int countMod = stepCount/drumDivider % 8;
      envelope_modulation(countMod, bankSel);
    }//>
    stepCount++;
++
    clockDuration=sinceTempo;
    sinceTempo = sinceTempo-clockDuration;
  } //END OF SEQ
  
}


void loop() {
  
  keySwitchStateRead();
  scaleSwitchStateRead();
  bankSwitchStateRead();
  wavSelSwitchStateRead();
  GPIOOnline=1;
  GPIOOnline=led_synth(stepCount, drumDivider, GPIOOnline, buttonMapping);
  GPIOOnline=led_drum(stepCount, drumDivider, GPIOOnline, buttonMapping);
  buttons_update();
  synth_e_sizer();
 // drum_machine();
  wav_sel();
  bank_sel(&bankSel);
  int scaleSel = scale_sel();
  int keySel = key_sel();
  scale[keySel][scaleSel]();
  dofilter();
}
