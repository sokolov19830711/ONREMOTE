#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "DataManager.h"
#include "SerialPortManager.h"
#include "AccountManager.h"
#include "TrayIconManager.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    DataManager dataManager;
    SerialPortManager portManager(dataManager);
    AccountManager accountManager(dataManager);
    TrayIconManager trayIconManager;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataManager", &dataManager);
    engine.rootContext()->setContextProperty("portManager", &portManager);
    engine.rootContext()->setContextProperty("accountManager", &accountManager);
    engine.rootContext()->setContextProperty("trayIconManager", &trayIconManager);
    engine.load(QUrl(QStringLiteral("qrc:/src/qml/main.qml")));
    return app.exec();
}