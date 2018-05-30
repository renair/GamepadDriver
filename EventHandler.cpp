#include <iostream>
#include <bitset>
#include "EventHandler.h"

using namespace std;

EventHandler::EventHandler():
    _leftJoystick(NULL),
    _rightJoystick(NULL)
{
    _rightJoystick = new MouseJoystickReaction;
}

EventHandler::~EventHandler()
{}

void EventHandler::joystickStateChanged(GamepadState state)
{
    // write handling here
    _rightJoystick->setDirection(state.getRightJoystickDirection());
}
