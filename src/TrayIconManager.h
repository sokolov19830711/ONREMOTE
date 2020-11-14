#pragma once

#include <QObject>
#include <QSystemTrayIcon>
#include <QMenu>

class TrayIconManager : public QObject
{
	Q_OBJECT

public:

	TrayIconManager();

private:

	QSystemTrayIcon* _trayIcon;
	QMenu* _trayMenu;

};