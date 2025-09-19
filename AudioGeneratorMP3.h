#ifndef _AUDIOGENERATORMP3_H
#define _AUDIOGENERATORMP3_H

#include "AudioFileSource.h"
#include "AudioOutput.h"
#include "AudioGenerator.h"

class AudioGeneratorMP3 : public AudioGenerator {
  public:
    AudioGeneratorMP3();
    virtual ~AudioGeneratorMP3();
    virtual bool begin(AudioFileSource &input, AudioOutput &output);
    virtual bool loop();
    virtual bool stop();

  protected:
    AudioOutput* output;  // ← přidáno pro správnou kompilaci
};

#endif
