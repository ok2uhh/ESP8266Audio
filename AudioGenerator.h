#ifndef _AUDIOGENERATOR_H
#define _AUDIOGENERATOR_H

#include "AudioFileSource.h"
#include "AudioOutput.h"

class AudioGenerator {
  public:
    virtual ~AudioGenerator() {}
    virtual bool begin(AudioFileSource &input, AudioOutput &output) = 0;
    virtual bool loop() = 0;
    virtual bool stop() = 0;
    virtual bool isRunning() { return running; }

  protected:
    bool running = false;
};

#endif
