#include "KeyboardKey.h"

KeyboardKey::KeyboardKey(int keycode):
    _state(false)
{
    _input.type = INPUT_KEYBOARD;
    _input.ki.dwExtraInfo = 0;
    _input.ki.wScan = 0;
    _input.ki.wVk = keycode;
}

KeyboardKey::~KeyboardKey()
{}

void KeyboardKey::setKey(int keycode)
{
    _input.ki.wVk = keycode;
}

void KeyboardKey::setState(bool state)
{
    if(state != _state)
    {
        _input.ki.dwFlags = state ? 0 : KEYEVENTF_KEYUP;
        SendInput(1, &_input, sizeof(INPUT));
    }
}
