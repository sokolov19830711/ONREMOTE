#pragma once

#include <QObject>
#include <QSystemTrayIcon>
#include <QMenu>

class TrayIconManager : public QObject
{
	Q_OBJECT

public:

	TrayIconManager();

signals:

	void showAppWindow();

public slots:
	void trayIconActivated(QSystemTrayIcon::ActivationReason reason);

private:

	QSystemTrayIcon* _trayIcon;
	QMenu* _trayMenu;

};