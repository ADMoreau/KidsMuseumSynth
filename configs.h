  //////////////////////////////////////////////////////////////////////////////////////////////////////DIS_SHIT
extern const void pca9685_config(uint8_t addr);

  //////////////////////////////////////////////////////////////////////////////////////////////////////DIS_SHIT
extern const void mcp23017_config(uint8_t addr, uint16_t dir);

extern const void waveforms_envelopes_init();

extern const void pca9685_config_init();

extern const void mcp23017_config_init();

extern const void keySwitchStateRead();

extern const void scaleSwitchStateRead();

extern const void bankSwitchStateRead();

extern const void wavSelSwitchStateRead();

extern const void wav_sel();

extern const int scale_sel();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////DRUMS
extern const void bank_sel(int* bankSel);

extern const int key_sel();
