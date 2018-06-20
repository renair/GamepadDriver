#include <QFile>
#include "Configurations.h"

Configurations::Configurations(QString filename)
{
    QString s = filename;
    // make preferences default if filename is empty or file can't be loaded
    if(filename.isEmpty() || !loadPreferences(filename))
    {
        makeDefault();
    }
}

Configurations::~Configurations()
{}

bool Configurations::loadPreferences(const QString& filename)
{
    QFile file(filename);
    const int pref_size = sizeof(_preferences);
    if(file.size() < pref_size || !file.open(QFile::ReadOnly))
    {
        return false;
    }
    int read = file.read((char*)&_preferences, pref_size);
    file.close();
    return read == pref_size;
}

bool Configurations::savePreferences(const QString& filename)
{
    QFile file(filename);
    const int pref_size = sizeof(_preferences);
    if(!file.open(QFile::WriteOnly))
    {
        return false;
    }
    int written = file.write((char*)&_preferences, pref_size);
    file.close();
    return written == pref_size;
}

void Configurations::makeDefault()
{
    getPreferences()._leftTrigger = 0x02; // RMB
    getPreferences()._rightTrigger = 0x01; // LMB
    getPreferences()._xButton = 0x51; // Q
    getPreferences()._aButton = 0x46; // F
    getPreferences()._bButton = 0x45; // E
    getPreferences()._yButton = 0x52; // R
    getPreferences()._leftFunctionButton = 0x25; // Esc
    getPreferences()._rightFunctionButton = 0x09; // Tab
    getPreferences()._leftJoystickButton = 0x43; // C
    getPreferences()._rightJoystickButton = 0x47; // G
    getPreferences()._leftJoystick._type = JOYSTICK_KEYBOARD;
    getPreferences()._leftJoystick._up = 0x57; // W
    getPreferences()._leftJoystick._down = 0x53; // S
    getPreferences()._leftJoystick._left = 0x41; // A
    getPreferences()._leftJoystick._right = 0x44; // D
    getPreferences()._rightJoystick._type = JOYSTICK_MOUSE;
    getPreferences()._rightJoystick._up = 0x57;
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
