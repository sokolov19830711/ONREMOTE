#include "SmtpManager.h"

#include <QDebug>

SmtpManager::SmtpManager(DataManager& dataManager, QObject* parent) :
	QObject(parent),
	_dataManager(dataManager)
{
	_smtp = _smtp = new SmtpClient(_dataManager.getSettingsStringValue("SMTP/server"), _dataManager.settings()->value("SMTP/port").toInt());
	_messageTimer = new QTimer(this);
	_messageTimer->start(300000);
	connect(_messageTimer, SIGNAL(timeout()), this, SLOT(sendEventLog()));

	_initDelayTimer = new QTimer(this);
	_initDelayTimer->setSingleShot(true);
	_initDelayTimer->start(5000);
}

SmtpManager::~SmtpManager()
{
	delete _smtp;
}

void SmtpManager::sentTestMessage()
{
	QString text = "Тестовое сообщение от устройства " + _dataManager.settings()->value("SMTP/deviceName").toString();
	sendMessage({ text });
}

void SmtpManager::addEventToLog(const QString& eventText)
{
	QString text;
	text += QDate::currentDate().toString("dd.MM.yyyy");
	text += " ";
	text += QTime::currentTime().toString("hh:mm");
	text += " ";
	text += eventText;

	if (!_eventLog.contains(text))
	{
		_eventLog.push_back(text);
	}
}

void SmtpManager::sendMessage(const QStringList& messageText)
{
	if (messageText.isEmpty())
	{
		return;
	}

	_smtp->setHost(_dataManager.settings()->value("SMTP/server").toString());
	_smtp->setPort(_dataManager.settings()->value("SMTP/port").toInt());

	/*if (_settings->value("SMTP/ssl").toInt()) _smtp->setConnectionType(SmtpClient::SslConnection);
	else _smtp->setConnectionType(SmtpClient::TcpConnection);*/
	_smtp->setConnectionType(SmtpClient::SslConnection);

	_smtp->setUser(_dataManager.settings()->value("SMTP/user").toString());
	_smtp->setPassword(_dataManager.settings()->value("SMTP/password").toString());

	MimeMessage message;
	message.setSender(new EmailAddress(_dataManager.settings()->value("SMTP/user").toString(), ""));
	message.addRecipient(new EmailAddress(_dataManager.settings()->value("SMTP/recipient").toString(), ""));
	message.setSubject("сообщение ONREMOTE+");

	QString messageTextLine;
	for (auto& line : messageText)
	{
		messageTextLine += line;
		messageTextLine += "\n";
	}

	MimeText text;
	text.setText(messageTextLine);
	message.addPart(&text);
	_smtp->connectToHost();
	_smtp->login();
	_smtp->sendMail(message);
	_smtp->quit();
}


void SmtpManager::update()
{
	if (_initDelayTimer->isActive() || !_dataManager.getSettingsValue("turnOn"))
	{
		return;
	}

	// Датчик температуры
	if (_dataManager.getSettingsValue("temperatureFlag_notification"))
	{
		unsigned char temperature = _dataManager.getMcuValue("temperatureSensor");
		if (temperature < _dataManager.getSettingsValue("temperatureMinValue") || temperature > _dataManager.getSettingsValue("temperatureMaxValue"))
		{
			addEventToLog(QString("Срабатывание датчика температуры. Значение: %1").arg(temperature));
		}
	}

	// Датчики вскрытия
	if (_dataManager.getSettingsValue("breakInFlag_notification1"))
	{
		if (_dataManager.getMcuValue("breakInSensor1") != _dataManager.getSettingsValue("breakInSensorNormalState1"))
		{
			addEventToLog("Срабатывание встроенного датчика вскрытия");
		}
	}

	if (_dataManager.getSettingsValue("breakInFlag_notification2"))
	{
		if (_dataManager.getMcuValue("breakInSensor2") != _dataManager.getSettingsValue("breakInSensorNormalState2"))
		{
			addEventToLog("Срабатывание внешнего датчика вскрытия");
		}
	}

	// Датчи пыли
	if (_dataManager.getSettingsValue("dustFlag_notification"))
	{
		if (_dataManager.getMcuValue("dustSensor") > 60)
		{
			addEventToLog("Срабатывание датчика запыленности");
		}
	}

    // Счетчики наработки

    // Общая наработка устройства
    uint hours = _dataManager.getSettingsValue("totalHwHoursNotification");
    uint minutes = _dataManager.getSettingsValue("totalHwMinutesNotification");
    uint seconds = _dataManager.getSettingsValue("totalHwSecondsNotification");
    if(hours || minutes || seconds)
    {
        uint sum = hours * 3600 + minutes * 60 + seconds;
        if(sum < _dataManager.getDeviceTotalTimeSec())
        {
            addEventToLog("Достигнуто общее заданное время наработки устройства " + _dataManager.settings()->value("SMTP/deviceName").toString());
            qDebug() << "Достигнуто общее заданное время наработки устройства " << _dataManager.settings()->value("SMTP/deviceName").toString() << sum;
        }
    }

    // Наработка устройства за сессию
    hours = _dataManager.getSettingsValue("sessionHwHoursNotification");
    minutes = _dataManager.getSettingsValue("sessionHwMinutesNotification");
    seconds = _dataManager.getSettingsValue("sessionHwSecondsNotification");
    if(hours || minutes || seconds)
    {
        uint sum = hours * 3600 + minutes * 60 + seconds;
        if(sum < _dataManager.getDeviceSessionTimeSec())
        {
            addEventToLog("Достигнуто заданное время наработки устройства за сессию " + _dataManager.settings()->value("SMTP/deviceName").toString());
            qDebug() << "Достигнуто заданное время наработки устройства  за сессию" << _dataManager.settings()->value("SMTP/deviceName").toString() << sum;
        }
    }

    // Общая наработка ПК
    hours = _dataManager.getSettingsValue("totalSwHoursNotification");
    minutes = _dataManager.getSettingsValue("totalSwMinutesNotification");
    seconds = _dataManager.getSettingsValue("totalSwSecondsNotification");
    if(hours || minutes || seconds)
    {
        uint sum = hours * 3600 + minutes * 60 + seconds;
        if(sum < _dataManager.getPcTotalTimeSec())
        {
            addEventToLog("Достигнуто общее заданное время наработки ПК " + _dataManager.settings()->value("SMTP/deviceName").toString());
            qDebug() << "Достигнуто общее заданное время наработки ПК " << _dataManager.settings()->value("SMTP/deviceName").toString() << sum;
        }
    }
}

void SmtpManager::sendEventLog()
{
	if (_eventLog.isEmpty())
	{
		return;
	}

	sendMessage(_eventLog);
	_eventLog.clear();
}
