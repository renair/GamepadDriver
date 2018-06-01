#ifndef KEYBOARDKEY_H
#define KEYBOARDKEY_H

#include <windows.h>

class KeyboardKey
{
    bool _state;
    INPUT _input;
public:
    KeyboardKey(int);
    ~KeyboardKey();
    void setKey(int);
    void setState(bool);
};

#endif // KEYBOARDKEY_H
