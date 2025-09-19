#ifndef _AUDIOFILESOURCEICY_H
#define _AUDIOFILESOURCEICY_H

#include "AudioFileSourceBuffer.h"

class AudioFileSourceICY : public AudioFileSourceBuffer {
  public:
    AudioFileSourceICY(AudioFileSource *source, int bufferSize = 1024);
    virtual int read(void *data, int len);
    virtual bool seek(int pos);
    virtual int readMetadata(char *data, int len);
    virtual bool hasMetadata();
  protected:
    int icyInterval;
    int icyCount;
    bool icyFound;
    bool icyMeta;
};

#endif
