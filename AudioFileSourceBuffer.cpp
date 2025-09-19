#include "AudioFileSourceBuffer.h"
#include <Arduino.h>

AudioFileSourceBuffer::AudioFileSourceBuffer(AudioFileSource *source, int bufferSize)
  : source(source), bufferSize(bufferSize), bufferPos(0), bufferLen(0), filePos(0) {
  buffer = (uint8_t *)malloc(bufferSize);
}

AudioFileSourceBuffer::~AudioFileSourceBuffer() {
  free(buffer);
}

int AudioFileSourceBuffer::read(void *data, int len) {
  int bytesRead = 0;
  uint8_t *dst = (uint8_t *)data;

  while (len > 0) {
    if (bufferPos >= bufferLen) {
      bufferLen = source->read(buffer, bufferSize);
      bufferPos = 0;
      if (bufferLen <= 0) break;
    }

    int toCopy = min(len, bufferLen - bufferPos);
    memcpy(dst + bytesRead, buffer + bufferPos, toCopy);
    bufferPos += toCopy;
    bytesRead += toCopy;
    len -= toCopy;
    filePos += toCopy;
  }

  return bytesRead;
}

bool AudioFileSourceBuffer::seek(int32_t pos, int dir) {
  bufferPos = bufferLen = 0;
  filePos = pos;
  return source->seek(pos, dir);
}

int32_t AudioFileSourceBuffer::getSize() {
  return source->getSize();
}

int32_t AudioFileSourceBuffer::getPos() {
  return filePos;
}

bool AudioFileSourceBuffer::isOpen() {
  return source->isOpen();
}

void AudioFileSourceBuffer::close() {
  source->close();
}

bool AudioFileSourceBuffer::open(const char *filename) {
  return source->open(filename);
}
