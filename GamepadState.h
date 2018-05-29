#ifndef GAMEPADSTATE_H
#define GAMEPADSTATE_H

#include <stdint.h>
#include "Constants.h"

class GamepadState
{
private:
    int32_t _state;
public:
    GamepadState(int32_t = 0);
    void setState(int32_t);
    bool isButtonClicked(int32_t) const;
    byte getLeftJoystickDirection() const;
    byte getRightJoystickDirection() const;
};

#endif // GAMEPADSTATE_H
