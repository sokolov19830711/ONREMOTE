#include "TrayIconManager.h"

#include <QCoreApplication>

TrayIconManager::TrayIconManager()
{
	_trayIcon = new QSystemTrayIcon(QIcon(":trayIcon.png"), this);
	_trayIcon->setToolTip("Программа мониторинга\nONREMOTE+");
	_trayIcon->show();

	_trayMenu = new QMenu;
	QAction* viewWindow = new QAction("Открыть окно", this);
	QAction* quitAction = new QAction("Выход", this);
	_trayMenu->addAction(viewWindow);
	_trayMenu->addAction(quitAction);
	_trayIcon->setContextMenu(_trayMenu);

	connect(viewWindow, &QAction::triggered, this, &TrayIconManager::showAppWindow);
	connect(quitAction, &QAction::triggered, [] (){ QCoreApplication::quit(); }); // To Do: Проследить, чтоб приложение завершалось корректно, настройки успевали сохранится!
	connect(_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));
}

void TrayIconManager::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Unknown:
		break;
	case QSystemTrayIcon::Context:
		break;
	case QSystemTrayIcon::DoubleClick:
		emit showAppWindow();
		break;
	case QSystemTrayIcon::Trigger:
		emit showAppWindow();
		break;
	case QSystemTrayIcon::MiddleClick:
		break;
	default:
		break;
	}
}
