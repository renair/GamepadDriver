#ifndef KEYBOARDJOYSTICKREACTION_H
#define KEYBOARDJOYSTICKREACTION_H

#include <windows.h>
#include "JoystickReaction.h"
#include "../Configurations.h"

class KeyboardJoystickReaction : public JoystickReaction
{
private:
    virtual void react(byte);
    JoystickKeyCodes& _keyCodes;
    byte _prevDirection;
    INPUT _input;
public:
    KeyboardJoystickReaction(JoystickKeyCodes&);
    KeyboardJoystickReaction(const KeyboardJoystickReaction&) = delete;
    virtual ~KeyboardJoystickReaction();
    KeyboardJoystickReaction& operator=(const KeyboardJoystickReaction&) = delete;
};

#endif // KEYBOARDJOYSTICKREACTION_H
