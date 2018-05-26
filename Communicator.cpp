#include "Communicator.h"
#include <QSerialPortInfo>

Communicator::Communicator():
    _serialPort(NULL)
{}

Communicator::~Communicator()
{
    delete _serialPort;
}

void Communicator::setupPort()
{
    if(_serialPort && !_serialPort->isOpen())
    {
        return;
    }
    _serialPort->setBaudRate(QSerialPort::Baud9600);
    _serialPort->setStopBits(QSerialPort::OneStop);
    _serialPort->setParity(QSerialPort::NoParity);
}

bool Communicator::testDevice()
{
    return true;
}

void Communicator::dataArrived()
{
    Q_ASSERT(_serialPort != NULL);
    if(_serialPort->bytesAvailable() >= 2)
    {
        int16_t val = 0;
        _serialPort->read((char*)&val, sizeof(val));
        _gamepadState.setState(val);
        emit newDeviceState(_gamepadState);
    }
}

bool Communicator::detectDevice()
{
    for(QSerialPortInfo& portInfo : QSerialPortInfo::availablePorts())
    {
        _portName = portInfo.portName();
        if(testDevice())
        {
            return true;
        }
    }
    return false;
}

bool Communicator::isDeviceEnabled()
{
    return _serialPort && _serialPort->isOpen();
}

void Communicator::enableDevice()
{
    if(_serialPort)
    {
        _serialPort->close();
        delete _serialPort;
    }
    _serialPort = new QSerialPort(_portName);
    setupPort();
    _serialPort->open(QSerialPort::ReadWrite);
}

void Communicator::disableDevice()
{
    if(!_serialPort)
    {
        return;
    }
    _serialPort->close();
    delete _serialPort;
    _serialPort = NULL;
}
