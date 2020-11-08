#pragma once

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>

#include "McuDataManager.h"

class SerialPortManager : public QObject
{
    Q_OBJECT

public:

    SerialPortManager(McuDataManager& dataManager, QObject *parent = nullptr);
    virtual ~SerialPortManager();

    QString getPortName() const;
    bool connectedToPort() const;

signals:
    void deviceConnected(bool state);
    void noConnection();

public slots:

     void refresh();
     void setPort(const QString& name);

private:

    McuDataManager& _dataManager;
    const int _connectionWaitingTime = 10000; // ������� ����, ������ ��� ���� ������ �� ���������� ����� � ����������� (��)
    QSerialPort _port;
    QTimer* _noConnectionTimer;
};
