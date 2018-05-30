#ifndef MOUSEJOYSTICKREACTION_H
#define MOUSEJOYSTICKREACTION_H

#include <windows.h>
#include "JoystickReaction.h"

class MouseJoystickReaction : public JoystickReaction
{
private:
    static const int _step;
    bool _isActual;
    POINT _pos;
    INPUT _input;
    virtual void react(byte);
public:
    MouseJoystickReaction();
    MouseJoystickReaction(const MouseJoystickReaction&) = delete;
    MouseJoystickReaction& operator=(const MouseJoystickReaction&) = delete;
    ~MouseJoystickReaction();
};
#endif // MOUSEJOYSTICKREACTION_H
