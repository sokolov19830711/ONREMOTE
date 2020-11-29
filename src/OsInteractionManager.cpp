#include "OsInteractionManager.h"

#include <QDir>
#include <QCoreApplication>
#include <QProcess>

#ifdef Q_OS_WIN32
#include <windows.h>
#endif

OsInteractionManager::OsInteractionManager(DataManager& dataManager, SerialPortManager& portManager, QObject* parent) :
	QObject(parent),
	_dataManager(dataManager),
	_portManager(portManager)
{
	connect(&_portManager, &SerialPortManager::noConnection, this, &OsInteractionManager::lockOS);
}

OsInteractionManager::~OsInteractionManager()
{
}

void OsInteractionManager::setStartOnBoot(bool state) const
{
	_dataManager.settings()->setValue("startOnBoot", static_cast<int>(state));

#ifdef Q_OS_WIN32
	QSettings settings("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
	if (state)
	{
		settings.setValue("ONREMOTE+", QDir::toNativeSeparators(QCoreApplication::applicationFilePath()));
		settings.sync();
	}

	else
	{
		settings.remove("ONREMOTE+");
	}
#endif // Q_OS_WIN32
}

void OsInteractionManager::setLockOS(bool state) const
{
	_dataManager.settings()->setValue("lockOS", static_cast<int>(state));
}

void OsInteractionManager::shutdown() const
{
#ifdef Q_OS_WIN32
	QProcess::execute("shutdown", { "/p" });
#endif
}

void OsInteractionManager::reset() const
{
#ifdef Q_OS_WIN32
	QProcess::execute("shutdown", { "/r" });
#endif
}

void OsInteractionManager::hybernate() const
{
#ifdef Q_OS_WIN32
	QProcess::execute("shutdown", { "/h" });
#endif
}

void OsInteractionManager::lockOS() const
{
	if(_dataManager.settings()->value("lockOS").toBool())
	{
#ifdef Q_OS_WIN32
		LockWorkStation();
#endif
	}
}
