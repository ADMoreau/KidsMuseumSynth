#include "scales.h"
#include <Audio.h>
#include "sounds.h"

AudioEffectEnvelope      envelope1;      //xy=343,164
AudioEffectEnvelope      envelope2;      //xy=347.88887786865234,202.1110954284668
AudioEffectEnvelope      envelope9; //xy=347,487
AudioEffectEnvelope      envelope3;      //xy=350,239
AudioEffectEnvelope      envelope7;      //xy=353,382
AudioEffectEnvelope      envelope4;      //xy=354,273
AudioEffectEnvelope      envelope10; //xy=353,524
AudioEffectEnvelope      envelope8;      //xy=354,418
AudioEffectEnvelope      envelope11; //xy=354,562
AudioEffectEnvelope      envelope5;      //xy=356,310
AudioEffectEnvelope      envelope6;      //xy=357,346
AudioEffectEnvelope      envelope15; //xy=357,705
AudioEffectEnvelope      envelope12; //xy=358,596
AudioEffectEnvelope      envelope16; //xy=358,741
AudioEffectEnvelope      envelope13; //xy=360,633
AudioEffectEnvelope      envelope14; //xy=361,669
AudioSynthWaveform       waveform2;      //xy=115,208
AudioSynthWaveform       waveform1;      //xy=116,175
AudioSynthWaveform       waveform5;      //xy=119,306
AudioSynthWaveform       waveform4;      //xy=121,274
AudioSynthWaveform       waveform6;      //xy=121,339
AudioSynthWaveform       waveform8;      //xy=122,404
AudioSynthWaveform       waveform3;      //xy=124,241
AudioSynthWaveform       waveform7;      //xy=124,372
AudioSynthWaveform       waveform10; //xy=131,527
AudioSynthWaveform       waveform11; //xy=131,561
AudioSynthWaveform       waveform9; //xy=132,494
AudioSynthWaveform       waveform12; //xy=132,594
AudioSynthWaveform       waveform13; //xy=135,627
AudioSynthWaveform       waveform14; //xy=135,660
AudioSynthWaveform       waveform16; //xy=136,728
AudioSynthWaveform       waveform15; //xy=138,692

AudioPlayMemory          sound0;       //xy=782.0832767486572,481.6666827201843
AudioPlayMemory          sound3;       //xy=783.3332767486572,599.1666851043701
AudioPlayMemory          sound1;       //xy=784.5832805633545,520.4166860580444
AudioPlayMemory          sound2;       //xy=787.0832786560059,559.1666841506958
AudioPlayMemory          sound4;       //xy=789.5832805633545,640.4166860580444
AudioFilterStateVariable filter1;        //xy=977.9999923706055,401.99999237060547


AudioMixer4              mixerSQ2;         //xy=578,289
AudioMixer4              mixerSQ1;         //xy=579,222
AudioMixer4              mixerSW2; //xy=594,608
AudioMixer4              mixerSW1; //xy=595,541
AudioMixer4              mixerWavSel;         //xy=788,397
AudioMixer4              mixerDrum1;         //xy=993.3332805633545,535.4166841506958
AudioMixer4              mixerDrum2;         //xy=993.3332843780518,602.9166841506958
AudioMixer4              mixerX;         //xy=1198.6667938232422,487.33333015441895
AudioOutputI2S           i2s1;           //xy=1377.9999771118164,490.6666069030762
AudioControlSGTL5000     sgtl5000_1;     //xy=138.66666412353516,859.3332939147949

AudioConnection          patchCord1(waveform2, envelope2);
AudioConnection          patchCord2(waveform1, envelope1);
AudioConnection          patchCord3(waveform5, envelope5);
AudioConnection          patchCord4(waveform4, envelope4);
AudioConnection          patchCord5(waveform6, envelope6);
AudioConnection          patchCord6(waveform8, envelope8);
AudioConnection          patchCord7(waveform3, envelope3);
AudioConnection          patchCord8(waveform7, envelope7);
AudioConnection          patchCord9(waveform10, envelope10);
AudioConnection          patchCord10(waveform11, envelope11);
AudioConnection          patchCord11(waveform9, envelope9);
AudioConnection          patchCord12(waveform12, envelope12);
AudioConnection          patchCord13(waveform13, envelope13);
AudioConnection          patchCord14(waveform14, envelope14);
AudioConnection          patchCord15(waveform16, envelope16);
AudioConnection          patchCord16(waveform15, envelope15);
AudioConnection          patchCord17(envelope1, 0, mixerSQ1, 0);
AudioConnection          patchCord18(envelope2, 0, mixerSQ1, 1);
AudioConnection          patchCord19(envelope9, 0, mixerSW1, 0);
AudioConnection          patchCord20(envelope3, 0, mixerSQ1, 2);
AudioConnection          patchCord21(envelope7, 0, mixerSQ2, 2);
AudioConnection          patchCord22(envelope4, 0, mixerSQ1, 3);
AudioConnection          patchCord23(envelope10, 0, mixerSW1, 1);
AudioConnection          patchCord24(envelope8, 0, mixerSQ2, 3);
AudioConnection          patchCord25(envelope11, 0, mixerSW1, 2);
AudioConnection          patchCord26(envelope5, 0, mixerSQ2, 0);
AudioConnection          patchCord27(envelope6, 0, mixerSQ2, 1);
AudioConnection          patchCord28(envelope15, 0, mixerSW2, 2);
AudioConnection          patchCord29(envelope12, 0, mixerSW1, 3);
AudioConnection          patchCord30(envelope16, 0, mixerSW2, 3);
AudioConnection          patchCord31(envelope13, 0, mixerSW2, 0);
AudioConnection          patchCord32(envelope14, 0, mixerSW2, 1);
AudioConnection          patchCord33(mixerSQ2, 0, mixerWavSel, 1);
AudioConnection          patchCord34(mixerSQ1, 0, mixerWavSel, 0);
AudioConnection          patchCord35(mixerSW2, 0, mixerWavSel, 3);
AudioConnection          patchCord36(mixerSW1, 0, mixerWavSel, 2);
AudioConnection          patchCord37(sound0, 0, mixerDrum1, 0);
AudioConnection          patchCord38(sound3, 0, mixerDrum1, 3);
AudioConnection          patchCord39(sound1, 0, mixerDrum1, 1);
AudioConnection          patchCord40(sound2, 0, mixerDrum1, 2);
AudioConnection          patchCord41(mixerWavSel, 0, filter1, 0);
AudioConnection          patchCord42(sound4, 0, mixerDrum2, 0);
AudioConnection          patchCord43(filter1, 0, mixerX, 0);
AudioConnection          patchCord44(filter1, 2, mixerX, 1);
AudioConnection          patchCord45(mixerDrum1, 0, mixerX, 2);
AudioConnection          patchCord46(mixerDrum2, 0, mixerX, 3);
AudioConnection          patchCord47(mixerX, 0, i2s1, 0);
AudioConnection          patchCord48(mixerX, 0, i2s1, 1);

elapsedMillis sinceThreshold;
elapsedMillis sinceTouch;

byte row[13]; //DAT NEW NEW
int rowOn[13]; //DAT NEW NEW
byte oldRow[8];

int wavSelSwitchState = 0;

int a1  = 55.0000;
int bb1 = 58.2705;
int b1  = 61.7354 ;  
int c1  = 32.7032;
int db1 = 34.6478;
int d1  = 36.7081;
int eb1 = 38.8909;
int e1  = 41.2034;
int f1  = 43.6535;
int gb1 = 46.2493;
int g1  = 48.9994 ;
int ab1 = 51.9131;
int a2  = 110.000;
int bb2 = 116.541 ;
int b2  = 123.471;
int c2  = 65.4064 ;  
int db2 = 69.2957;
int d2  = 73.4162;
int eb2 = 77.7817;
int e2  = 82.4069;
int f2  = 87.3071;
int gb2 = 92.4986;
int g2  = 97.9989;

int FREAKwencies[23] = { 
  a1,   //0
  bb1,  //1
  b1,   //2
  c1,   //3
  db1,  //4
  d1,   //5
  eb1,  //6
  e1,   //7
  f1,   //8
  gb1,  //09
  g1,   //10
  ab1,  //11
  a2,   //12
  bb2,  //13
  b2,   //14 
  c2,   //15
  db2,  //16 //
  d2,   //17
  eb2,  //18 //
  e2,   //19
  f2,   //20
  gb2,  //21 //
  g2    //22
  };

////////////////////////////////A
const void aMinor(){
  waveform1.frequency(FREAKwencies[0]);
  waveform2.frequency(FREAKwencies[2]);
  waveform3.frequency(FREAKwencies[3]);
  waveform4.frequency(FREAKwencies[5]);
  waveform5.frequency(FREAKwencies[7]);
  waveform6.frequency(FREAKwencies[8]);
  waveform7.frequency(FREAKwencies[10]);
  waveform8.frequency(FREAKwencies[12]);
  waveform9.frequency(FREAKwencies[0]);
  waveform10.frequency(FREAKwencies[2]);
  waveform11.frequency(FREAKwencies[3]);
  waveform12.frequency(FREAKwencies[5]);
  waveform13.frequency(FREAKwencies[7]);
  waveform14.frequency(FREAKwencies[8]);
  waveform15.frequency(FREAKwencies[10]);
  waveform16.frequency(FREAKwencies[12]);
}

const void aMajor(){
  waveform1.frequency(FREAKwencies[0]);
  waveform2.frequency(FREAKwencies[2]);
  waveform3.frequency(FREAKwencies[4]);
  waveform4.frequency(FREAKwencies[5]);
  waveform5.frequency(FREAKwencies[7]);
  waveform6.frequency(FREAKwencies[9]);
  waveform7.frequency(FREAKwencies[11]);
  waveform8.frequency(FREAKwencies[12]);
  waveform9.frequency(FREAKwencies[0]);
  waveform10.frequency(FREAKwencies[2]);
  waveform11.frequency(FREAKwencies[4]);
  waveform12.frequency(FREAKwencies[5]);
  waveform13.frequency(FREAKwencies[7]);
  waveform14.frequency(FREAKwencies[9]);
  waveform15.frequency(FREAKwencies[11]);
  waveform16.frequency(FREAKwencies[12]);
}


const void aMinorH(){
  waveform1.frequency(FREAKwencies[0]);
  waveform2.frequency(FREAKwencies[2]);
  waveform3.frequency(FREAKwencies[3]);
  waveform4.frequency(FREAKwencies[5]);
  waveform5.frequency(FREAKwencies[7]);
  waveform6.frequency(FREAKwencies[8]);
  waveform7.frequency(FREAKwencies[11]);
  waveform8.frequency(FREAKwencies[12]);
  waveform9.frequency(FREAKwencies[0]);
  waveform10.frequency(FREAKwencies[2]);
  waveform11.frequency(FREAKwencies[3]);
  waveform12.frequency(FREAKwencies[5]);
  waveform13.frequency(FREAKwencies[7]);
  waveform14.frequency(FREAKwencies[8]);
  waveform15.frequency(FREAKwencies[11]);
  waveform16.frequency(FREAKwencies[12]);
}

////////////////////////////////B
const void bMinor(){
  waveform1.frequency(FREAKwencies[2]);
  waveform2.frequency(FREAKwencies[4]);
  waveform3.frequency(FREAKwencies[5]);
  waveform4.frequency(FREAKwencies[7]);
  waveform5.frequency(FREAKwencies[9]);
  waveform6.frequency(FREAKwencies[10]);
  waveform7.frequency(FREAKwencies[12]);
  waveform8.frequency(FREAKwencies[14]);
  waveform9.frequency(FREAKwencies[2]);
  waveform10.frequency(FREAKwencies[4]);
  waveform11.frequency(FREAKwencies[5]);
  waveform12.frequency(FREAKwencies[7]);
  waveform13.frequency(FREAKwencies[9]);
  waveform14.frequency(FREAKwencies[10]);
  waveform15.frequency(FREAKwencies[12]);
  waveform16.frequency(FREAKwencies[14]);
}

const void bMajor(){
  waveform1.frequency(FREAKwencies[2]);
  waveform2.frequency(FREAKwencies[4]);
  waveform3.frequency(FREAKwencies[6]);
  waveform4.frequency(FREAKwencies[7]);
  waveform5.frequency(FREAKwencies[9]);
  waveform6.frequency(FREAKwencies[11]);
  waveform7.frequency(FREAKwencies[13]);
  waveform8.frequency(FREAKwencies[14]);
  waveform9.frequency(FREAKwencies[2]);
  waveform10.frequency(FREAKwencies[4]);
  waveform11.frequency(FREAKwencies[6]);
  waveform12.frequency(FREAKwencies[7]);
  waveform13.frequency(FREAKwencies[9]);
  waveform14.frequency(FREAKwencies[11]);
  waveform15.frequency(FREAKwencies[13]);
  waveform16.frequency(FREAKwencies[14]);
}

const void bMinorH(){
  waveform1.frequency(FREAKwencies[2]);
  waveform2.frequency(FREAKwencies[4]);
  waveform3.frequency(FREAKwencies[5]);
  waveform4.frequency(FREAKwencies[7]);
  waveform5.frequency(FREAKwencies[9]);
  waveform6.frequency(FREAKwencies[10]);
  waveform7.frequency(FREAKwencies[13]);
  waveform8.frequency(FREAKwencies[14]);
  waveform9.frequency(FREAKwencies[2]);
  waveform10.frequency(FREAKwencies[4]);
  waveform11.frequency(FREAKwencies[5]);
  waveform12.frequency(FREAKwencies[7]);
  waveform13.frequency(FREAKwencies[9]);
  waveform14.frequency(FREAKwencies[10]);
  waveform15.frequency(FREAKwencies[13]);
  waveform16.frequency(FREAKwencies[14]);
}

////////////////////////////////C
const void cMinor(){
  waveform1.frequency(FREAKwencies[3]);
  waveform2.frequency(FREAKwencies[5]);
  waveform3.frequency(FREAKwencies[6]);
  waveform4.frequency(FREAKwencies[8]);
  waveform5.frequency(FREAKwencies[10]);
  waveform6.frequency(FREAKwencies[11]);
  waveform7.frequency(FREAKwencies[13]);
  waveform8.frequency(FREAKwencies[15]);
  waveform9.frequency(FREAKwencies[3]);
  waveform10.frequency(FREAKwencies[5]);
  waveform11.frequency(FREAKwencies[6]);
  waveform12.frequency(FREAKwencies[8]);
  waveform13.frequency(FREAKwencies[10]);
  waveform14.frequency(FREAKwencies[11]);
  waveform15.frequency(FREAKwencies[13]);
  waveform16.frequency(FREAKwencies[15]);
}

const void cMajor(){
  waveform1.frequency(FREAKwencies[3]);
  waveform2.frequency(FREAKwencies[5]);
  waveform3.frequency(FREAKwencies[7]);
  waveform4.frequency(FREAKwencies[8]);
  waveform5.frequency(FREAKwencies[10]);
  waveform6.frequency(FREAKwencies[12]);
  waveform7.frequency(FREAKwencies[14]);
  waveform8.frequency(FREAKwencies[15]);
  waveform9.frequency(FREAKwencies[3]);
  waveform10.frequency(FREAKwencies[5]);
  waveform11.frequency(FREAKwencies[7]);
  waveform12.frequency(FREAKwencies[8]);
  waveform13.frequency(FREAKwencies[10]);
  waveform14.frequency(FREAKwencies[12]);
  waveform15.frequency(FREAKwencies[14]);
  waveform16.frequency(FREAKwencies[15]);
}

const void cMinorH(){
  waveform1.frequency(FREAKwencies[3]);
  waveform2.frequency(FREAKwencies[5]);
  waveform3.frequency(FREAKwencies[6]);
  waveform4.frequency(FREAKwencies[8]);
  waveform5.frequency(FREAKwencies[10]);
  waveform6.frequency(FREAKwencies[11]);
  waveform7.frequency(FREAKwencies[14]);
  waveform8.frequency(FREAKwencies[15]);
  waveform9.frequency(FREAKwencies[3]);
  waveform10.frequency(FREAKwencies[5]);
  waveform11.frequency(FREAKwencies[6]);
  waveform12.frequency(FREAKwencies[8]);
  waveform13.frequency(FREAKwencies[10]);
  waveform14.frequency(FREAKwencies[11]);
  waveform15.frequency(FREAKwencies[14]);
  waveform16.frequency(FREAKwencies[15]);
}

////////////////////////////////D
const void dMinor(){
  waveform1.frequency(FREAKwencies[5]);
  waveform2.frequency(FREAKwencies[7]);
  waveform3.frequency(FREAKwencies[8]);
  waveform4.frequency(FREAKwencies[10]);
  waveform5.frequency(FREAKwencies[12]);
  waveform6.frequency(FREAKwencies[13]);
  waveform7.frequency(FREAKwencies[15]);
  waveform8.frequency(FREAKwencies[17]);
  waveform9.frequency(FREAKwencies[5]);
  waveform10.frequency(FREAKwencies[7]);
  waveform11.frequency(FREAKwencies[8]);
  waveform12.frequency(FREAKwencies[10]);
  waveform13.frequency(FREAKwencies[12]);
  waveform14.frequency(FREAKwencies[13]);
  waveform15.frequency(FREAKwencies[15]);
  waveform16.frequency(FREAKwencies[17]);
}

const void dMajor(){
  waveform1.frequency(FREAKwencies[5]);
  waveform2.frequency(FREAKwencies[7]);
  waveform3.frequency(FREAKwencies[9]);
  waveform4.frequency(FREAKwencies[10]);
  waveform5.frequency(FREAKwencies[12]);
  waveform6.frequency(FREAKwencies[14]);
  waveform7.frequency(FREAKwencies[16]);
  waveform8.frequency(FREAKwencies[17]);
  waveform9.frequency(FREAKwencies[5]);
  waveform10.frequency(FREAKwencies[7]);
  waveform11.frequency(FREAKwencies[9]);
  waveform12.frequency(FREAKwencies[10]);
  waveform13.frequency(FREAKwencies[12]);
  waveform14.frequency(FREAKwencies[14]);
  waveform15.frequency(FREAKwencies[16]);
  waveform16.frequency(FREAKwencies[17]);
}

const void dMinorH(){
  waveform1.frequency(FREAKwencies[5]);
  waveform2.frequency(FREAKwencies[7]);
  waveform3.frequency(FREAKwencies[8]);
  waveform4.frequency(FREAKwencies[10]);
  waveform5.frequency(FREAKwencies[12]);
  waveform6.frequency(FREAKwencies[13]);
  waveform7.frequency(FREAKwencies[16]);
  waveform8.frequency(FREAKwencies[17]);
  waveform9.frequency(FREAKwencies[5]);
  waveform10.frequency(FREAKwencies[7]);
  waveform11.frequency(FREAKwencies[8]);
  waveform12.frequency(FREAKwencies[10]);
  waveform13.frequency(FREAKwencies[12]);
  waveform14.frequency(FREAKwencies[13]);
  waveform15.frequency(FREAKwencies[16]);
  waveform16.frequency(FREAKwencies[17]);
}

////////////////////////////////E
const void eMinor(){
  waveform1.frequency(FREAKwencies[7]);
  waveform2.frequency(FREAKwencies[9]);
  waveform3.frequency(FREAKwencies[10]);
  waveform4.frequency(FREAKwencies[12]);
  waveform5.frequency(FREAKwencies[14]);
  waveform6.frequency(FREAKwencies[15]);
  waveform7.frequency(FREAKwencies[17]);
  waveform8.frequency(FREAKwencies[19]);
  waveform9.frequency(FREAKwencies[7]);
  waveform10.frequency(FREAKwencies[9]);
  waveform11.frequency(FREAKwencies[10]);
  waveform12.frequency(FREAKwencies[12]);
  waveform13.frequency(FREAKwencies[14]);
  waveform14.frequency(FREAKwencies[15]);
  waveform15.frequency(FREAKwencies[17]);
  waveform16.frequency(FREAKwencies[19]);
}

const void eMajor(){
  waveform1.frequency(FREAKwencies[7]);
  waveform2.frequency(FREAKwencies[9]);
  waveform3.frequency(FREAKwencies[11]);
  waveform4.frequency(FREAKwencies[12]);
  waveform5.frequency(FREAKwencies[14]);
  waveform6.frequency(FREAKwencies[16]);
  waveform7.frequency(FREAKwencies[18]);
  waveform8.frequency(FREAKwencies[19]);
  waveform9.frequency(FREAKwencies[7]);
  waveform10.frequency(FREAKwencies[9]);
  waveform11.frequency(FREAKwencies[11]);
  waveform12.frequency(FREAKwencies[12]);
  waveform13.frequency(FREAKwencies[14]);
  waveform14.frequency(FREAKwencies[16]);
  waveform15.frequency(FREAKwencies[18]);
  waveform16.frequency(FREAKwencies[19]);
}

const void eMinorH(){
  waveform1.frequency(FREAKwencies[7]);
  waveform2.frequency(FREAKwencies[9]);
  waveform3.frequency(FREAKwencies[10]);
  waveform4.frequency(FREAKwencies[12]);
  waveform5.frequency(FREAKwencies[14]);
  waveform6.frequency(FREAKwencies[15]);
  waveform7.frequency(FREAKwencies[18]);
  waveform8.frequency(FREAKwencies[19]);
  waveform9.frequency(FREAKwencies[7]);
  waveform10.frequency(FREAKwencies[9]);
  waveform11.frequency(FREAKwencies[10]);
  waveform12.frequency(FREAKwencies[12]);
  waveform13.frequency(FREAKwencies[14]);
  waveform14.frequency(FREAKwencies[15]);
  waveform15.frequency(FREAKwencies[18]);
  waveform16.frequency(FREAKwencies[19]);
}

////////////////////////////////F
const void fMinor(){
  waveform1.frequency(FREAKwencies[8]);
  waveform2.frequency(FREAKwencies[10]);
  waveform3.frequency(FREAKwencies[11]);
  waveform4.frequency(FREAKwencies[13]);
  waveform5.frequency(FREAKwencies[15]);
  waveform6.frequency(FREAKwencies[16]);
  waveform7.frequency(FREAKwencies[18]);
  waveform8.frequency(FREAKwencies[20]);
  waveform9.frequency(FREAKwencies[8]);
  waveform10.frequency(FREAKwencies[10]);
  waveform11.frequency(FREAKwencies[11]);
  waveform12.frequency(FREAKwencies[13]);
  waveform13.frequency(FREAKwencies[15]);
  waveform14.frequency(FREAKwencies[16]);
  waveform15.frequency(FREAKwencies[18]);
  waveform16.frequency(FREAKwencies[20]);
}
const void fMajor(){
  waveform1.frequency(FREAKwencies[8]);
  waveform2.frequency(FREAKwencies[10]);
  waveform3.frequency(FREAKwencies[12]);
  waveform4.frequency(FREAKwencies[13]);
  waveform5.frequency(FREAKwencies[15]);
  waveform6.frequency(FREAKwencies[17]);
  waveform7.frequency(FREAKwencies[19]);
  waveform8.frequency(FREAKwencies[20]);
  waveform9.frequency(FREAKwencies[8]);
  waveform10.frequency(FREAKwencies[10]);
  waveform11.frequency(FREAKwencies[12]);
  waveform12.frequency(FREAKwencies[13]);
  waveform13.frequency(FREAKwencies[15]);
  waveform14.frequency(FREAKwencies[17]);
  waveform15.frequency(FREAKwencies[19]);
  waveform16.frequency(FREAKwencies[20]);
}

const void fMinorH(){
  waveform1.frequency(FREAKwencies[8]);
  waveform2.frequency(FREAKwencies[10]);
  waveform3.frequency(FREAKwencies[11]); //
  waveform4.frequency(FREAKwencies[13]);
  waveform5.frequency(FREAKwencies[15]);
  waveform6.frequency(FREAKwencies[16]);
  waveform7.frequency(FREAKwencies[19]);
  waveform8.frequency(FREAKwencies[20]);
  waveform9.frequency(FREAKwencies[8]);
  waveform10.frequency(FREAKwencies[10]);
  waveform11.frequency(FREAKwencies[11]); //
  waveform12.frequency(FREAKwencies[13]);
  waveform13.frequency(FREAKwencies[15]);
  waveform14.frequency(FREAKwencies[16]);
  waveform15.frequency(FREAKwencies[19]);
  waveform16.frequency(FREAKwencies[20]);
  
}

////////////////////////////////G
const void gMinor(){
  waveform1.frequency(FREAKwencies[10]);
  waveform2.frequency(FREAKwencies[12]);
  waveform3.frequency(FREAKwencies[13]);
  waveform4.frequency(FREAKwencies[15]);
  waveform5.frequency(FREAKwencies[17]);
  waveform6.frequency(FREAKwencies[18]);
  waveform7.frequency(FREAKwencies[20]);
  waveform8.frequency(FREAKwencies[22]);
  waveform9.frequency(FREAKwencies[10]);
  waveform10.frequency(FREAKwencies[12]);
  waveform11.frequency(FREAKwencies[13]);
  waveform12.frequency(FREAKwencies[15]);
  waveform13.frequency(FREAKwencies[17]);
  waveform14.frequency(FREAKwencies[18]);
  waveform15.frequency(FREAKwencies[20]);
  waveform16.frequency(FREAKwencies[22]);
}

const void gMajor(){
  waveform1.frequency(FREAKwencies[10]);
  waveform2.frequency(FREAKwencies[12]);
  waveform3.frequency(FREAKwencies[14]);
  waveform4.frequency(FREAKwencies[15]);
  waveform5.frequency(FREAKwencies[17]);
  waveform6.frequency(FREAKwencies[19]);
  waveform7.frequency(FREAKwencies[21]);
  waveform8.frequency(FREAKwencies[22]);
  waveform9.frequency(FREAKwencies[10]);
  waveform10.frequency(FREAKwencies[12]);
  waveform11.frequency(FREAKwencies[14]);
  waveform12.frequency(FREAKwencies[15]);
  waveform13.frequency(FREAKwencies[17]);
  waveform14.frequency(FREAKwencies[19]);
  waveform15.frequency(FREAKwencies[21]);
  waveform16.frequency(FREAKwencies[22]);
}

const void gMinorH(){
  waveform1.frequency(FREAKwencies[10]);
  waveform2.frequency(FREAKwencies[12]);
  waveform3.frequency(FREAKwencies[13]);
  waveform4.frequency(FREAKwencies[15]);
  waveform5.frequency(FREAKwencies[17]);
  waveform6.frequency(FREAKwencies[18]);
  waveform7.frequency(FREAKwencies[21]);
  waveform8.frequency(FREAKwencies[22]);
  waveform9.frequency(FREAKwencies[10]);
  waveform10.frequency(FREAKwencies[12]);
  waveform11.frequency(FREAKwencies[13]);
  waveform12.frequency(FREAKwencies[15]);
  waveform13.frequency(FREAKwencies[17]);
  waveform14.frequency(FREAKwencies[18]);
  waveform15.frequency(FREAKwencies[21]);
  waveform16.frequency(FREAKwencies[22]);
}

const void (*scale[3][7])()
{
  {aMinor, bMinor, cMinor, dMinor, eMinor, fMinor, gMinor},
  {aMajor, bMajor, cMajor, dMajor, eMajor, fMajor, gMajor},
  {aMinorH, bMinorH, cMinorH, dMinorH, eMinorH, fMinorH, gMinorH}
};

const void waveform1_init(float amplitude, float pulseWidth)
{
  waveform1.begin(WAVEFORM_SQUARE);
  waveform1.amplitude(amplitude);
  waveform1.pulseWidth(pulseWidth);
}

const void waveform2_init(float amplitude, float pulseWidth)
{
  waveform2.begin(WAVEFORM_SQUARE);
  waveform2.amplitude(amplitude);
  waveform2.pulseWidth(pulseWidth);
}

const void waveform3_init(float amplitude, float pulseWidth)
{
  waveform3.begin(WAVEFORM_SQUARE);
  waveform3.amplitude(amplitude);
  waveform3.pulseWidth(pulseWidth);
}

const void waveform4_init(float amplitude, float pulseWidth)
{
  waveform4.begin(WAVEFORM_SQUARE);
  waveform4.amplitude(amplitude);
  waveform4.pulseWidth(pulseWidth);
}

const void waveform5_init(float amplitude, float pulseWidth)
{
  waveform5.begin(WAVEFORM_SQUARE);
  waveform5.amplitude(amplitude);
  waveform5.pulseWidth(pulseWidth);
}

const void waveform6_init(float amplitude, float pulseWidth)
{
  waveform6.begin(WAVEFORM_SQUARE);
  waveform6.amplitude(amplitude);
  waveform6.pulseWidth(pulseWidth);
}

const void waveform7_init(float amplitude, float pulseWidth)
{
  waveform7.begin(WAVEFORM_SQUARE);
  waveform7.amplitude(amplitude);
  waveform7.pulseWidth(pulseWidth);
}

const void waveform8_init(float amplitude, float pulseWidth)
{
  waveform8.begin(WAVEFORM_SQUARE);
  waveform8.amplitude(amplitude);
  waveform8.pulseWidth(pulseWidth);
}

const void waveform9_init(float amplitude, float pulseWidth)
{
  waveform9.begin(WAVEFORM_SAWTOOTH);
  waveform9.amplitude(amplitude);
  waveform9.pulseWidth(pulseWidth);
}

const void waveform10_init(float amplitude, float pulseWidth)
{
  waveform10.begin(WAVEFORM_SAWTOOTH);
  waveform10.amplitude(amplitude);
  waveform10.pulseWidth(pulseWidth);
}

const void waveform11_init(float amplitude, float pulseWidth)
{
  waveform11.begin(WAVEFORM_SAWTOOTH);
  waveform11.amplitude(amplitude);
  waveform11.pulseWidth(pulseWidth);
}

const void waveform12_init(float amplitude, float pulseWidth)
{
  waveform12.begin(WAVEFORM_SAWTOOTH);
  waveform12.amplitude(amplitude);
  waveform12.pulseWidth(pulseWidth);
}

const void waveform13_init(float amplitude, float pulseWidth)
{
  waveform13.begin(WAVEFORM_SAWTOOTH);
  waveform13.amplitude(amplitude);
  waveform13.pulseWidth(pulseWidth);
}

const void waveform14_init(float amplitude, float pulseWidth)
{
  waveform14.begin(WAVEFORM_SAWTOOTH);
  waveform14.amplitude(amplitude);
  waveform14.pulseWidth(pulseWidth);
}

const void waveform15_init(float amplitude, float pulseWidth)
{
  waveform15.begin(WAVEFORM_SAWTOOTH);
  waveform15.amplitude(amplitude);
  waveform15.pulseWidth(pulseWidth);
}

const void waveform16_init(float amplitude, float pulseWidth)
{
  waveform16.begin(WAVEFORM_SAWTOOTH);
  waveform16.amplitude(amplitude);
  waveform16.pulseWidth(pulseWidth);
}

const void envelope1_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope1.attack(attack);
  envelope1.hold(hold);
  envelope1.decay(decay);
  envelope1.sustain(sustain);
  envelope1.release(release);
}

const void envelope2_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope2.attack(attack);
  envelope2.hold(hold);
  envelope2.decay(decay);
  envelope2.sustain(sustain);
  envelope2.release(release);
}

const void envelope3_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope3.attack(attack);
  envelope3.hold(hold);
  envelope3.decay(decay);
  envelope3.sustain(sustain);
  envelope3.release(release);
}

const void envelope4_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope4.attack(attack);
  envelope4.hold(hold);
  envelope4.decay(decay);
  envelope4.sustain(sustain);
  envelope4.release(release);
}

const void envelope5_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope5.attack(attack);
  envelope5.hold(hold);
  envelope5.decay(decay);
  envelope5.sustain(sustain);
  envelope5.release(release);
}

const void envelope6_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope6.attack(attack);
  envelope6.hold(hold);
  envelope6.decay(decay);
  envelope6.sustain(sustain);
  envelope6.release(release);
}

const void envelope7_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope7.attack(attack);
  envelope7.hold(hold);
  envelope7.decay(decay);
  envelope7.sustain(sustain);
  envelope7.release(release);
}

const void envelope8_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope8.attack(attack);
  envelope8.hold(hold);
  envelope8.decay(decay);
  envelope8.sustain(sustain);
  envelope8.release(release);
}

const void envelope9_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope9.attack(attack);
  envelope9.hold(hold);
  envelope9.decay(decay);
  envelope9.sustain(sustain);
  envelope9.release(release);
}

const void envelope10_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope10.attack(attack);
  envelope10.hold(hold);
  envelope10.decay(decay);
  envelope10.sustain(sustain);
  envelope10.release(release);
}

const void envelope11_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope11.attack(attack);
  envelope11.hold(hold);
  envelope11.decay(decay);
  envelope11.sustain(sustain);
  envelope11.release(release);
}

const void envelope12_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope12.attack(attack);
  envelope12.hold(hold);
  envelope12.decay(decay);
  envelope12.sustain(sustain);
  envelope12.release(release);
}

const void envelope13_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope13.attack(attack);
  envelope13.hold(hold);
  envelope13.decay(decay);
  envelope13.sustain(sustain);
  envelope13.release(release);
}

const void envelope14_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope14.attack(attack);
  envelope14.hold(hold);
  envelope14.decay(decay);
  envelope14.sustain(sustain);
  envelope14.release(release);
}

const void envelope15_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope15.attack(attack);
  envelope15.hold(hold);
  envelope15.decay(decay);
  envelope15.sustain(sustain);
  envelope15.release(release);
}

const void envelope16_init(int attack, int hold, int decay, float sustain, int release)
{
  envelope16.attack(attack);
  envelope16.hold(hold);
  envelope16.decay(decay);
  envelope16.sustain(sustain);
  envelope16.release(release);
}

const void envelope_modulation(int countMod, int bankSel)
{
      if (bitRead(row[0], countMod))
      {
        envelope1.noteOn();
        envelope9.noteOn();
      } else {
        envelope1.noteOff();
        envelope9.noteOff();
      }
      if (bitRead(row[1], countMod))
      {
        envelope2.noteOn();
        envelope10.noteOn();
      } else {
        envelope2.noteOff();
        envelope10.noteOff();
      }
      if (bitRead(row[2], countMod))
      {
        envelope3.noteOn();
        envelope11.noteOn();
      } else {
        envelope3.noteOff();
        envelope11.noteOff();
      }
      if (bitRead(row[3], countMod))
      {
        envelope4.noteOn();
        envelope12.noteOn();
      } else {
        envelope4.noteOff();
        envelope12.noteOff();
      }
      if (bitRead(row[4], countMod))
      {
        envelope5.noteOn();
        envelope13.noteOn();
      } else {
        envelope5.noteOff();
        envelope13.noteOff();
      }
      if (bitRead(row[5], countMod))
      {
        envelope6.noteOn();
        envelope14.noteOn();
      } else {
        envelope6.noteOff();
        envelope14.noteOff();
      }
      if (bitRead(row[6], countMod))
      {
        envelope7.noteOn();
        envelope15.noteOn();
      } else {
        envelope7.noteOff();
        envelope15.noteOff();
      }
      if (bitRead(row[7], countMod))
      {
        envelope8.noteOn();
        envelope16.noteOn();
      } else {
        envelope8.noteOff();
        envelope16.noteOff();
      }
//////DRUMS
      if (bitRead(row[8], countMod))
      {
        sound4.play(bank[bankSel][0]);
        Serial1.write('4');
      }
      if (bitRead(row[9], countMod))
      {
        sound2.play(bank[bankSel][1]);
        Serial1.write('2');
      }
      if (bitRead(row[10], countMod))
      {
        sound1.play(bank[bankSel][2]);
        Serial1.write('1');
      }
      if (bitRead(row[11], countMod))
      {
        sound3.play(bank[bankSel][3]);
        Serial1.write('3');
      }
      if (bitRead(row[12], countMod))
      {
        sound0.play(bank[bankSel][4]);
        Serial1.write('0');
      }
}

const void mixer_init()
{
  mixerSQ1.gain(0, 0.4);
  mixerSQ1.gain(1, 0.4);
  mixerSQ1.gain(2, 0.4);
  mixerSQ1.gain(3, 0.4);
  mixerSQ2.gain(0, 0.4);
  mixerSQ2.gain(1, 0.4);
  mixerSQ2.gain(2, 0.4);
  mixerSQ2.gain(3, 0.4);
  mixerSW1.gain(0, 0.4);
  mixerSW1.gain(1, 0.4);
  mixerSW1.gain(2, 0.4);
  mixerSW1.gain(3, 0.4);
  mixerSW2.gain(0, 0.4);
  mixerSW2.gain(1, 0.4);
  mixerSW2.gain(2, 0.4);
  mixerSW2.gain(3, 0.4);
  mixerWavSel.gain(0, 0.0);////////////////////////////////////////square
  mixerWavSel.gain(1, 0.0);///////////////////////////////////////square
  mixerWavSel.gain(2, 0.0);////////////////////////////////////////saw
  mixerWavSel.gain(3, 0.0);///////////////////////////////////////saw
  
  mixerDrum1.gain(0, 0.4); 
  mixerDrum1.gain(1, 0.4); 
  mixerDrum1.gain(2, 0.4); 
  mixerDrum1.gain(3, 0.4);
  mixerDrum2.gain(0, 0.4);

  mixerX.gain(0, 0.9); //Low Pass Filter
  mixerX.gain(1, 0.0); //High Pass
  mixerX.gain(2, 0.7); //Drum Machine
  mixerX.gain(3, 0.7); //Drum Machine
}

const void audio_init()
{
  // Global audio stuff
  AudioMemory(50);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.6);
}

const void monophizer()
{
  for (int r=0; r<8; r++)
      {
        for (int c=0; c<8; c++)
        {
          int m = 0;
          for (int x=0; x<8; x++) {
            if (bitRead(row[x], c)) {
              m = x;
            }
          }
          //if (m > 0) {
            for (int y=0;y<m;y++) {
              if (bitRead(row[y], c) > bitRead(oldRow[y], c)) {
                m++;
              }
              else {
                bitClear(row[y],c);
              }
            }
          //}
        }
      }
          for (int i=0; i<8; i++) {
            oldRow[i] = row[i];
          }
}

const void turn_off_rand(int* totalOn, int* offThreshold, int stepCount)
{
  if(sinceTouch>30000&&totalOn<offThreshold&&stepCount%64==0)
    {
    for (int r=8; r<13; r++)  
      {
        for (int c=0; c<8; c++)
        {
          if(totalOn==offThreshold)
          bitClear(row[r],c);
        }
      }
      if(totalOn<offThreshold)
      {
        for(int w=0; w<offThreshold; w++)
        {
          int mapStep;
          int mapRow;
          mapStep=random(8);
          mapRow=random(13);
          //  bitWrite(row[mapRow],mapStep,bitRead(drumTable[mapRow],mapStep));
        }
      }
  }
}

const void write_to_row(int i)
{
  bitWrite(row[i/8],i%8,!bitRead(row[i/8],i%8));
  sinceTouch=0;
}

const void define_changeRow(int lastOn, int totalOn)
{
      if(lastOn!=totalOn)
      sinceThreshold=0;
      if(sinceThreshold>400)
      {
        int changeRow=0;
        int selectedRow;
        int randomStep;
        changeRow=max(rowOn[0],rowOn[1]);
        changeRow=max(changeRow,rowOn[2]);
        changeRow=max(changeRow,rowOn[3]);
        changeRow=max(changeRow,rowOn[4]);
        changeRow=max(changeRow,rowOn[5]);
        changeRow=max(changeRow,rowOn[6]);
        changeRow=max(changeRow,rowOn[7]);
        changeRow=max(changeRow,rowOn[8]);
        changeRow=max(changeRow,rowOn[9]);
        changeRow=max(changeRow,rowOn[10]);
        changeRow=max(changeRow,rowOn[11]);
        changeRow=max(changeRow,rowOn[12]);
        for(int s=0; s<13; s++)
        {
          if(changeRow==rowOn[s])
          selectedRow=s;
        }
        randomStep=random(8);
        if(sinceTouch>4000)
        bitClear(row[selectedRow],randomStep);
        sinceThreshold=0;
      }
}

const void resetandupdate_rowOn(int* totalOn)
{
  for(int i=0; i<13; i++)
  rowOn[i]=0;
 
  for(int r=0; r<13; r++)
  {
    for(int c=0; c<8; c++)
    {
      if(bitRead(row[r],c))
      {
        rowOn[r]++;
        *totalOn++;
      }
    }
  }
}

const int getbit(int x)
{
  return bitRead(row[x / 8], x % 8);
}

const void dofilter()
{
  ////////////////////FILTER
  int knob = analogRead(A1);
  float freq =  expf((float)knob / 150.0) * 10.0 + 80.0;
  filter1.frequency(freq);
}


const void wav_sel()
{
  if(wavSelSwitchState == LOW){
  mixerWavSel.gain(0, 0.0);////////////////////////////////////////square
  mixerWavSel.gain(1, 0.0);///////////////////////////////////////square
  mixerWavSel.gain(2, 0.6);////////////////////////////////////////saw
  mixerWavSel.gain(3, 0.6);///////////////////////////////////////saw
  }
  else {
  mixerWavSel.gain(0, 0.6);////////////////////////////////////////square
  mixerWavSel.gain(1, 0.6);///////////////////////////////////////square
  mixerWavSel.gain(2, 0.0);////////////////////////////////////////saw
  mixerWavSel.gain(3, 0.0);///////////////////////////////////////saw
  }
}

const void wavSelSwitchStateRead()
{
    wavSelSwitchState = digitalRead(0);/////////////////////////////////TRY SSWITCHING THIS TO PIN 2 TO AVOID TX/RX
}

