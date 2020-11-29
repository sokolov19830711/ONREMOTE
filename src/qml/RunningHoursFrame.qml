import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Text {
        id: text16
        x: 8
        y: 24
        width: 310
        height: 19
        color: "#fefefe"
        text: qsTr("НАРАБОТКА (HW) ОБЩЕЕ ВРЕМЯ")
        font.pixelSize: 19
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: false
        minimumPixelSize: 10
    }

    TextField {
        id: totalRunningField
        x: 8
        y: 55
        width: 228
        height: 40
        enabled: false
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        passwordMaskDelay: 300
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00 ч 00 мин 00 сек"
    }

    Button {
        id: resetTotalHwButton
        x: 249
        y: 55
        width: 132
        height: 40
        text: "СБРОСИТЬ"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        font.pointSize: 10
        background: Rectangle {
            color: parent.pressed ? "#166999" : "#30859B"
        }

        onClicked:
        {
            totalHwHoursNotification.text = ""
            totalHwMinutesNotification.text = ""
            totalHwSecondsNotification.text = ""
        }
    }

    Text {
        id: text17
        x: 0
        y: 102
        width: 236
        height: 19
        color: "#fefefe"
        text: qsTr("Напомнить SMTP при достижении")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: false
    }

    Text {
        id: text18
        x: 0
        y: 120
        width: 236
        height: 19
        color: "#fefefe"
        text: qsTr("(часов, минут, секунд)")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: false
    }

    Text {
        id: text19
        x: 71
        y: 188
        width: 310
        height: 19
        color: "#fefefe"
        text: qsTr("НАРАБОТКА (HW) ТЕКУЩИЙ СЕАНС")
        font.pixelSize: 19
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: false
    }

    TextField {
        id: sessionRunningField
        x: 153
        y: 220
        width: 228
        height: 40
        enabled: false
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        passwordMaskDelay: 300
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00 ч 00 мин 00 сек"
    }

    Button {
        id: resetSessionHwButton
        x: 8
        y: 221
        width: 132
        height: 40
        text: "СБРОСИТЬ"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        font.pointSize: 10
        background: Rectangle {
            color: parent.pressed ? "#166999" : "#30859B"
        }

        onClicked:
        {
            sessionHwHoursNotification.text = ""
            sessionHwMinutesNotification.text = ""
            sessionHwSecondsNotification.text = ""
        }
    }

    Text {
        id: text20
        x: 149
        y: 267
        width: 236
        height: 19
        color: "#fefefe"
        text: qsTr("Напомнить SMTP при достижении")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: false
    }

    Text {
        id: text21
        x: 149
        y: 285
        width: 236
        height: 19
        color: "#fefefe"
        text: qsTr("(часов, минут, секунд)")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: false
    }

    Text {
        id: text22
        x: 8
        y: 352
        width: 310
        height: 19
        color: "#fefefe"
        text: qsTr("НАРАБОТКА (SW) ОБЩЕЕ ВРЕМЯ")
        font.pixelSize: 19
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: false
    }

    TextField {
        id: swTotalRunningField
        x: 8
        y: 383
        width: 228
        height: 40
        enabled: false
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        passwordMaskDelay: 300
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00 ч 00 мин 00 сек"
    }

    Button {
        id: resetTotalSwButton
        x: 249
        y: 383
        width: 132
        height: 40
        text: "СБРОСИТЬ"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        font.pointSize: 10
        background: Rectangle {
            color: parent.pressed ? "#166999" : "#30859B"
        }

        onClicked:
        {
            totalSwHoursNotification.text = ""
            totalSwMinutesNotification.text = ""
            totalSwSecondsNotification.text = ""
        }
    }

    Text {
        id: text23
        x: 0
        y: 430
        width: 236
        height: 19
        color: "#fefefe"
        text: qsTr("Напомнить SMTP при достижении")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: false
    }

    Text {
        id: text24
        x: 0
        y: 448
        width: 236
        height: 19
        color: "#fefefe"
        text: qsTr("(часов, минут, секунд)")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
        font.italic: false
    }

    TextField {
        id: totalHwHoursNotification
        x: 249
        y: 101
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        leftPadding: 6
        font.pointSize: 15
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        validator: RegExpValidator{regExp: /^[0-9]+$/}
        text: dataManager.getSettingsStringValue("totalHwHoursNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("totalHwHoursNotification", text)
            if(text === "0") text = ""
        }
    }

    TextField {
        id: totalHwMinutesNotification
        x: 295
        y: 101
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        leftPadding: 6
        validator: RegExpValidator {
            regExp: /^[0-9]+$/
        }
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        text: dataManager.getSettingsStringValue("totalHwMinutesNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("totalHwMinutesNotification", text)
            if(text === "0") text = ""
        }
    }

    TextField {
        id: totalHwSecondsNotification
        x: 341
        y: 101
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        leftPadding: 6
        validator: RegExpValidator {
            regExp: /^[0-9]+$/
        }
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        text: dataManager.getSettingsStringValue("totalHwSecondsNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("totalHwSecondsNotification", text)
            if(text === "0") text = ""
        }
    }

    TextField {
        id: sessionHwHoursNotification
        x: 8
        y: 267
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        leftPadding: 6
        validator: RegExpValidator {
            regExp: /^[0-9]+$/
        }
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        text: dataManager.getSettingsStringValue("sessionHwHoursNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("sessionHwHoursNotification", text)
            if(text === "0") text = ""
        }
    }

    TextField {
        id: sessionHwMinutesNotification
        x: 54
        y: 267
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        leftPadding: 6
        validator: RegExpValidator {
            regExp: /^[0-9]+$/
        }
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        text: dataManager.getSettingsStringValue("sessionHwMinutesNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("sessionHwMinutesNotification", text)
            if(text === "0") text = ""
        }
    }

    TextField {
        id: sessionHwSecondsNotification
        x: 100
        y: 267
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        leftPadding: 6
        validator: RegExpValidator {
            regExp: /^[0-9]+$/
        }
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        text: dataManager.getSettingsStringValue("sessionHwSecondsNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("sessionHwSecondsNotification", text)
            if(text === "0") text = ""
        }
    }

    TextField {
        id: totalSwHoursNotification
        x: 249
        y: 430
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        leftPadding: 6
        validator: RegExpValidator {
            regExp: /^[0-9]+$/
        }
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        text: dataManager.getSettingsStringValue("totalSwHoursNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("totalSwHoursNotification", text)
            if(text === "0") text = ""
        }
    }

    TextField {
        id: totalSwMinutesNotification
        x: 295
        y: 430
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        leftPadding: 6
        validator: RegExpValidator {
            regExp: /^[0-9]+$/
        }
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        text: dataManager.getSettingsStringValue("totalSwMinutesNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("totalSwMinutesNotification", text)
            if(text === "0") text = ""
        }
    }

    TextField {
        id: totalSwSecondsNotification
        x: 341
        y: 430
        width: 40
        height: 40
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        leftPadding: 6
        validator: RegExpValidator {
            regExp: /^[0-9]+$/
        }
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: "00"
        text: dataManager.getSettingsStringValue("totalSwSecondsNotification")
        onTextChanged:
        {
            dataManager.setSettingsStringValue("totalSwSecondsNotification", text)
            if(text === "0") text = ""
        }
    }

    function update()
    {
        totalRunningField.text = dataManager.getDeviceTotalTime()
        sessionRunningField.text = dataManager.getDeviceSessionTime()
        swTotalRunningField.text = dataManager.getPcTotalTime()
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
