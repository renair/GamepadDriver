#include <iostream>
#include <bitset>
#include "EventHandler.h"

using namespace std;

EventHandler::EventHandler()
{}

EventHandler::~EventHandler()
{}

void EventHandler::joystickStateChanged(GamepadState state)
{
    cout << "Joystick:" << (int)state.getLeftJoystickDirection() << endl;
}
