#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include "GamepadState.h"
#include "Configurations.h"
#include "reactions/JoystickReaction.h"
#include "reactions/KeyboardKey.h"

class EventHandler : public QObject
{
Q_OBJECT
private:
    Configurations& _configs;
    JoystickReaction* _leftJoystick;
    JoystickReaction* _rightJoystick;
    KeyboardKey _leftTrigger;
    KeyboardKey _rightTrigger;
    KeyboardKey _xButton;
    KeyboardKey _aButton;
    KeyboardKey _bButton;
    KeyboardKey _yButton;
    KeyboardKey _leftFunctionButton;
    KeyboardKey _rightFunctionButton;
    KeyboardKey _leftJoystickButon;
    KeyboardKey _rightJoystickButton;
public:
    EventHandler(Configurations&);
    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;
    ~EventHandler();
public slots:
    void joystickStateChanged(GamepadState);
    void updateConfiguration();
};

#endif // EVENTHANDLER_H
