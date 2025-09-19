#ifndef _AUDIOFILESOURCEBUFFER_H
#define _AUDIOFILESOURCEBUFFER_H

#include "AudioFileSource.h"

class AudioFileSourceBuffer : public AudioFileSource {
  public:
    AudioFileSourceBuffer(AudioFileSource *source, int bufferSize = 1024);
    virtual ~AudioFileSourceBuffer();
    virtual int read(void *data, int len);
    virtual bool seek(int32_t pos, int dir);
    virtual int32_t getSize();
    virtual int32_t getPos();
    virtual bool isOpen();
    virtual void close();
    virtual bool open(const char *filename);
  protected:
    AudioFileSource *source;
    uint8_t *buffer;
    int bufferSize;
    int bufferPos;
    int bufferLen;
    int32_t filePos;
};

#endif
