#include "SerialPortManager.h"
#include "firmware/dataStructures.h"

#include <QDebug>

SerialPortManager::SerialPortManager(DataManager& dataManager, QObject* parent) :
    QObject(parent),
    _dataManager(dataManager)
{
    _port.setBaudRate(19200);
    connect(&_port, SIGNAL(readyRead()), this, SLOT(refresh()));

    _noConnectionTimer = new QTimer(this);
	connect(_noConnectionTimer, SIGNAL(timeout()), this, SIGNAL(noConnection()));
    _noConnectionTimer->start(_connectionWaitingTime);

    setPort(_dataManager.settings()->value("SerialPort/name").toString());
}

SerialPortManager::~SerialPortManager()
{
    _dataManager.settings()->setValue("SerialPort/name", getPortName());
}

QString SerialPortManager::getPortName() const
{
    return _port.portName();
}

QStringList SerialPortManager::avaliablePortsNames() const
{
    QStringList portsNames;
	auto ports = QSerialPortInfo::availablePorts();
    for (auto& i : ports)
    {
        portsNames.push_back(i.portName());
    }
    return portsNames;
}

void SerialPortManager::refresh()
{
    if (_isSync != 2)
    {
        _rawData.append(_port.read(sizeof(McuOutData)));
        if(_rawData.size() >= sizeof(McuOutData))
		{
			int marker1Pos = _rawData.indexOf(START_MARKER1);
			int marker2Pos = _rawData.indexOf(START_MARKER2);
			if ((marker2Pos - marker1Pos) == 1)
			{
                _rawData = _rawData.mid(marker1Pos);
                if(_rawData.at(6) == CONTROL_MARKER)
				{
					_isSync++;
                    if(_isSync == 2)
					{
                        emit deviceConnected(true);
                    }
				}
			}

            else if (_rawData.size() > 1000)
            {
                _rawData.clear();
            }
		}
    }

    else
    {
        //qDebug() << "Size of recieved bytearray:" << _rawData.size() << "bytes; content of array:" << _rawData;

        if (_rawData.size() >= sizeof(McuOutData))
        {
            _dataManager.writeMcuOutData(_rawData);
            _rawData = _rawData.mid(sizeof(McuOutData));
        }

        _rawData.append(_port.read(sizeof(McuOutData)));

        _noConnectionTimer->start(_connectionWaitingTime);
    }

        _port.write(reinterpret_cast<const char*>(&(_dataManager.inData())), sizeof(McuInData));
        _port.waitForBytesWritten(10);
}

void SerialPortManager::setPort(const QString &name)
{
    auto ports = QSerialPortInfo::availablePorts();
    for (auto & i : ports)
    {
        if((i.portName() == name) && (i.description().contains("CH340", Qt::CaseInsensitive)))
        {
            if (_port.isOpen())
            {
                _port.close();
            }
            _port.setPort(i);
            _port.setBaudRate(19200);
            _port.open(QIODevice::ReadWrite);

            _isSync = 0;
            _rawData.clear();

            emit connectedToPort(name);
            return;
        }
    }

	for (auto& i : ports)
	{
		if (i.description().contains("CH340", Qt::CaseInsensitive))
		{
			if (_port.isOpen())
			{
				_port.close();
			}
			_port.setPort(i);
			_port.setBaudRate(19200);
			_port.open(QIODevice::ReadWrite);

			_isSync = 0;
			_rawData.clear();

			emit connectedToPort(name);
			return;
		}
	}
}
