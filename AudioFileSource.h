#ifndef _AUDIOFILESOURCE_H
#define _AUDIOFILESOURCE_H

#include <stdint.h>

class AudioFileSource {
  public:
    virtual ~AudioFileSource() {}
    virtual bool open(const char *filename) { return false; }
    virtual void close() {}
    virtual int read(void *data, int len) { return 0; }
    virtual bool seek(int32_t pos, int dir) { return false; }
    virtual int32_t getSize() { return 0; }
    virtual int32_t getPos() { return 0; }
    virtual bool isOpen() { return false; }
};

#endif
