#include "AudioOutputPWM.h"
#include <Arduino.h>

AudioOutputPWM::AudioOutputPWM() {
  // Nastavení PWM výstupu (např. pin D1)
  pinMode(1, OUTPUT);  // GPIO1 (D1) – můžeš změnit podle potřeby
}

AudioOutputPWM::~AudioOutputPWM() {
  stop();
}

bool AudioOutputPWM::begin() {
  // Inicializace PWM – můžeš přizpůsobit frekvenci nebo rozlišení
  analogWriteFreq(44100);  // 44.1 kHz
  analogWriteRange(255);   // 8bit rozsah
  return true;
}

bool AudioOutputPWM::consumeSample(int16_t sample) {
  // Převede 16bit vzorek na 8bit PWM
  uint8_t pwm = (sample >> 8) + 128;
  analogWrite(1, pwm);  // GPIO1 (D1)
  return true;
}

bool AudioOutputPWM::stop() {
  analogWrite(1, 0);
  return true;
}
