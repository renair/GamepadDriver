#include "MouseJoystickReaction.h"
#include <windowsx.h>

const int MouseJoystickReaction::_step = 5;

MouseJoystickReaction::MouseJoystickReaction():
    _isActual(false),
    _pos{0, 0}
{
    memset(&_input, 0,  sizeof(INPUT));
    _input.type = INPUT_MOUSE;
    _input.mi.dwFlags = MOUSEEVENTF_MOVE;
}

MouseJoystickReaction::~MouseJoystickReaction()
{}

void MouseJoystickReaction::react(byte direction)
{
    switch(direction)
    {
    case UP: _pos.y = -_step;
             _pos.x = 0;
             break;
    case UP_RIGHT:
             _pos.y = -_step;
             _pos.x = _step;
             break;
    case RIGHT:
             _pos.x = _step;
             _pos.y = 0;
             break;
    case RIGHT_DOWN:
            _pos.y = _step;
            _pos.x = _step;
             break;
    case DOWN:
             _pos.x = 0;
             _pos.y = _step;
             break;
    case DOWN_LEFT:
             _pos.y = _step;
             _pos.x = -_step;
             break;
    case LEFT:
             _pos.x = -_step;
             _pos.y = 0;
             break;
    case LEFT_UP:
             _pos.y = -_step;
             _pos.x = -_step;
             break;
    default:
             return;
    }
    _input.mi.dx = _pos.x;
    _input.mi.dy = _pos.y;
    SendInput(1, &_input, sizeof(INPUT));
}

