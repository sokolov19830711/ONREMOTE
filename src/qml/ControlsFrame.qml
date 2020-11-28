import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Button {
        id: passwordButton
        x: 292
        y: 230
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

    Button {
        id: smtpButton
        x: 293
        y: 368
        width: 100
        height: 34
        text: "SMTP"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        background: Rectangle {
            color: parent.pressed ? "#166999" : "#30859B"
        }
        font.pointSize: 10
    }

    Button {
        id: runningHoursButton
        x: 292
        y: 449
        width: 100
        height: 34
        text: "НАРАБОТКА"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        background: Rectangle {
            color: parent.pressed ? "#166999" : "#30859B"
        }
        font.pointSize: 10
    }

    OnOffButton {
        id: bypassButton
        x: 352
        y: 0
        enabled: true
        checked: !dataManager.getSettingsValue("turnOn")
        onCheckedChanged: dataManager.setSettingsValue("turnOn", !checked)
    }

    Text {
        id: text8
        x: 47
        y: 1
        width: 299
        height: 19
        color: "#fefefe"
        text: qsTr("ВКЛЮЧИТЬ РЕЖИМ BYPASS (отключить")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text9
        x: 47
        y: 20
        width: 299
        height: 19
        color: "#fefefe"
        text: qsTr("все функции и блокировки)")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    OnOffButton {
        id: startOnBootButton
        x: 352
        y: 46
        checked: dataManager.getSettingsValue("startOnBoot")
        enabled: true

        onToggled: osInteractionManager.setStartOnBoot(startOnBootButton.checked)
    }

    Text {
        id: text10
        x: 19
        y: 48
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("АВТОМАТИЧЕСКИЙ ЗАПУСК ПРИЛОЖЕНИЯ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text11
        x: 19
        y: 67
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("ПРИ ЗАГРУЗКЕ ОПЕРАЦИОННОЙ СИСТЕМЫ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    OnOffButton {
        id: lockOSButton
        x: 352
        y: 92
        checked: dataManager.getSettingsValue("lockOS")
        enabled: true

        onToggled: osInteractionManager.setLockOS(lockOSButton.checked)
    }

    Text {
        id: text12
        x: 19
        y: 93
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("БЛОКИРОВАТЬ КОМПЬЮТЕР ЕСЛИ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text13
        x: 19
        y: 112
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("УСТРОЙСТВО ОТКЛЮЧЕНО")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    OnOffButton {
        id: soundSignaltButton
        x: 352
        y: 138
        enabled: true
        checked: dataManager.getSettingsValue("soundOn")
        onCheckedChanged: dataManager.setSettingsValue("soundOn", checked)
    }

    Text {
        id: text14
        x: 19
        y: 149
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("ЗВУКОВОЙ СИГНАЛ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    OnOffButton {
        id: ledButton
        x: 352
        y: 184
        enabled: true
        checked: dataManager.getSettingsValue("ledOn")
        onCheckedChanged: dataManager.setSettingsValue("ledOn", checked)
    }

    Text {
        id: text15
        x: 19
        y: 195
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("ИНДИКАЦИЯ LED")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text16
        x: 30
        y: 232
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("нажмите, если хотите заменить")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        minimumPixelSize: 10
    }

    Text {
        id: text17
        x: 30
        y: 249
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("или сбросить пароль приложения")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        minimumPixelSize: 10
    }

    OnOffButton {
        id: lockAppButton
        x: 352
        y: 276
        enabled: true
        checked: dataManager.getSettingsValue("lockApp")
        onCheckedChanged: dataManager.setSettingsValue("lockApp", checked)
    }

    Text {
        id: text18
        x: 19
        y: 277
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("БЛОКИРОВАТЬ ПРИЛОЖЕНИЕ ПОСЛЕ ТРЕХ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text19
        x: 19
        y: 296
        width: 327
        height: 19
        color: "#fefefe"
        text: qsTr("ПОПЫТОК ВВОДА ПАРОЛЯ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    ComboBox {
        id: portBox
        x: 289
        y: 322
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
        x: 109
        y: 333
        width: 174
        height: 19
        color: "#fefefe"
        text: qsTr("ПОДКЛЮЧЕНИЕ ЧЕРЕЗ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Button {
        id: resetToDefaultButton
        x: 293
        y: 408
        width: 100
        height: 34
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
        x: 31
        y: 407
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("нажмите, чтобы сбросить")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        minimumPixelSize: 10
    }

    Text {
        id: text22
        x: 30
        y: 423
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("все настройки")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        minimumPixelSize: 10
    }

    Text {
        id: text23
        x: 32
        y: 366
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("настроить отправку")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
        font.italic: true
        font.family: "Calibri Light"
    }

    Text {
        id: text24
        x: 31
        y: 383
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("уведомлений")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
        font.italic: true
        font.family: "Calibri Light"
    }

    Text {
        id: text25
        x: 30
        y: 448
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("нажмите, чтобы посмотреть")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
        font.italic: true
        font.family: "Calibri Light"
    }

    Text {
        id: text26
        x: 29
        y: 464
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("время наработки")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
        font.italic: true
        font.family: "Calibri Light"
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
