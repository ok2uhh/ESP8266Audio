#ifndef _AUDIOOUTPUTI2S_H
#define _AUDIOOUTPUTI2S_H

#include "AudioOutput.h"

class AudioOutputI2S : public AudioOutput {
  public:
    AudioOutputI2S();
    virtual ~AudioOutputI2S();
    virtual bool begin();
    virtual bool consumeSample(int16_t sample);
    virtual bool stop();
};

#endif
