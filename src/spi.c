#include "../inc/spi.h"

void spiInit(void) {

    DDRB |= (1 << SS) | (1 << MOSI) | (1 << SCK); // this must be done by user
    SPCR = (1 << SPE) | (1 << CPOL) | (1 << MSTR) | (1 << SPR1); //mode 2, frequency 250 kHz
}

uint8_t spiExchangeByte(uint8_t byte) {

    LOW(SS);
    SPDR = byte;
    while(!(SPSR & (1 << SPIF))) // slave SPDR exchange
        continue;
    HIGH(SS);
    return (SPDR);
}