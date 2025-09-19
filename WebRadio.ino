#include <ESP8266WiFi.h>
#include "AudioFileSourceICY.h"
#include "AudioGeneratorMP3.h"
#include "AudioOutputPWM.h"

const char *ssid = "NAZEV_TVE_WIFI";
const char *password = "TVE_HESLO";
const char *streamURL = "http://icecast.radio.cz:8000/cro-dvojka-128.mp3";

AudioGeneratorMP3 *mp3;
AudioFileSourceICY *file;
AudioOutputPWM *out;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  file = new AudioFileSourceICY(streamURL);
  out = new AudioOutputPWM();
  mp3 = new AudioGeneratorMP3();
  mp3->begin(*file, *out);
}

void loop() {
  if (mp3->isRunning()) {
    mp3->loop();
  } else {
    Serial.println("MP3 stream ended");
    delay(1000);
  }
}
