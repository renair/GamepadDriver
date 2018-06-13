#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <QSerialPort>
#include "GamepadState.h"

// Protocol Description
//  Bit   |   Value
//   1    |   Button 1
//   2    |   Button 2
//   3    |   Button 3
//   4    |   Button 4
//   5    |   Button 5
//   6    |   Button 6
//   7    |   Button 7
//   8    |   Button 8
//   9    |   Button 9
//   10   |   Button 10
// 11-13  |   Joystick Left
// 14-16  |   Joystick Right
// Protocol have 16 bit so int16_i is used for data transmission.

class Communicator : public QObject
{
Q_OBJECT
private:
    QSerialPort* _serialPort;
    QString _portName;
    GamepadState _gamepadState;

    void setupPort();
    void setDataHandler();
    bool testDevice();
private slots:
    void dataArrived();
public:
    Communicator();
    ~Communicator();
    bool detectDevice();
    bool isDeviceEnabled();
    void enableDevice();
    void disableDevice();
signals:
    void newDeviceState(GamepadState);
};

#endif // COMMUNICATOR_H
