#include "KeyboardKey.h"
#include <iostream>

KeyboardKey::KeyboardKey(int keycode):
    _state(false),
    _keycode(keycode)
{
    setKey(keycode);
}

KeyboardKey::~KeyboardKey()
{}

void KeyboardKey::setKey(int keycode)
{
    if(keycode >= 0x01 && keycode <= 0x06)
    {
        memset(&_input, 0, sizeof(INPUT));
        _input.type = INPUT_MOUSE;
        _input.mi.dx = 0;
        _input.mi.dy = 0;
        _input.mi.dwExtraInfo = 0;
    }
    else
    {
        memset(&_input, 0, sizeof(INPUT));
        _input.type = INPUT_KEYBOARD;
        _input.ki.dwExtraInfo = 0;
        _input.ki.wScan = MapVirtualKey(keycode, MAPVK_VK_TO_VSC);
        _input.ki.wVk = keycode;
    }
    _keycode = keycode;
}

void KeyboardKey::setState(bool state)
{
    if(_state == state)
    {
        return;
    }
    switch(_keycode)
    {
    case 0x01: // LMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_LEFTUP;
        //std::cout << (state ? "Presing left mouse" : "Releasing left mouse") << std::endl;
        break;
    case 0x02: // RMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_RIGHTDOWN : MOUSEEVENTF_RIGHTUP;
        std::cout << (state ? "Presing right mouse" : "Releasing right mouse") << std::endl;
        break;
    case 0x04: // MMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_MIDDLEDOWN : MOUSEEVENTF_MIDDLEUP;
        //std::cout << (state ? "Presing central mouse" : "Releasing central mouse") << std::endl;
        break;
    case 0x05: // Fwd MMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_WHEEL : 0;
        _input.mi.mouseData = state ? WHEEL_DELTA : 0;
        //std::cout << "fwd mmb" << std::endl;
        break;
    case 0x06: // Bwd MMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_WHEEL : 0;
        _input.mi.mouseData = state ? -WHEEL_DELTA : 0;
        //std::cout << "Bwd mmb" << std::endl;
        break;
    default: // keyboard key
        _input.ki.dwFlags = state ? 0 : KEYEVENTF_KEYUP;
        //std::cout << (state ? "Presing btn" : "Releasing btn") << std::endl;
        break;
    }
    _state = state;
    SendInput(1, &_input, sizeof(INPUT));
}
