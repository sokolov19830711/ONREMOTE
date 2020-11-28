import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Button {
        id: saveButton
        x: 27
        y: 394
        width: 125
        height: 40
        text: "СОХРАНИТЬ"
        font.pointSize: 10

        onClicked:
        {
            dataManager.setSettingsStringValue("SMTP/server", serverField.text);
            dataManager.setSettingsStringValue("SMTP/port", portField.text);
            dataManager.setSettingsStringValue("SMTP/user", userField.text);
            dataManager.setSettingsStringValue("SMTP/password", passwordField.text);
            dataManager.setSettingsStringValue("SMTP/recipient", recipientField.text);
            dataManager.setSettingsStringValue("SMTP/deviceName", deviceNameField.text);
        }

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
        x: 158
        y: 394
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("нажмите, чтобы")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        minimumPixelSize: 10
    }

    Text {
        id: text17
        x: 158
        y: 411
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("сохранить настройки")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        minimumPixelSize: 10
    }

    Text {
        id: text1
        x: 27
        y: 8
        width: 133
        height: 42
        color: "#fefefe"
        text: "СЕРВЕР"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        textFormat: Text.RichText
    }

    TextField {
        id: serverField
        x: 172
        y: 8
        width: 220
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        passwordMaskDelay: 300
        font.pointSize: 12
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: ""
        text: dataManager.getSettingsStringValue("SMTP/server")
    }

    Text {
        id: text2
        x: 212
        y: 47
        width: 180
        height: 23
        color: "#fefefe"
        text: "ПРИМЕР: smtp.mail.ru"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.italic: true
        font.family: "Calibri Light"
        textFormat: Text.RichText
    }

    Text {
        id: text3
        x: 27
        y: 76
        width: 133
        height: 42
        color: "#fefefe"
        text: "ПОРТ"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        textFormat: Text.RichText
    }

    TextField {
        id: portField
        x: 172
        y: 76
        width: 220
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        passwordMaskDelay: 300
        font.pointSize: 12
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: ""
        text: dataManager.getSettingsStringValue("SMTP/port")
    }

    Text {
        id: text4
        x: 270
        y: 116
        width: 122
        height: 22
        color: "#fefefe"
        text: "ПРИМЕР:465"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        textFormat: Text.RichText
    }

    Text {
        id: text5
        x: 27
        y: 144
        width: 133
        height: 42
        color: "#fefefe"
        text: "ПОЛЬЗОВАТЕЛЬ"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        textFormat: Text.RichText
    }

    TextField {
        id: userField
        x: 172
        y: 144
        width: 220
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        passwordMaskDelay: 300
        font.pointSize: 12
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: ""
        text: dataManager.getSettingsStringValue("SMTP/user")
    }

    Text {
        id: text6
        x: 27
        y: 192
        width: 133
        height: 42
        color: "#fefefe"
        text: "ПАРОЛЬ"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        textFormat: Text.RichText
    }

    TextField {
        id: passwordField
        x: 172
        y: 192
        width: 220
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        passwordMaskDelay: 300
        echoMode: TextInput.Password
        font.pointSize: 12
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: ""
        text: dataManager.getSettingsStringValue("SMTP/password")
    }

    Text {
        id: text7
        x: 27
        y: 240
        width: 133
        height: 42
        color: "#fefefe"
        text: "ПОЛУЧАТЕЛЬ"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        textFormat: Text.RichText
    }

    TextField {
        id: recipientField
        x: 172
        y: 240
        width: 220
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        passwordMaskDelay: 300
        font.pointSize: 12
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: ""
        text: dataManager.getSettingsStringValue("SMTP/recipient")
    }

    Text {
        id: text8
        x: 27
        y: 288
        width: 133
        height: 42
        color: "#fefefe"
        text: "ИМЯ УСТРОЙСТВА"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        textFormat: Text.RichText
    }

    TextField {
        id: deviceNameField
        x: 172
        y: 288
        width: 220
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        passwordMaskDelay: 300
        font.pointSize: 12
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: ""
        text: dataManager.getSettingsStringValue("SMTP/deviceName")
    }

    OnOffButton {
        id: sslButton
        x: 352
        y: 336
    }

    Text {
        id: text9
        x: 248
        y: 336
        width: 96
        height: 42
        color: "#fefefe"
        text: "SSL включено"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        textFormat: Text.RichText
    }

    Button {
        id: testButton
        x: 27
        y: 447
        width: 125
        height: 40
        text: "ТЕСТ"
        font.pointSize: 10
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
    }

    Text {
        id: text18
        x: 158
        y: 447
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("нажмите, чтобы отправить")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: true
    }

    Text {
        id: text19
        x: 158
        y: 464
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("тестовое сообщение")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: true
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
