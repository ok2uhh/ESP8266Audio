#ifndef _AUDIOFILESOURCEHTTPSTREAM_H
#define _AUDIOFILESOURCEHTTPSTREAM_H

#include <ESP8266HTTPClient.h>
#include "AudioFileSource.h"

class AudioFileSourceHTTPStream : public AudioFileSource {
  public:
    AudioFileSourceHTTPStream(const char *url);
    virtual ~AudioFileSourceHTTPStream();
    virtual int read(void *data, int len);
    virtual bool seek(int32_t pos, int dir);
    virtual int32_t getSize();
    virtual int32_t getPos();
    virtual bool isOpen();
    virtual void close();
    virtual bool open(const char *filename);

  protected:
    WiFiClient client;
    HTTPClient http;
    String streamURL;
    int32_t position;
    bool opened;
};

#endif
