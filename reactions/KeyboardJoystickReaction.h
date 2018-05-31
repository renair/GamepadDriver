#ifndef KEYBOARDJOYSTICKREACTION_H
#define KEYBOARDJOYSTICKREACTION_H

#include <windows.h>
#include "JoystickReaction.h"

class KeyboardJoystickReaction : public JoystickReaction
{
private:
    virtual void react(byte);
    byte _prevDirection;
    INPUT _input;
public:
    KeyboardJoystickReaction();
    KeyboardJoystickReaction(const KeyboardJoystickReaction&) = delete;
    ~KeyboardJoystickReaction();
    KeyboardJoystickReaction& operator=(const KeyboardJoystickReaction&) = delete;
};

#endif // KEYBOARDJOYSTICKREACTION_H
