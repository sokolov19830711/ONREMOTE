#include "serialportmanager.h"
#include "firmware/dataStructures.h"

#include <QDebug>

SerialPortManager::SerialPortManager(McuDataManager& dataManager, QObject* parent) :
    QObject(parent),
    _dataManager(dataManager)
{
    _port.setBaudRate(19200);
    connect(&_port, SIGNAL(readyRead()), this, SLOT(refresh()));

    _noConnectionTimer = new QTimer(this);
	connect(_noConnectionTimer, SIGNAL(timeout()), this, SIGNAL(noConnection()));
    _noConnectionTimer->start(_connectionWaitingTime);
}

SerialPortManager::~SerialPortManager()
{

}

QString SerialPortManager::getPortName() const
{
    return _port.portName();
}

bool SerialPortManager::connectedToPort() const
{
    return _port.isOpen();
}

void SerialPortManager::refresh()
{
    static int isSync = 0;
    static int counter = 0;
    static QByteArray data;

    if (isSync != 2)
    {
        data.append(_port.read(sizeof(McuOutData)));
        if(data.size() >= sizeof(McuOutData))
		{
			int marker1Pos = data.indexOf(START_MARKER1);
			int marker2Pos = data.indexOf(START_MARKER2);
			if ((marker2Pos - marker1Pos) == 1)
			{
				data = data.mid(marker1Pos);
                if(data.at(9) == CONTROL_MARKER)
				{
					isSync++;
                    if(isSync == 2)
					{
                        emit deviceConnected(true);
                    }
				}
			}

            else if (data.size() > 1000)
            {
                data.clear();
            }
		}
    }

    else
    {
        //qDebug() << "Size of recieved bytearray:" << data.size() << "bytes; content of array:" << data;

        if (data.size() >= sizeof(McuOutData))
        {
            _dataManager.writeMcuOutData(data);
            data = data.mid(sizeof(McuOutData));
        }

		data.append(_port.read(sizeof(McuOutData)));

        _noConnectionTimer->start(_connectionWaitingTime);
    }

    if (counter < 100)
    {
        counter++;
    }
    else // Отсылаем настройки контроллеру на каждый 100 цикл (~раз в 1 сек)
    {
        counter = 0;
        _port.write(reinterpret_cast<const char*>(&(_dataManager.inData())), sizeof(McuInData));
        _port.waitForBytesWritten(10);
    }
}

void SerialPortManager::setPort(const QString &name)
{
    auto ports = QSerialPortInfo::availablePorts();
    for (auto & i : ports)
    {
        if(i.portName() == name)
        {
            _port.close();
            _port.setPort(i);
            _port.setBaudRate(19200);
            _port.open(QIODevice::ReadWrite);
            break;
        }
    }
}
