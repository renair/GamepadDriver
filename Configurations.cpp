#include "Configurations.h"

Configurations::Configurations(QString filename)
{
    // make preferences default if filename is empty or file can't be loaded
    if(filename.isEmpty() || !loadPreferences(filename))
    {
        makeDefault();
    }
}

Configurations::~Configurations()
{}

bool Configurations::loadPreferences(QString filename)
{
    // TODO
    // implement this method
    return false;
}

bool Configurations::savePreferences(QString filename)
{
    // TODO
    // implement this method
    return false;
}

void Configurations::makeDefault()
{
    getPreferences()._leftTrigger = 0;
    getPreferences()._rightTrigger = 0;
    getPreferences()._xButton = 0;
    getPreferences()._aButton = 0;
    getPreferences()._bButton = 0;
    getPreferences()._yButton = 0;
    getPreferences()._leftFunctionButton = 0;
    getPreferences()._rightFunctionButton = 0;
    getPreferences()._leftJoystickButton = 0;
    getPreferences()._rightJoystickButton = 0;
    getPreferences()._leftJoystick._type = 0;
    getPreferences()._leftJoystick._up = 0;
    getPreferences()._leftJoystick._down = 0;
    getPreferences()._leftJoystick._left = 0;
    getPreferences()._leftJoystick._right = 0;
    getPreferences()._rightJoystick._type = 0;
    getPreferences()._rightJoystick._up = 0;
    getPreferences()._rightJoystick._down = 0;
    getPreferences()._rightJoystick._left = 0;
    getPreferences()._rightJoystick._right = 0;
    return;
}

Configurations::KeyCodesPreference& Configurations::getPreferences()
{
    return _preferences;
}

const Configurations::KeyCodesPreference& Configurations::getPreferences() const
{
    return _preferences;
}
