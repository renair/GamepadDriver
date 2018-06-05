#include <iostream>
#include <QApplication>
#include "Communicator.h"
#include "EventHandler.h"
#include "CustomConfiguration.h"
#include "PressEater.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //create objects
    Communicator comm;
    EventHandler handler;
    //setup its
    if(!comm.detectDevice())
    {
        cout << "Device not found!" << endl;
        return 1;
    }
    comm.enableDevice();
    //connect device data do handler
    QObject::connect(&comm, SIGNAL(newDeviceState(GamepadState)),&handler, SLOT(joystickStateChanged(GamepadState)));

    Configurations configs;

    CustomConfiguration customConfiguration(configs);

    a.installEventFilter(new PressEater(&customConfiguration));
    customConfiguration.show();

    return a.exec();
}
