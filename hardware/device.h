#ifndef DEVICE_H
#define DEVICE_H

#include <qserialport.h>


class Device
{
public:
    Device();
    Device(QString _portName);
    void setPortName(QString name);
    bool connect();
    void disConnect();
    void sendCommand(QString cmd);
    double read();
public:
    bool isConnected;
    QString portName;
    QSerialPort *serial;
};

#endif // DEVICE_H
