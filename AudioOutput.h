#ifndef _AUDIOOUTPUT_H
#define _AUDIOOUTPUT_H

#include <stdint.h>

class AudioOutput {
  public:
    virtual ~AudioOutput() {}
    virtual bool begin() = 0;
    virtual bool consumeSample(int16_t sample) = 0;
    virtual bool stop() = 0;
};

#endif
