#include "Communicator.h"
#include <QSerialPortInfo>
#include <QThread>
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
}

void Communicator::setDataHandler()
{
    connect(_serialPort, SIGNAL(readyRead()), this, SLOT(dataArrived()));
}

bool Communicator::testDevice()
{
    std::cout << "Testing device on " << _portName.toStdString() << " port" << std::endl;
    enableDevice();
    _serialPort->write("joi?");
    _serialPort->flush();
    for(int i = 0; i < 50 && _serialPort->bytesAvailable() < 4;++i)
    {
        _serialPort->waitForReadyRead(100);
    }
    QString str(_serialPort->read(4));
    if(str != "yes)")
    {
        disableDevice();
        return false;
    }
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
            std::cout<<"Connected to "<<_portName.toStdString()<<" port"<<std::endl;
            setDataHandler();
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
    if(isDeviceEnabled() && _serialPort->portName() == _portName)
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
    bool isOpened = _serialPort->open(QSerialPort::ReadWrite);
    QThread::sleep(2);
    if(!isOpened)
    {
        std::cout << "Port " << _portName.toStdString() << " not opened!" << std::endl;
        return;
    }
}

void Communicator::disableDevice()
{
    std::cout << "Disabling device at " << _portName.toStdString() << std::endl;
    if(!_serialPort)
    {
        return;
    }
    _serialPort->close();
    delete _serialPort;
    _serialPort = NULL;
}
