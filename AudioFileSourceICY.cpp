#include "AudioFileSourceICY.h"

AudioFileSourceICY::AudioFileSourceICY(AudioFileSource *source, int bufferSize)
  : AudioFileSourceBuffer(source, bufferSize), icyInterval(0), icyCount(0), icyFound(false), icyMeta(false) {}

int AudioFileSourceICY::read(void *data, int len) {
  int bytesRead = AudioFileSourceBuffer::read(data, len);
  if (icyFound && icyInterval > 0) {
    icyCount += bytesRead;
    if (icyCount >= icyInterval) {
      icyMeta = true;
      icyCount = 0;
    }
  }
  return bytesRead;
}

bool AudioFileSourceICY::seek(int pos) {
  icyCount = 0;
  icyMeta = false;
  return AudioFileSourceBuffer::seek(pos);
}

int AudioFileSourceICY::readMetadata(char *data, int len) {
  if (!icyMeta) return 0;
  icyMeta = false;
  return AudioFileSourceBuffer::read(data, len);
}

bool AudioFileSourceICY::hasMetadata() {
  return icyMeta;
}
