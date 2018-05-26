#ifndef GAMEPADSTATE_H
#define GAMEPADSTATE_H

#include <stdint.h>
#include "Constants.h"

class GamepadState
{
private:
    union
      {
        int16_t _value;
        struct
        {
          int16_t _buttons : 10;
          byte _directionL : 3; // left joystick direction
          byte _directionR : 3; // right joystick direction
        } _bits;
      } _state;
public:
    GamepadState(int16_t = 0);
    void setState(int16_t);
    bool isButtonClicked(int16_t) const;
    byte getLeftJoystickDirection() const;
    byte getRightJoystickDirection() const;
};

#endif // GAMEPADSTATE_H
