#pragma once

#include "DataManager.h"
#include "SerialPortManager.h"

class OsInteractionManager : public QObject
{
	Q_OBJECT

public:

	OsInteractionManager(DataManager& dataManager, SerialPortManager& portManager, QObject* parent = nullptr);
	virtual ~OsInteractionManager();

	Q_INVOKABLE void setStartOnBoot(bool state) const;
	Q_INVOKABLE void setLockOS(bool state) const;
	Q_INVOKABLE void shutdown() const;
	Q_INVOKABLE void reset() const;
	Q_INVOKABLE void hybernate() const;

public slots:

	void lockOS() const;


private:

	DataManager& _dataManager;
	SerialPortManager& _portManager;
};
