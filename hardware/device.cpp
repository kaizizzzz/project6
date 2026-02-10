#include "device.h"
#include "qdebug.h"

Device::Device()
{

}

Device::Device(QString _portName)
    : isConnected(false)
{
    this->portName = "COM" + _portName;
}

void Device::setPortName(QString name)
{
    this->portName = "COM" + name;
}

bool Device::connect()
{
    serial = new QSerialPort;
    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::BaudRate::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::StopBits::OneStop);
    serial->setParity(QSerialPort::NoParity);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if( serial->open(QIODevice::ReadWrite) ){
        isConnected = true;
        return isConnected;
    }
    else{
        return isConnected;
    }
}

void Device::disConnect()
{
    serial->close();
}

void Device::sendCommand(QString cmd)
{
    cmd = cmd.trimmed();
    if( !cmd.endsWith("\n") ){
        cmd+="\n";
    }
    // qDebug() << cmd;
    QByteArray data = cmd.toUtf8();
    serial->write(data);
}

double Device::read()
{
    QByteArray resData = serial->readAll();
    QString resString = QString::fromUtf8(resData).trimmed();
    qDebug() << resString;
    double V = resString.toDouble();
    return V;
}


