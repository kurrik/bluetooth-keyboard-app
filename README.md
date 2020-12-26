# bluetooth-keyboard-app
Playing with an Adafruit Feather nRF52

[This Tweet](https://twitter.com/lanewinfield/status/1339257875034566656)
demonstrated an amazing solution to an annoying problem I'd had at work
(fumbling to find the right focus / shortcut for Zoom), and I'd just come off
of playing with a [Christmas tree lights hardware
project](https://github.com/kurrik/treelights) so I quickly ordered an
Adafruit Bluetooth Feather to see if I could make a physical button to control
Zoom on my laptop.

## Hardware
I'm using an [Adafruit Feather nRF52 Bluefruit LE -
nRF52832](https://www.adafruit.com/product/3406) as the Bluetooth Feather.

## Setup

### Solder board
I [soldered the
board](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/ktownsend-assembly)
with plain male headers (I wasn't expecting to add Featherwings extension
boards).

### BSP setup
I installed the [Arduino IDE](https://www.arduino.cc/en/software) and then
[followed these steps to setup the
board](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/arduino-bsp-setup).

I needed to install [this Silicon Labs VCP
driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) to
have a suitable serial port show up in my system.

I also [updated the
bootloader](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/updating-the-bootloader)
since I was using the older nRF52832 board.