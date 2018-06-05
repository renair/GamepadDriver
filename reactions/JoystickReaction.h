#ifndef JOYSTICKREACTION_H
#define JOYSTICKREACTION_H

#include <QObject>
#include <QTimer>
#include "Constants.h"

class JoystickReaction: public QObject
{
Q_OBJECT
private:
    byte _direction;
    static const unsigned int _tickTime;
    QTimer _timer;
    virtual void react(byte) = 0;
private slots:
    void activate();
public:
    JoystickReaction();
    virtual ~JoystickReaction();
    void setDirection(byte);
};

#endif // JOYSTICKREACTION_H
