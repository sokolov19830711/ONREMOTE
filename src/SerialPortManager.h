#pragma once

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QTimer>

#include "DataManager.h"

class SerialPortManager : public QObject
{
    Q_OBJECT

public:

    SerialPortManager(DataManager& dataManager, QObject *parent = nullptr);
    virtual ~SerialPortManager();

    Q_INVOKABLE QString getPortName() const;
    Q_INVOKABLE QStringList avaliablePortsNames() const;


signals:
    void deviceConnected(bool state);
    void noConnection();
    void connectedToPort(QString portName);

public slots:

     void refresh();
     void setPort(const QString& name);

private:

    DataManager& _dataManager;

    QSerialPort _port;
	int _isSync = 0;
	QByteArray _rawData;

    QTimer* _noConnectionTimer;
    const int _connectionWaitingTime = 10000; // Сколько ждем, прежде чем шлем сигнал об отсутствии связи с устройством (мс)
};
