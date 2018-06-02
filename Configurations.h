#ifndef CONFIGURATIONS_H
#define CONFIGURATIONS_H

#include <QString>
#include "Constants.h"

struct JoystickKeyCodes
{
    byte _type;
    int _up;
    int _right;
    int _down;
    int _left;
};

class Configurations
{
public:
    struct KeyCodesPreference
    {
        JoystickKeyCodes _leftJoystick;
        JoystickKeyCodes _rightJoystick;
        int _leftTrigger;
        int _rightTrigger;
        int _xButton;
        int _aButton;
        int _bButton;
        int _yButton;
        int _leftFunctionButton;
        int _rightFunctionButton;
        int _leftJoystickButton;
        int _rightJoystickButton;
    };
    Configurations(QString = "");
    ~Configurations();
    bool loadPreferences(QString = "driver.prefs");
    bool savePreferences(QString = "driver.prefs");
    void makeDefault();
    KeyCodesPreference& getPreferences();
    const KeyCodesPreference& getPreferences() const;
private:
    KeyCodesPreference _preferences;
};

#endif // CONFIGURATIONS_H
