#include <iostream>
#include <bitset>
#include "EventHandler.h"
#include "reactions/MouseJoystickReaction.h"
#include "reactions/KeyboardJoystickReaction.h"

using namespace std;

EventHandler::EventHandler():
    _leftJoystick(NULL),
    _rightJoystick(NULL),
    _leftTrigger(0x07), // 0x07 - undefined value
    _rightTrigger(0x07),
    _xButton(0x07),
    _aButton(0x07),
    _bButton(0x07),
    _yButton(0x07),
    _leftFunctionButton(0x07),
    _rightFunctionButton(0x07),
    _leftJoystickButon(0x07),
    _rightJoystickButton(0x07)
{
    _rightJoystick = new KeyboardJoystickReaction;//MouseJoystickReaction;
}

EventHandler::~EventHandler()
{
    delete _leftJoystick;
    delete _rightJoystick;
}

void EventHandler::joystickStateChanged(GamepadState state)
{
    _rightJoystick->setDirection(state.getRightJoystickDirection());
    //_leftJoystick->setDirection(state.getLeftJoystickDirection());
//    _leftTrigger.setState(state.isButtonClicked(LTRIGGER));
//    _rightTrigger.setState(state.isButtonClicked(RTRIGGER));
//    _xButton.setState(state.isButtonClicked(XBUTTON));
//    _aButton.setState(state.isButtonClicked(ABUTTON));
//    _bButton.setState(state.isButtonClicked(BBUTTON));
//    _yButton.setState(state.isButtonClicked(YBUTTON));
//    _leftFunctionButton.setState(state.isButtonClicked(LFUNBUTTON));
//    _rightFunctionButton.setState(state.isButtonClicked(RFUNBUTTON));
//    _leftJoystickButon.setState(state.isButtonClicked(LJOYBUTTON));
//    _rightJoystickButton.setState(state.isButtonClicked(RJOYBUTTON));
}
