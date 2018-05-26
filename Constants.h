#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>

typedef unsigned char byte;

// Joystick directions
const byte CENTER = 0;
const byte UP = 1;
const byte UP_RIGHT = 2;
const byte RIGHT = 3;
const byte RIGHT_DOWN = 4;
const byte DOWN = 5;
const byte DOWN_LEFT = 6;
const byte LEFT = 7;
const byte LEFT_UP = 8;

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
