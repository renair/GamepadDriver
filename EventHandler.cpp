#include <iostream>
#include <bitset>
#include "EventHandler.h"
#include "reactions/MouseJoystickReaction.h"
#include "reactions/KeyboardJoystickReaction.h"

using namespace std;

EventHandler::EventHandler(Configurations& conf):
    _configs(conf),
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
    //_rightJoystick = new KeyboardJoystickReaction;//MouseJoystickReaction;
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

void EventHandler::updateConfiguration()
{
    Configurations::KeyCodesPreference& prefs = _configs.getPreferences();
    //setup joysticks
    delete _leftJoystick;
    _leftJoystick = prefs._leftJoystick._type == JOYSTICK_MOUSE ? static_cast<JoystickReaction*>(new MouseJoystickReaction) : static_cast<JoystickReaction*>(new KeyboardJoystickReaction(prefs._leftJoystick));
    delete _rightJoystick;
    _rightJoystick = prefs._rightJoystick._type == JOYSTICK_MOUSE ? static_cast<JoystickReaction*>(new MouseJoystickReaction) : static_cast<JoystickReaction*>(new KeyboardJoystickReaction(prefs._rightJoystick));
    //setup buttons
    _leftTrigger.setKey(prefs._leftTrigger);
    _rightTrigger.setKey(prefs._rightTrigger);
    _xButton.setKey(prefs._xButton);
    _aButton.setKey(prefs._aButton);
    _bButton.setKey(prefs._bButton);
    _yButton.setKey(prefs._yButton);
    _leftFunctionButton.setKey(prefs._leftFunctionButton);
    _rightFunctionButton.setKey(prefs._rightFunctionButton);
    _leftJoystickButon.setKey(prefs._leftJoystickButton);
    _rightJoystickButton.setKey(prefs._rightJoystickButton);
}
