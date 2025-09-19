# ESP8266Audio
libraries
# ESP8266Audio (Reconstructed Version)

This is a manually reconstructed and updated version of the **ESP8266Audio** library, tailored for use with ESP8266-based web radios. It includes essential decoder, output, and source modules that were missing or incomplete in the original distribution.

## 🎧 Features

- MP3 decoding via `AudioGeneratorMP3`
- PWM audio output (tested on GPIO1 / TX)
- Compatible with PAM8403 amplifier modules
- Streaming support via HTTP and ICY sources
- Basic support for I2S output (e.g. MAX98357A)
- Designed for use with Arduino IDE and ESP8266 boards

## 📁 Contents

This version includes manually added and verified files such as:

- `AudioGenerator.h`, `AudioOutput.h`, `AudioFileSourceICY.h`, etc.
- PWM and I2S output modules
- Stream source handlers (buffered, HTTP, ICY)
- Example sketch: `WebRadio.ino`

## 🛠️ Notes

- PWM output works best with active speakers or amplifiers
- For better sound quality, consider switching to I2S output
- Tested with Czech radio streams (e.g. Radiožurnál, Rádio Beat)

## 👤 Author

Maintained and reconstructed by **Vladimír (ok2uhh)**  
GitHub: [github.com/ok2uhh](https://github.com/ok2uhh)
