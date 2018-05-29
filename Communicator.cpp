#include "Communicator.h"
#include <QSerialPortInfo>
#include <iostream>
#include <bitset>

Communicator::Communicator():
    _serialPort(NULL)
{}

Communicator::~Communicator()
{
    delete _serialPort;
}

void Communicator::setupPort()
{
    if(!_serialPort || _serialPort->isOpen())
    {
        return;
    }
    _serialPort->setBaudRate(QSerialPort::Baud9600);
    _serialPort->setStopBits(QSerialPort::OneStop);
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setFlowControl(QSerialPort::NoFlowControl);
    _serialPort->setDataBits(QSerialPort::Data8);
    connect(_serialPort, SIGNAL(readyRead()), this, SLOT(dataArrived()));
}

bool Communicator::testDevice()
{
    return true;
}

void Communicator::dataArrived()
{
    Q_ASSERT(_serialPort != NULL);
    while(_serialPort->bytesAvailable() >= 4)
    {
        int32_t val = 0;
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
    if(_serialPort && _serialPort->isOpen() && _serialPort->portName() == _portName)
    {
        return;
    }
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
