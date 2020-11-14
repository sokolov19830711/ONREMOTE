import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    OnOffButton {
        id: bypassButton
        x: 352
        y: 8
        enabled: true
        checked: !dataManager.isDeviceActive()
        onCheckedChanged: dataManager.setDeviceActive(!checked)
    }

    Text {
        id: text8
        x: 47
        y: 9
        width: 299
        height: 19
        color: "#fefefe"
        text: qsTr("ВКЛЮЧИТЬ РЕЖИМ BYPASS (отключить")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    Text {
        id: text9
        x: 47
        y: 28
        width: 299
        height: 19
        color: "#fefefe"
        text: qsTr("все функции и блокировки)")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    OnOffButton {
        id: startOnBootButton
        x: 352
        y: 60
        enabled: true
    }

    Text {
        id: text10
        x: 19
        y: 61
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("АВТОМАТИЧЕСКИЙ ЗАПУСК ПРИЛОЖЕНИЯ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    Text {
        id: text11
        x: 19
        y: 80
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("ПРИ ЗАГРУЗКЕ ОПЕРАЦИОННОЙ СИСТЕМЫ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    OnOffButton {
        id: lockOSButton
        x: 352
        y: 111
        enabled: true
    }

    Text {
        id: text12
        x: 19
        y: 112
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("БЛОКИРОВАТЬ КОМПЬЮТЕР ЕСЛИ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    Text {
        id: text13
        x: 19
        y: 131
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("УСТРОЙСТВО ОТКЛЮЧЕНО")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    OnOffButton {
        id: soundSignaltButton
        x: 352
        y: 162
        enabled: true
    }

    Text {
        id: text14
        x: 19
        y: 173
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("ЗВУКОВОЙ СИГНАЛ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    OnOffButton {
        id: ledButton
        x: 352
        y: 214
        enabled: true
        checked: dataManager.isLedActive()
        onCheckedChanged: dataManager.setLedActive(checked)
    }

    Text {
        id: text15
        x: 19
        y: 225
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("ИНДИКАЦИЯ LED")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    Button {
        id: passwordButton
        x: 292
        y: 264
        width: 100
        height: 40
        text: "ПАРОЛЬ"
        font.pointSize: 10

        background: Rectangle {
            color: parent.pressed ? "#166999" : "#30859B"
        }

        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            font: parent.font
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
    }

    Text {
        id: text16
        x: 30
        y: 265
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("нажмите, если хотите заменить")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.italic: true
        minimumPixelSize: 10
    }

    Text {
        id: text17
        x: 30
        y: 284
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("или сбросить пароль приложения")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.italic: true
        minimumPixelSize: 10
    }

    OnOffButton {
        id: lockAppButton
        x: 352
        y: 315
        enabled: true
    }

    Text {
        id: text18
        x: 19
        y: 316
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("БЛОКИРОВАТЬ ПРИЛОЖЕНИЕ ПОСЛЕ ТРЕХ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    Text {
        id: text19
        x: 19
        y: 335
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("ПОПЫТОК ВВОДА ПАРОЛЯ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    ComboBox {
        id: portBox
        x: 288
        y: 366
        width: 104
        height: 40
        font.bold: true
        font.pointSize: 10

        model: portManager.avaliablePortsNames()
        displayText: portManager.getPortName()

        onActivated: {portManager.setPort(currentText); displayText = currentText}

        Connections {
            target: portManager
            function onConnectedToPort(portName) {}
        }
    }

    Text {
        id: text20
        x: 108
        y: 377
        width: 174
        height: 19
        color: "#fefefe"
        text: qsTr("ПОДКЛЮЧЕНИЕ ЧЕРЕЗ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
    }

    Button {
        id: resetToDefaultButton
        x: 292
        y: 449
        width: 100
        height: 40
        text: "СБРОСИТЬ"
        background: Rectangle {
            color: parent.pressed ? "#166999" : "#30859B"
        }
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        font.pointSize: 10
    }

    Text {
        id: text21
        x: 30
        y: 449
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("нажмите, чтобы сбросить")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.italic: true
        minimumPixelSize: 10
    }

    Text {
        id: text22
        x: 30
        y: 468
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("все настройки")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.italic: true
        minimumPixelSize: 10
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
