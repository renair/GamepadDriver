#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>

typedef unsigned char byte;

// Joystick directions
const byte CENTER = 0b0000;
const byte UP = 0b1000;
const byte UP_RIGHT = 0b1100;
const byte RIGHT = 0b0100;
const byte RIGHT_DOWN = 0b0110;
const byte DOWN = 0b0010;
const byte DOWN_LEFT = 0b0011;
const byte LEFT = 0b0001;
const byte LEFT_UP = 0b1001;

// Controller buttons
const int16_t LTRIGGER = 1;
const int16_t RTRIGGER = 1 << 1;
const int16_t XBUTTON = 1 << 2;
const int16_t ABUTTON = 1 << 3;
const int16_t BBUTTON = 1 << 4;
const int16_t YBUTTON = 1 << 5;
const int16_t LFUNBUTTON = 1 << 6;
const int16_t RFUNBUTTON = 1 << 7;
const int16_t LJOYBUTTON = 1 << 8;
const int16_t RJOYBUTTON = 1 << 9;

#endif // CONSTANTS_H
