
#include "sounds.h"

#include "AudioSampleKick1.h"
#include "AudioSampleHat1.h"
#include "AudioSampleHat2.h"
#include "AudioSampleHat3.h"
#include "AudioSampleHat4.h"
#include "AudioSampleHat5.h"
#include "AudioSamplePerc1.h"
#include "AudioSamplePerc2.h"
#include "AudioSamplePerc3.h"
#include "AudioSamplePerc4.h"
#include "AudioSamplePerc5.h"
#include "AudioSampleSnare1.h"
#include "AudioSampleSnare2.h"
#include "AudioSampleSnare3.h"
#include "AudioSampleSnare4.h"
#include "AudioSampleSnare5.h"
#include "AudioSampleClap1.h"
#include "AudioSampleClap2.h"
#include "AudioSampleClap3.h"

const unsigned int *bank[5][5]={
{AudioSampleSnare1,AudioSampleClap1,AudioSampleHat1,AudioSamplePerc1,AudioSampleKick1},
{AudioSampleSnare2,AudioSampleClap2,AudioSampleHat2,AudioSamplePerc2,AudioSampleKick1},
{AudioSampleSnare3,AudioSampleClap3,AudioSampleHat3,AudioSamplePerc3,AudioSampleKick1},
{AudioSampleSnare4,AudioSampleClap1,AudioSampleHat4,AudioSamplePerc4,AudioSampleKick1},
{AudioSampleSnare5,AudioSampleClap2,AudioSampleHat5,AudioSamplePerc5,AudioSampleKick1}
};

