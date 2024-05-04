#ifndef SPI_H_
#define SPI_H_

#include "common.h"

#define SS   2
#define MOSI 3
#define MISO 4
#define SCK  5

#define HIGH(wire) PORTB |= (1 << wire)
#define LOW(wire)  PORTB &= ~(1 << wire)

void spiInit(void);
uint8_t spiExchangeByte(uint8_t byte);

#endif