#ifndef _AUDIOOUTPUTPWM_H
#define _AUDIOOUTPUTPWM_H

#include "AudioOutput.h"

class AudioOutputPWM : public AudioOutput {
  public:
    AudioOutputPWM();
    virtual ~AudioOutputPWM();
    virtual bool begin();
    virtual bool consumeSample(int16_t sample);
    virtual bool stop();
};

#endif
