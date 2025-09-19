#include "AudioGeneratorMP3.h"

AudioGeneratorMP3::AudioGeneratorMP3() {
  // Inicializace dekodéru
}

AudioGeneratorMP3::~AudioGeneratorMP3() {
  stop();
}

bool AudioGeneratorMP3::begin(AudioFileSource &input, AudioOutput &output) {
  // this->input = &input;  ← odstraněno, protože neexistuje
  this->output = &output;
  // Inicializace dekódování MP3
  return true;
}

bool AudioGeneratorMP3::loop() {
  // Zpracování datového toku
  return true;
}

bool AudioGeneratorMP3::stop() {
  // Ukončení dekódování
  return true;
}
