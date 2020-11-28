import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    property int currentPwswLevel: 0

    onCurrentPwswLevelChanged: dataManager.setPowerButtonPwdLevel(currentPwswLevel)

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
        currentValue: dataManager.temperatureMinValue()

        onCurrentValueChanged: dataManager.setValue("temperatureMinValue", currentValue)
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

        function checkTemperatureState()
        {
            if((dataManager.getMcuValue("temperature") < minTemperatureSpinBox.currentValue) || (dataManager.getMcuValue("temperature") > maxTemperatureSpinBox.currentValue))
            {
                temperatureValueButton.checked = true;
            }
            else
            {
                temperatureValueButton.checked = false;
            }
        }

        Connections {
            target: dataManager
            function onTemperatureValueChanged(value)
            {
                temperatureValueButton.text = dataManager.getMcuValue("temperature");
                temperatureValueButton.checkTemperatureState();
            }
        }

        Connections {
            target: minTemperatureSpinBox
            function onCurrentValueChanged()
            {
                temperatureValueButton.checkTemperatureState();
            }
        }

        Connections {
            target: maxTemperatureSpinBox
            function onCurrentValueChanged()
            {
                temperatureValueButton.checkTemperatureState();
            }
        }

    }

    MySpinBox {
        id: maxTemperatureSpinBox
        x: 170
        y: 98
        valueFieldColor: "#808080"
        currentValue: dataManager.temperatureMaxValue()

        onCurrentValueChanged: dataManager.setValue("temperatureMaxValue", currentValue)
    }

    OnOffButton {
        id: onOffButton
        x: 309
        y: 98
        width: 40
        height: 40
    }

    OnOffButton {
        id: onOffButton1
        x: 360
        y: 98
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
    }

    Button {
        id: intOnButton
        x: 0
        y: 201
        width: 108
        height: 40
        text: "ОТКРЫТ"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }
        rightPadding: 4
        checkable: true
        bottomPadding: 4
        enabled: true
        font.pointSize: 14
        layer.enabled: false
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
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }
        rightPadding: 4
        checkable: true
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
        id: onOffButton2
        x: 309
        y: 201
        width: 40
        height: 40
    }

    OnOffButton {
        id: onOffButton3
        x: 360
        y: 201
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
    }

    Button {
        id: outOnButton
        x: 0
        y: 298
        width: 108
        height: 40
        text: "ОТКРЫТ"
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }
        rightPadding: 4
        checkable: true
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
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 12
        }
        rightPadding: 4
        checkable: true
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
        id: onOffButton4
        x: 309
        y: 298
        width: 40
        height: 40
    }

    OnOffButton {
        id: onOffButton5
        x: 360
        y: 298
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
        id: onOffButton6
        x: 309
        y: 395
        width: 40
        height: 40
    }

    OnOffButton {
        id: onOffButton7
        x: 360
        y: 395
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
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
