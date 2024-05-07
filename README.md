# Code for reading the PS2 remote controller via SPI. <br>
AVR Atmega328P, 16 MHz, internal SPI. <br>
SPI freqency 250 kHz, mode 0, LSB first. Pins used: MOSI, MISO, SS, SCK. <br>
After spiInit() and remoteInit() functions execution, it is possible to use remoteGetButtonsState() and remoteGetSticksState() functions. First one returns 16-bit uint16_t variable, each bit is button state: 1 - pressed, 0 - released; second one returns 4 bytes uint8_t array pointer: 0 byte is left ctick horizontal position (0 - left, 128 - middle, 255 - right), 1-st byte is left ctick vertical position (0 - down, 128 - middle, 255 - top), 2-nd and 3-rd is for right stick. <br>
Buttons position in 16-bit variable is described in ps2Remote.h file <br>
uartInit() is set for 19200 baud and requires uartInit() function execution first.
