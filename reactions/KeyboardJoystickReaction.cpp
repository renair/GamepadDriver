#include "KeyboardJoystickReaction.h"

KeyboardJoystickReaction::KeyboardJoystickReaction():
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
        _input.ki.wVk = 0x57; // W key
        _input.ki.wScan = MapVirtualKey(0x57, MAPVK_VK_TO_VSC);
        _input.ki.dwFlags = direction & UP ? 0 : KEYEVENTF_KEYUP; // if bit is set - then no flags, otherwise key up
        SendInput(1, &_input, sizeof(INPUT));
    }
    if(diff & RIGHT)
    {
        _input.ki.wVk = 0x44; // D key
        _input.ki.wScan = MapVirtualKey(0x44, MAPVK_VK_TO_VSC);
        _input.ki.dwFlags = direction & RIGHT ? 0 : KEYEVENTF_KEYUP; // if bit is set - then no flags, otherwise key up
        SendInput(1, &_input, sizeof(INPUT));
    }
    if(diff & DOWN)
    {
        _input.ki.wVk = 0x53; // S key
        _input.ki.wScan = MapVirtualKey(0x53, MAPVK_VK_TO_VSC);
        _input.ki.dwFlags = direction & DOWN ? 0 : KEYEVENTF_KEYUP; // if bit is set - then no flags, otherwise key up
        SendInput(1, &_input, sizeof(INPUT));
    }
    if(diff & LEFT)
    {
        _input.ki.wVk = 0x41; // A key
        _input.ki.wScan = MapVirtualKey(0x41, MAPVK_VK_TO_VSC);
        _input.ki.dwFlags = direction & LEFT ? 0 : KEYEVENTF_KEYUP; // if bit is set - then no flags, otherwise key up
        SendInput(1, &_input, sizeof(INPUT));
    }
    _prevDirection = direction;
}
