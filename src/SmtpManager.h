#pragma once

#include <QObject>
#include <QTimer>

#include "../../SmtpClient-for-Qt/src/SmtpMime"
#include "DataManager.h"

class SmtpManager : public QObject
{
	Q_OBJECT

public:

	SmtpManager(DataManager& dataManager, QObject* parent = nullptr);
	virtual ~SmtpManager();

public slots:

	void update();
	void sentTestMessage();

private slots:

	void sendEventLog();

private:

	void addEventToLog(const QString& eventText);
	void sendMessage(const QStringList& messageText);

	DataManager& _dataManager;

	SmtpClient* _smtp = nullptr;
	QStringList _eventLog;

	QTimer* _initDelayTimer; // Организуем задержку при обработке значений от устройства, чтобы успела установиться связь
	QTimer* _messageTimer;
};