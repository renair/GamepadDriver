#include "KeyboardKey.h"

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
        _input.type = INPUT_MOUSE;
        _input.mi.dx = 0;
        _input.mi.dy = 0;
        _input.mi.dwExtraInfo = NULL;
    }
    else
    {
        _input.type = INPUT_KEYBOARD;
        _input.ki.dwExtraInfo = 0;
        _input.ki.wScan = MapVirtualKey(keycode, MAPVK_VK_TO_VSC);;
        _input.ki.wVk = keycode;
    }
    _keycode = keycode;
}

void KeyboardKey::setState(bool state)
{
//    if(state != _state)
//    {
//        _input.ki.dwFlags = state ? 0 : KEYEVENTF_KEYUP;
//        SendInput(1, &_input, sizeof(INPUT));
//    }
    switch(_keycode)
    {
    case 0x01: // LMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_LEFTUP;
        break;
    case 0x02: // RMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_RIGHTDOWN : MOUSEEVENTF_RIGHTUP;
        break;
    case 0x04: // MMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_MIDDLEDOWN : MOUSEEVENTF_MIDDLEUP;
        break;
    case 0x05: // Fwd MMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_WHEEL : 0;
        _input.mi.mouseData = state ? WHEEL_DELTA : 0;
        break;
    case 0x06: // Bwd LMB
        _input.mi.dwFlags = state ? MOUSEEVENTF_WHEEL : 0;
        _input.mi.mouseData = state ? -WHEEL_DELTA : 0;
        break;
    default: // keyboard key
        _input.ki.dwFlags = state ? 0 : KEYEVENTF_KEYUP;
        break;
    }
    SendInput(1, &_input, sizeof(INPUT));
}
