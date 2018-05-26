#include "GamepadState.h"
#include <QObject>

Q_DECLARE_METATYPE(GamepadState);
const int GamepadStateTypeId = qRegisterMetaType<GamepadState>();

GamepadState::GamepadState(int16_t value)
{
    setState(value);
}

void GamepadState::setState(int16_t value)
{
    _state._value = value;
}

bool GamepadState::isButtonClicked(int16_t button) const
{
    return (_state._bits._buttons & button) > 0;
}

byte GamepadState::getLeftJoystickDirection() const
{
    return _state._bits._directionL;
}

byte GamepadState::getRightJoystickDirection() const
{
    return _state._bits._directionR;
}
