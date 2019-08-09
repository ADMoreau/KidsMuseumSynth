
extern const void waveform1_init(float amplitude, float pulseWidth);

extern const void waveform2_init(float amplitude, float pulseWidth);

extern const void waveform3_init(float amplitude, float pulseWidth);

extern const void waveform4_init(float amplitude, float pulseWidth);

extern const void waveform5_init(float amplitude, float pulseWidth);

extern const void waveform6_init(float amplitude, float pulseWidth);

extern const void waveform7_init(float amplitude, float pulseWidth);

extern const void waveform8_init(float amplitude, float pulseWidth);

extern const void waveform9_init(float amplitude, float pulseWidth);

extern const void waveform10_init(float amplitude, float pulseWidth);

extern const void waveform11_init(float amplitude, float pulseWidth);

extern const void waveform12_init(float amplitude, float pulseWidth);

extern const void waveform13_init(float amplitude, float pulseWidth);

extern const void waveform14_init(float amplitude, float pulseWidth);

extern const void waveform15_init(float amplitude, float pulseWidth);

extern const void waveform16_init(float amplitude, float pulseWidth);

extern const void envelope1_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope2_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope3_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope4_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope5_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope6_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope7_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope8_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope9_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope10_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope11_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope12_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope13_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope14_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope15_init(int attack, int hold, int decay, float sustain, int release);

extern const void envelope16_init(int attack, int hold, int decay, float sustain, int release);

extern const void (*scale[3][7])();

////////////////////////////////A
extern const void aMinor();

extern const void aMajor();

extern const void aMinorH();

////////////////////////////////B
extern const void bMinor();

extern const void bMajor();

extern const void bMinorH();

////////////////////////////////C
extern const void cMinor();

extern const void cMajor();

extern const void cMinorH();

////////////////////////////////D
extern const void dMinor();

extern const void dMajor();

extern const void dMinorH();

////////////////////////////////E
extern const void eMinor();

extern const void eMajor();

extern const void eMinorH();

////////////////////////////////F
extern const void fMinor();

extern const void fMajor();

extern const void fMinorH();

////////////////////////////////G
extern const void gMinor();

extern const void gMajor();

extern const void gMinorH();

extern const void envelope_modulation(int countMod, int bankSel);

extern const void mixer_init();

extern const void audio_init();

extern const void monophizer();

extern const void turn_off_rand(int* totalOn, int* offThreshold, int stepCount);

extern const void write_to_row(int i);

extern const void define_changeRow(int lastOn, int totalOn);

extern const void resetandupdate_rowOn(int* totalOn);

extern const int getbit(int x);

extern const void dofilter();

extern const void wav_sel();

extern const void wavSelSwitchStateRead();
