import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Text {
        id: setPwswLevelLabel
        x: 0
        y: 62
        width: 231
        height: 30
        color: "#fefefe"
        text: qsTr("ЕСЛИ ТЕМПЕРАТУРА")
        font.pixelSize: 21
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.family: "Calibri"
        font.weight: Font.Normal
        minimumPixelSize: 16
    }

    MySpinBox {
        id: minTemperatureSpinBox
        x: 0
        y: 98
        valueFieldColor: "#808080"
        currentValue: dataManager.getSettingsValue("temperatureMinValue")
        onCurrentValueChanged: dataManager.setSettingsValue("temperatureMinValue", currentValue)
    }

    Button {
        id: temperatureValueButton
        x: 120
        y: 98
        width: 40
        height: 40
        topPadding: 4
        leftPadding: 4
        rightPadding: 4
        bottomPadding: 4
        text: "0"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        checkable: true
        layer.enabled: false
        font.pointSize: 14
        enabled: false

        background: Rectangle {
            color: parent.checked ? "#c05046" : "#00be94"
        }  
    }

    MySpinBox {
        id: maxTemperatureSpinBox
        x: 170
        y: 98
        valueFieldColor: "#808080"
        currentValue: dataManager.getSettingsValue("temperatureMaxValue")
        onCurrentValueChanged: dataManager.setSettingsValue("temperatureMaxValue", currentValue)
    }

    OnOffButton {
        id: shutdownButton1
        x: 309
        y: 98
        width: 40
        height: 40

        checked: dataManager.getSettingsValue("temperatureFlag_pcShutdown")
        onCheckedChanged: dataManager.setSettingsValue("temperatureFlag_pcShutdown", checked)
    }

    OnOffButton {
        id: notificationButton1
        x: 360
        y: 98

        checked: dataManager.getSettingsValue("temperatureFlag_notification")
        onCheckedChanged: dataManager.setSettingsValue("temperatureFlag_notification", checked)
    }

    Text {
        id: setPwswLevelLabel1
        x: 278
        y: 35
        rotation: -90
        width: 85
        height: 30
        color: "#fefefe"
        text: qsTr("ВЫКЛЮЧИТЬ ПК")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.bold: false
        font.family: "Calibri Light"
        font.weight: Font.Normal
    }

    Text {
        id: setPwswLevelLabel2
        x: 293
        y: 34
        width: 85
        height: 30
        color: "#fefefe"
        text: qsTr("(HW)")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        rotation: -90
        font.bold: false
        font.family: "Calibri Light"
        font.weight: Font.Normal
    }

    Text {
        id: setPwswLevelLabel3
        x: 328
        y: 37
        width: 85
        height: 30
        color: "#fefefe"
        text: qsTr("ОТПРАВИТЬ SMTP")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        rotation: -90
        font.bold: false
        font.family: "Calibri Light"
        font.weight: Font.Normal
    }

    Text {
        id: setPwswLevelLabel4
        x: 343
        y: 36
        width: 85
        height: 30
        color: "#fefefe"
        text: qsTr("(SW)")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        rotation: -90
        font.bold: false
        font.family: "Calibri Light"
        font.weight: Font.Normal
    }

    Text {
        id: setPwswLevelLabel5
        x: 0
        y: 165
        width: 287
        height: 30
        color: "#fefefe"
        text: qsTr("ЕСЛИ ДАТЧИК ВСРЫТИЯ (INT)")
        font.pixelSize: 21
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.bold: true
        font.family: "Calibri"
        font.weight: Font.Normal
    }

    ButtonGroup {
        id: intButtons
        onClicked:
        {
            if (button == intOnButton)
            {
                dataManager.setSettingsValue("breakInSensorNormalState1", 1)
            }
            else
            {
                dataManager.setSettingsValue("breakInSensorNormalState1", 0)
            }
        }
    }

    Button {
        id: intOnButton
        x: 0
        y: 201
        width: 108
        height: 40
        text: "ОТКРЫТ"
        enabled: true
        checkable: true
        checked: dataManager.getSettingsValue("breakInSensorNormalState1") === 1

        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }
        rightPadding: 4
        bottomPadding: 4
        font.pointSize: 14
        layer.enabled: false
        background: Rectangle {
            color: parent.checked ? "#c05046" : "#636363"
        }
        topPadding: 4
        leftPadding: 4

        ButtonGroup.group: intButtons
    }

    Text {
        id: setPwswLevelLabel6
        x: 115
        y: 206
        width: 46
        height: 30
        color: "#fefefe"
        text: qsTr("ИЛИ")
        font.pixelSize: 18
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.bold: false
        font.family: "Calibri"
        font.weight: Font.Normal
    }

    Button {
        id: intOffButton
        x: 170
        y: 201
        width: 108
        height: 40
        text: "ЗАКРЫТ"
        checkable: true
        checked: dataManager.getSettingsValue("breakInSensorNormalState1") !== 1

        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }
        rightPadding: 4
        layer.enabled: false
        font.pointSize: 14
        enabled: true
        bottomPadding: 4
        background: Rectangle {
            color: parent.checked ? "#c05046" : "#636363"
        }
        topPadding: 4
        Connections {
            target: dataManager
        }
        leftPadding: 4

        ButtonGroup.group: intButtons
    }

    OnOffButton {
        id: shutdownButton2
        x: 309
        y: 201
        width: 40
        height: 40

        checked: dataManager.getSettingsValue("breakInFlag_pcShutdown1")
        onCheckedChanged: dataManager.setSettingsValue("breakInFlag_pcShutdown1", checked)
    }

    OnOffButton {
        id: notificationButton2
        x: 360
        y: 201

        checked: dataManager.getSettingsValue("breakInFlag_notification1")
        onCheckedChanged: dataManager.setSettingsValue("breakInFlag_notification1", checked)
    }

    Text {
        id: setPwswLevelLabel7
        x: 0
        y: 262
        width: 287
        height: 30
        color: "#fefefe"
        text: qsTr("ЕСЛИ ДАТЧИК ВСРЫТИЯ (OUT)")
        font.pixelSize: 21
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.bold: true
        font.family: "Calibri"
        font.weight: Font.Normal
    }

    ButtonGroup {
        id: outButtons
        onClicked:
        {
            if (button == outOnButton)
            {
                dataManager.setSettingsValue("breakInSensorNormalState2", 1)
            }
            else
            {
                dataManager.setSettingsValue("breakInSensorNormalState2", 0)
            }
        }
    }

    Button {
        id: outOnButton
        x: 0
        y: 298
        width: 108
        height: 40
        text: "ОТКРЫТ"
        checkable: true
        checked: dataManager.getSettingsValue("breakInSensorNormalState2") === 1

        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }
        rightPadding: 4
        layer.enabled: false
        font.pointSize: 14
        bottomPadding: 4
        enabled: true
        background: Rectangle {
            color: parent.checked ? "#c05046" : "#636363"
        }
        topPadding: 4
        Connections {
            target: dataManager
        }
        leftPadding: 4

        ButtonGroup.group: outButtons
    }

    Text {
        id: setPwswLevelLabel8
        x: 115
        y: 303
        width: 46
        height: 30
        color: "#fefefe"
        text: qsTr("ИЛИ")
        font.pixelSize: 18
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.bold: false
        font.family: "Calibri"
        font.weight: Font.Normal
    }

    Button {
        id: outOffButton
        x: 170
        y: 298
        width: 108
        height: 40
        text: "ЗАКРЫТ"
        checkable: true
        checked: dataManager.getSettingsValue("breakInSensorNormalState2") === 0

        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }
        rightPadding: 4
        bottomPadding: 4
        font.pointSize: 14
        layer.enabled: false
        enabled: true
        background: Rectangle {
            color: parent.checked ? "#c05046" : "#636363"
        }
        topPadding: 4
        Connections {
            target: dataManager
        }
        leftPadding: 4

        ButtonGroup.group: outButtons
    }

    OnOffButton {
        id: shutdownButton3
        x: 309
        y: 298
        width: 40
        height: 40

        checked: dataManager.getSettingsValue("breakInFlag_pcShutdown2")
        onCheckedChanged: dataManager.setSettingsValue("breakInFlag_pcShutdown2", checked)
    }

    OnOffButton {
        id: notificationButton3
        x: 360
        y: 298

        checked: dataManager.getSettingsValue("breakInFlag_notification2")
        onCheckedChanged: dataManager.setSettingsValue("breakInFlag_notification2", checked)
    }

    Text {
        id: setPwswLevelLabel9
        x: 0
        y: 359
        width: 287
        height: 30
        color: "#fefefe"
        text: qsTr("ЕСЛИ ДАТЧИК ПЫЛИ")
        font.pixelSize: 21
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.bold: true
        font.family: "Calibri"
        font.weight: Font.Normal
    }

    Button {
        id: dustButton
        x: 0
        y: 395
        width: 90
        height: 40
        text: "НИЗКИЙ"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
        }
        rightPadding: 4
        checkable: true
        enabled: true
        bottomPadding: 4
        font.pointSize: 14
        layer.enabled: false
        background: Rectangle {
            color: "#636363"
        }
        topPadding: 4
        Connections {
            target: dataManager
        }
        leftPadding: 4
    }

    OnOffButton {
        id: shutdownButton4
        x: 309
        y: 395
        width: 40
        height: 40

        checked: dataManager.getSettingsValue("dustFlag_pcShutdown")
        onCheckedChanged: dataManager.setSettingsValue("dustFlag_pcShutdown", checked)
    }

    OnOffButton {
        id: notificationButton4
        x: 360
        y: 395

        checked: dataManager.getSettingsValue("dustFlag_notification")
        onCheckedChanged: dataManager.setSettingsValue("dustFlag_notification", checked)
    }

    Button {
        id: dustButton1
        x: 94
        y: 395
        width: 90
        height: 40
        text: "УМЕРЕННЫЙ"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
        }
        rightPadding: 4
        checkable: true
        layer.enabled: false
        font.pointSize: 14
        bottomPadding: 4
        enabled: true
        background: Rectangle {
            color: "#636363"
        }
        topPadding: 4
        Connections {
            target: dataManager
        }
        leftPadding: 4
    }

    Button {
        id: dustButton2
        x: 188
        y: 395
        width: 90
        height: 40
        text: "ВЫСОКИЙ"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
        }
        rightPadding: 4
        checkable: true
        layer.enabled: false
        font.pointSize: 14
        bottomPadding: 4
        enabled: true
        background: Rectangle {
            color: "#c05046"
        }
        topPadding: 4
        Connections {
            target: dataManager
        }
        leftPadding: 4
    }

    //-------------------------------------------------------------------------------------------------

    function update()
    {
        var currentTempereture = dataManager.getMcuValue("temperatureSensor");
        temperatureValueButton.text = currentTempereture;
        if(currentTempereture < minTemperatureSpinBox.currentValue || currentTempereture > maxTemperatureSpinBox.currentValue)
        {
            temperatureValueButton.checked = true;
        }
        else
        {
            temperatureValueButton.checked = false;
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
