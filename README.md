# ESP32 Blink LED Morse Code

This project demonstrates how to use an ESP32 microcontroller to blink an LED in Morse code using the ESP-IDF (Espressif IoT Development Framework) in C programming language.

## Prerequisites

Before getting started, ensure you have the following:

- ESP32 development board
- [ESP-IDF](https://github.com/espressif/esp-idf) installed (version 5.0.2)
- LED connected to a GPIO pin on the ESP32


## Installation

1. Clone this repository: `git clone https://github.com/R34ll/esp32-blink-morse-code.git`
2. Change into the project directory: `cd esp32-blink-morse-code`
3. Build the project: `idf.py build`
4. Flash the firmware to the ESP32: `idf.py -p <port> flash` (replace `<port>` with the appropriate serial port)

## Usage

Once the firmware is flashed and the ESP32 is powered on, it will start blinking the LED in Morse code. The Morse code message to be blinked can be modified by editing the `morse_code_message` variable in the `morse-code.c` file.

The LED will blink according to the Morse code encoding rules, where a dot is represented by a short blink, a dash is represented by a long blink, and the space between symbols is represented by no blinking. The LED will pause for a longer duration between each letter and word.

