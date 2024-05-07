#ifndef PS2REMOTE_H_
#define PS2REMOTE_H_

#include "common.h"

/*
receiver -> microcontroller
DI/DAT -> MISO
DO/CMD -> MOSI
CS -> SS
CLK -> SCK
*/

#define ANSWER_DELAY    _delay_us(10)
#define BUTTON_SELECT   (1 << 0)
#define BUTTON_L3       (1 << 1)
#define BUTTON_R3       (1 << 2)
#define BUTTON_START    (1 << 3)
#define BUTTON_UP       (1 << 4)
#define BUTTON_RIGHT    (1 << 5)
#define BUTTON_DOWN     (1 << 6)
#define BUTTON_LEFT     (1 << 7)
#define BUTTON_L2       (1 << 8)
#define BUTTON_R2       (1 << 9)
#define BUTTON_L1       (1 << 10)
#define BUTTON_R1       (1 << 11)
#define BUTTON_TRIANGLE (1 << 12)
#define BUTTON_CIRCLE   (1 << 13)
#define BUTTON_CROSS    (1 << 14)
#define BUTTON_SQUARE   (1 << 15)

//MODE button has no code and could not be received

#define WORK // TEST is for button name uart transmittion; WORK is for turning off TEST mode

void remoteInit(void);
uint16_t remoteGetButtonsState(void); // returns 16-bit variable, each bit is a button, for mapping - see above ^
uint8_t *remoteGetSticksState(void); // returns array of 4 elements: left stick horizontal position, left vertical, right horizontal, right vertical

#endif