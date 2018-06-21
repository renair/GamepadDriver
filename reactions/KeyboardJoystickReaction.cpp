#include "KeyboardJoystickReaction.h"

KeyboardJoystickReaction::KeyboardJoystickReaction(JoystickKeyCodes& codes):
    _keyCodes(codes),
    _prevDirection(0)
{
    _input.type = INPUT_KEYBOARD;
    _input.ki.dwExtraInfo = 0;
}

KeyboardJoystickReaction::~KeyboardJoystickReaction()
{}

void KeyboardJoystickReaction::react(byte direction)
{
    byte diff = direction ^ _prevDirection;
    if(diff & UP)
    {
        _input.ki.wVk = _keyCodes._up;
        _input.ki.wScan = MapVirtualKey(_keyCodes._up, MAPVK_VK_TO_VSC);
        _input.ki.dwFlags = direction & UP ? 0 : KEYEVENTF_KEYUP; // if bit is set - then no flags, otherwise key up
        SendInput(1, &_input, sizeof(INPUT));
    }
    if(diff & RIGHT)
    {
        _input.ki.wVk = _keyCodes._right;
        _input.ki.wScan = MapVirtualKey(_keyCodes._right, MAPVK_VK_TO_VSC);
        _input.ki.dwFlags = direction & RIGHT ? 0 : KEYEVENTF_KEYUP; // if bit is set - then no flags, otherwise key up
        SendInput(1, &_input, sizeof(INPUT));
    }
    if(diff & DOWN)
    {
        _input.ki.wVk = _keyCodes._down;
        _input.ki.wScan = MapVirtualKey(_keyCodes._down, MAPVK_VK_TO_VSC);
        _input.ki.dwFlags = direction & DOWN ? 0 : KEYEVENTF_KEYUP; // if bit is set - then no flags, otherwise key up
        SendInput(1, &_input, sizeof(INPUT));
    }
    if(diff & LEFT)
    {
        _input.ki.wVk = _keyCodes._left;
        _input.ki.wScan = MapVirtualKey(_keyCodes._left, MAPVK_VK_TO_VSC);
        _input.ki.dwFlags = direction & LEFT ? 0 : KEYEVENTF_KEYUP; // if bit is set - then no flags, otherwise key up
        SendInput(1, &_input, sizeof(INPUT));
    }
    _prevDirection = direction;
}
