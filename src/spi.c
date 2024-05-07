#include "../inc/spi.h"

void spiInit(void) {

    DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK);                // this must be done by user
    SPCR = (1 << SPE) | (1 << DORD) | (1 << MSTR) | (1 << SPR1); // SPI mode 0, frequency 250 kHz, LSB first
}

uint8_t spiExchangeByte(uint8_t byte) {

    SPDR = byte;
    while(!(SPSR & (1 << SPIF))) // slave SPDR exchange
        continue;
    return (SPDR);
}