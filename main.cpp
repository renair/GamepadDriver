#include <iostream>
#include <QApplication>
#include "Communicator.h"
#include "EventHandler.h"
#include "testbuttons.h"

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
    TestButtons *tb = new TestButtons();
    tb->show();
    return a.exec();
}
