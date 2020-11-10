#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "McuDataManager.h"
#include "SerialPortManager.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    McuDataManager dataManager;

    SerialPortManager portManager(dataManager);
    portManager.setPort("COM3");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataManager", &dataManager);
    engine.rootContext()->setContextProperty("portManager", &portManager);
    engine.load(QUrl(QStringLiteral("qrc:/src/qml/main.qml")));
    return app.exec();
}