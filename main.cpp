#include <iostream>
#include <QApplication>
#include <QMessageBox>
#include "Communicator.h"
#include "EventHandler.h"
#include "CustomConfiguration.h"
#include "PressEater.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    //create objects
    Communicator comm;
    Configurations configs;
    EventHandler handler(configs);
    //setup its
    if(!comm.detectDevice())
    {
        cout << "Device not found!" << endl;
        QMessageBox::warning(NULL, "Device not found" ,"Please connect device to computer and try again or if device has already connected reconnect it to another port.");
        return 1;
    }
    comm.enableDevice();
    //connect device data to handler
    QObject::connect(&comm, SIGNAL(newDeviceState(GamepadState)),&handler, SLOT(joystickStateChanged(GamepadState)));

    CustomConfiguration customConfiguration(configs);
    QObject::connect(&customConfiguration, SIGNAL(buttonChangingDone()), &handler, SLOT(updateConfiguration()));

    a.installEventFilter(new PressEater(&customConfiguration));
    customConfiguration.show();

    QObject::connect(&a, SIGNAL(aboutToQuit()), &comm, SLOT(disableDevice()));
    return a.exec();
}
