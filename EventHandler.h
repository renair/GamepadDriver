#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include "GamepadState.h"
#include "reactions/MouseJoystickReaction.h"

class EventHandler : public QObject
{
Q_OBJECT
private:
    JoystickReaction* _leftJoystick;
    JoystickReaction* _rightJoystick;
public:
    EventHandler();
    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;
    ~EventHandler();
public slots:
    void joystickStateChanged(GamepadState);
};

#endif // EVENTHANDLER_H
