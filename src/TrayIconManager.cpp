#include "TrayIconManager.h"

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
}