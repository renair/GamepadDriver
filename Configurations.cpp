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
