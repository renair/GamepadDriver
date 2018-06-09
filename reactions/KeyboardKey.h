#ifndef KEYBOARDKEY_H
#define KEYBOARDKEY_H

#include <windows.h>

class KeyboardKey
{
    INPUT _input;
    bool _state;
    short _keycode;
public:
    KeyboardKey(int);
    ~KeyboardKey();
    void setKey(int);
    void setState(bool);
};

#endif // KEYBOARDKEY_H
