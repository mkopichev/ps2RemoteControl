#include "inc/common.h"

int main(void) {

    initAll();
    
    while(1) {

        uartTransmitBin(spiExchangeByte(0x01));
        uartTransmitStr("\t");
        uartTransmitBin(spiExchangeByte(0x42));
        uartTransmitStr("\t");
        uartTransmitBin(spiExchangeByte(0x00));
        uartTransmitStr("\t");
        uartTransmitBin(spiExchangeByte(0x00));
        uartTransmitStr("\t");
        uartTransmitBin(spiExchangeByte(0x00));
        uartTransmitStr("\r\n");
    }
}