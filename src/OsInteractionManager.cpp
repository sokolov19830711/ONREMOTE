#include "OsInteractionManager.h"

#include <QCoreApplication>

#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
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
	_dataManager.settings()->setValue("startOnBoot", state);

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
#ifdef Q_OS_LINUX

    // Путь к папке автозапуска
    QString autostartPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation).at(0) + QLatin1String("/autostart");
    /* Проверяем, существует ли директория, в которой будет храниться файл автозапуска.
         * А то мало ли... пользователь удалил...
         * */
    QDir autorunDir(autostartPath);
    if(!autorunDir.exists()){
        // Если не существует, то создаём
        autorunDir.mkpath(autostartPath);
    }
    QFile autorunFile(autostartPath + QLatin1String("/ONREMOTE+.sh.desktop"));

    if(state)
    {
        if(!autorunFile.exists())
        {

            /* Далее открываем файл и записываем в него необходимые данные
                     * с указанием пути к исполняемому файлу, с помощью QCoreApplication::applicationFilePath()
                     * */
            if(autorunFile.open(QFile::WriteOnly))
            {
                QDir scriptDir(QCoreApplication::applicationFilePath());
                scriptDir.cdUp();
                QString filePathToScript = scriptDir.absolutePath() + "/ONREMOTE+.sh";
                QString autorunContent("[Desktop Entry]\n"
                                       "Type=Application\n"
                                       "Exec=" + filePathToScript + "\n"
                                                                    "Hidden=false\n"
                                                                    "NoDisplay=false\n"
                                                                    "X-GNOME-Autostart-enabled=true\n"
                                                                    "Name[en_GB]=ONREMOTE+\n"
                                                                    "Name=ONREMOTE+\n"
                                                                    "Comment[en_GB]=ONREMOTE+\n"
                                                                    "Comment=ONREMOTE+\n");
                QTextStream outStream(&autorunFile);
                outStream << autorunContent;
                // Устанавливаем права доступа, в том числе и на исполнение файла, иначе автозапуск не сработает
                autorunFile.setPermissions(QFileDevice::ExeUser|QFileDevice::ExeOwner|QFileDevice::ExeOther|QFileDevice::ExeGroup|
                                           QFileDevice::WriteUser|QFileDevice::ReadUser);
                autorunFile.close();
            }
        }
    }

    else
    {
        // Удаляем файл автозапуска
        if(autorunFile.exists()) autorunFile.remove();
    }

#endif
}

void OsInteractionManager::setLockOS(bool state) const
{
	_dataManager.settings()->setValue("lockOS", state);
}

void OsInteractionManager::lockOS() const
{
	if(_dataManager.settings()->value("lockOS").toBool())
	{
#ifdef Q_OS_WIN32
		LockWorkStation();
#endif

#ifdef Q_OS_LINUX
        QProcess::execute("gnome-session-quit", {"--force", "--no-prompt"});
        QProcess::execute("mate-session-save", {"--force-logout"});
        QProcess::execute("cinnamon-session-quit", {"--logout", "--force"});
#endif
	}
}
