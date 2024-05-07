#include "../inc/ps2Remote.h"

static uint8_t txBuf[9] = {0x01, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static uint8_t rxBuf[9] = {0};

void remoteDataExchange(void) {

    LOW(SS);
    _delay_us(100);

    for(uint8_t i = 0; i < sizeof(txBuf); i++) {

        rxBuf[i] = spiExchangeByte(txBuf[i]);
        ANSWER_DELAY;
    }
    HIGH(SS);
    _delay_us(100);
}

void remoteInit(void) {

    remoteDataExchange();

    if(((rxBuf[1] == 0x41) || (rxBuf[1] == 0x73)) && (rxBuf[2] == 0x5A))
        uartTransmitStr("Remote - OK\r\n");
    else
        uartTransmitStr("Remote - not OK\r\n");
}

uint16_t remoteGetButtonsState(void) {

    remoteDataExchange();
    _delay_ms(10);

    uint16_t buttonsState = rxBuf[3] | (rxBuf[4] << 8);

#ifdef TEST

    for(uint8_t i = 0; i <= 15; i++) {

        if(~buttonsState & (1 << i)) {

            switch(1 << i) {
            case(BUTTON_SELECT):
                uartTransmitStr("Select\r\n");
                break;
            case(BUTTON_L3):
                uartTransmitStr("L3\r\n");
                break;
            case(BUTTON_R3):
                uartTransmitStr("R3\r\n");
                break;
            case(BUTTON_START):
                uartTransmitStr("Start\r\n");
                break;
            case(BUTTON_UP):
                uartTransmitStr("Up\r\n");
                break;
            case(BUTTON_RIGHT):
                uartTransmitStr("Right\r\n");
                break;
            case(BUTTON_DOWN):
                uartTransmitStr("Down\r\n");
                break;
            case(BUTTON_LEFT):
                uartTransmitStr("Left\r\n");
                break;
            case(BUTTON_L2):
                uartTransmitStr("L2\r\n");
                break;
            case(BUTTON_R2):
                uartTransmitStr("R2\r\n");
                break;
            case(BUTTON_L1):
                uartTransmitStr("L1\r\n");
                break;
            case(BUTTON_R1):
                uartTransmitStr("R1\r\n");
                break;
            case(BUTTON_TRIANGLE):
                uartTransmitStr("Triangle\r\n");
                break;
            case(BUTTON_CIRCLE):
                uartTransmitStr("Circle\r\n");
                break;
            case(BUTTON_CROSS):
                uartTransmitStr("Cross\r\n");
                break;
            case(BUTTON_SQUARE):
                uartTransmitStr("Square\r\n");
                break;
            }
        }
    }

#endif

    return ~buttonsState;
}

uint8_t *remoteGetSticksState(void) {

    remoteDataExchange();
    _delay_ms(10);

    static uint8_t sticksState[4];
    sticksState[0] = rxBuf[7];
    sticksState[1] = rxBuf[8];
    sticksState[2] = rxBuf[5];
    sticksState[3] = rxBuf[6];

    return sticksState;
}