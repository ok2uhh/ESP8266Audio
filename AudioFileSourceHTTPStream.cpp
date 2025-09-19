#include "AudioFileSourceHTTPStream.h"

AudioFileSourceHTTPStream::AudioFileSourceHTTPStream(const char *url)
  : streamURL(url), position(0), opened(false) {}

AudioFileSourceHTTPStream::~AudioFileSourceHTTPStream() {
  close();
}

bool AudioFileSourceHTTPStream::open(const char *filename) {
  streamURL = String(filename);
  return true;
}

void AudioFileSourceHTTPStream::close() {
  http.end();
  opened = false;
}

bool AudioFileSourceHTTPStream::isOpen() {
  return opened;
}

int AudioFileSourceHTTPStream::read(void *data, int len) {
  if (!opened) {
    http.begin(client, streamURL);
    int httpCode = http.GET();
    if (httpCode != HTTP_CODE_OK) return 0;
    opened = true;
  }

  WiFiClient *stream = http.getStreamPtr();
  int available = stream->available();
  if (available == 0) return 0;

  int toRead = (available < len) ? available : len;
  int bytesRead = stream->readBytes((uint8_t *)data, toRead);
  position += bytesRead;
  return bytesRead;
}

bool AudioFileSourceHTTPStream::seek(int32_t pos, int dir) {
  // HTTP stream není seekovatelný
  return false;
}

int32_t AudioFileSourceHTTPStream::getSize() {
  return 0; // neznámá velikost
}

int32_t AudioFileSourceHTTPStream::getPos() {
  return position;
}
