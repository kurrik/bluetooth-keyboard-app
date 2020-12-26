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
have a suitable serial port show up in my system.  I also needed to change
cables before the board showed up in my system (as `/dev/tty.SLAB_USBtoUART`).

I [updated the
bootloader](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/updating-the-bootloader)
since I was using the older nRF52832 board.

### First test
The sketch in `src/test_blinky_sketch` blinks the red LED by the USB port on
the board on and off once a second.

### Wiring buttons
I wired buttons to [pin 7 and 11](https://learn.adafruit.com/assets/46248) and wrote
a quick sketch to test [reading the value](https://learn.adafruit.com/adafruit-arduino-lesson-6-digital-inputs?view=all).

Eventually it may be interesting to use [button breakout
boards](https://learn.adafruit.com/ble-hid-keyboard-buttons-with-circuitpython/ble-keyboard-buttons)
like [these](https://www.adafruit.com/product/4431).

### Bluetooth
The [Bluetooth HID keyboard
example](https://github.com/adafruit/Adafruit_nRF52_Arduino/blob/master/libraries/Bluefruit52Lib/examples/Peripheral/hid_keyboard/hid_keyboard.ino)
is useful for showing how to bond the board to a host device. I initially had
some problem with serial data being garbled but it turned out to be fixable
by making my USB cables were seated correctly.

When running, the board can have a battery installed and be unplugged from the USB.

The [Bluetooth HID API](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/blehidadafruit) has a few different methods to send key press data to the host.