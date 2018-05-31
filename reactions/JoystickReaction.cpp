#include "JoystickReaction.h"

const unsigned int JoystickReaction::_tickTime = 10; // in msec


JoystickReaction::JoystickReaction():
    _direction(0)
{
    _timer.setSingleShot(false);
    _timer.setInterval(_tickTime);
    connect(&_timer, SIGNAL(timeout()), this, SLOT(activate()));
}

JoystickReaction::~JoystickReaction()
{
    _timer.stop();
}

void JoystickReaction::setDirection(byte direction)
{
    _direction = direction;
    if(_direction != CENTER)
    {
        _timer.start();
    }
    else
    {
        _timer.stop();
        react(CENTER);
    }
}

void JoystickReaction::activate()
{
    react(_direction);
}
