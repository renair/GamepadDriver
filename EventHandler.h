#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include "GamepadState.h"

class EventHandler : public QObject
{
Q_OBJECT
private:

public:
    EventHandler();
    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;
    ~EventHandler();
public slots:
    void joystickStateChanged(GamepadState);
};

#endif // EVENTHANDLER_H
