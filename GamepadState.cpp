#include "GamepadState.h"
#include <QObject>

Q_DECLARE_METATYPE(GamepadState);
const int GamepadStateTypeId = qRegisterMetaType<GamepadState>();

GamepadState::GamepadState(int32_t value)
{
    setState(value);
}

void GamepadState::setState(int32_t value)
{
    _state = value;
}

bool GamepadState::isButtonClicked(int32_t button) const
{
    return _state & button;
}

byte GamepadState::getLeftJoystickDirection() const
{
    return (_state >> 10) & 0b1111;
}

byte GamepadState::getRightJoystickDirection() const
{
    return (_state >> 14) & 0b1111;
}
