#include "inc/common.h"

int main(void) {

    initAll();

    while(1) {

        uartTransmitBin(remoteGetButtonsState());
        uartTransmitStr("\t");

        uint8_t *analogData = remoteGetSticksState();

        for(uint8_t i = 0; i <= 3; i++) {
            uartTransmitDec(analogData[i]);
            uartTransmitStr("\t");
        }
        uartTransmitStr("\r\n");
    }
}