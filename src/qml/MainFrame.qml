import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Text {
        id: currentPwswLevelLabel
        x: 0
        y: 8
        width: 401
        height: 51
        color: "#fefefe"
        text: qsTr("ТЕКУЩИЙ УРОВЕНЬ ЗАЩИТЫ PWSW")
        font.pixelSize: 22
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.family: "Calibri Light"
        font.weight: Font.Light
        minimumPixelSize: 16
    }

    Button {
        id: lowPwswButton
        x: 0
        y: 66
        width: 112
        height: 60
        text: qsTr("НИЗКИЙ")
        enabled: false
        checkable: true
        font.pointSize: 13

        background: Rectangle {
                color: parent.checked ? "#c05046" : "#636363"
            }

        contentItem: Text {
                color: "#fefefe"
                text: parent.text
                font: parent.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
        }

        ButtonGroup.group: pwswButtons
    }

    Button {
        id: mediumPwswButton
        x: 115
        y: 66
        width: 112
        height: 60
        text: qsTr("СРЕДНИЙ")
        enabled: false
        checkable: true
        font.pointSize: 13

        background: Rectangle {
                color: parent.checked ? "#cea400" : "#636363"
            }

        contentItem: Text {
                color: "#fefefe"
                text: parent.text
                font: parent.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
        }

        ButtonGroup.group: pwswButtons
    }

    Button {
        id: highPwswButton
        x: 230
        y: 66
        width: 112
        height: 60
        text: qsTr("ВЫСОКИЙ")
        enabled: false
        checkable: true
        font.pointSize: 13

        background: Rectangle {
                color: parent.checked ? "#00be94" : "#636363"
            }

        contentItem: Text {
                color: "#fefefe"
                text: parent.text
                font: parent.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
        }

        ButtonGroup.group: pwswButtons
    }

    Button {
        id: pwswOffButton
        x: 345
        y: 66
        width: 56
        height: 60
        text: qsTr("OFF")
        enabled: false
        checkable: true
        font.pointSize: 13

        background: Rectangle {
            color: parent.checked ? "#c05046" : "#636363"
        }

        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            font: parent.font
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        ButtonGroup.group: pwswButtons
    }

    ButtonGroup {
        id: pwswButtons
    }

//----------------------------------------------------------------------------------------------
    Text {
        id: currentDustinessLevelLabel
        x: 0
        y: 136
        width: 401
        height: 51
        color: "#fefefe"
        text: qsTr("ТЕКУЩИЙ УРОВЕНЬ ЗАПЫЛЕННОСТИ")
        font.pixelSize: 22
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        minimumPixelSize: 16
        font.weight: Font.Light
        font.family: "Calibri Light"
    }

    Button {
        id: lowDustinessButton
        x: 0
        y: 195
        width: 131
        height: 60
        text: qsTr("НИЗКИЙ")
        checked: false
        checkable: true
        enabled: false

        background: Rectangle {
            color: parent.checked ? "#00be94" : "#636363"
        }
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        font.pointSize: 13

        ButtonGroup.group: dustinessButtons
    }

    Button {
        id: mediumDustinessButton
        x: 134
        y: 195
        width: 132
        height: 60
        text: qsTr("СРЕДНИЙ")
        checked: false
        checkable: true
        enabled: false

        background: Rectangle {
            color: parent.checked ? "#cea400" : "#636363"
        }
        contentItem: Text {
            color: "#fefefe"
            text: "УМЕРЕННЫЙ"
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        font.pointSize: 13

        ButtonGroup.group: dustinessButtons
    }

    Button {
        id: highDustinessButton
        x: 269
        y: 195
        width: 131
        height: 60
        text: qsTr("ВЫСОКИЙ")
        checked: false
        checkable: true
        enabled: false

        background: Rectangle {
            color: parent.checked ? "#c05046" : "#636363"
        }
        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        font.pointSize: 13

        ButtonGroup.group: dustinessButtons
    }

    ButtonGroup {
        id: dustinessButtons
    }

    //-------------------------------------------------------------------------------

    Button {
        id: temperatureButton
        x: 181
        y: 271
        text: "0"
        width: 40
        height: 40
        layer.enabled: false
        font.pointSize: 12
        checkable: true
        enabled: false

        bottomPadding: 4
        topPadding: 4
        rightPadding: 4
        leftPadding: 4

        background: Rectangle {
            color: parent.checked ? "#c05046" : "#00be94"
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
        id: text1
        x: 59
        y: 271
        width: 127
        height: 40
        color: "#fefefe"
        text: qsTr("ТЕМПЕРАТУРА")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
    }

    Button {
        id: breakInButton1
        x: 181
        y: 317
        width: 40
        height: 40
        text: "txt"
        enabled: false

        contentItem: Text {
            color: "#fefefe"
            text: parent.checked ? "!!!" : "OK"
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        topPadding: 4
        background: Rectangle {
            color: parent.checked ? "#ea6f0d" : "#00be94"
        }
        font.pointSize: 12
        rightPadding: 4
        leftPadding: 4
        layer.enabled: false
        checkable: true
        bottomPadding: 4
    }

    Text {
        id: text2
        x: 225
        y: 317
        width: 89
        height: 40
        color: "#fefefe"
        text: qsTr("ВСКРЫТИЕ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
    }

    Text {
        id: text3
        x: 91
        y: 317
        width: 89
        height: 22
        color: "#fefefe"
        text: "встроенный"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text4
        x: 123
        y: 335
        width: 56
        height: 22
        color: "#fefefe"
        text: "датчик"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Button {
        id: breakInButton2
        x: 181
        y: 363
        width: 40
        height: 40
        text: "txt"
        enabled: false

        contentItem: Text {
            color: "#fefefe"
            text: parent.checked ? "!!!" : "OK"
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        topPadding: 4
        background: Rectangle {
            color: parent.checked ? "#ea6f0d" : "#00be94"
        }
        leftPadding: 4
        rightPadding: 4
        font.pointSize: 12
        checkable: true
        layer.enabled: false
        bottomPadding: 4
    }

    Text {
        id: text5
        x: 89
        y: 363
        width: 89
        height: 40
        color: "#fefefe"
        text: qsTr("ВСКРЫТИЕ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
    }

    Text {
        id: text6
        x: 224
        y: 362
        width: 75
        height: 22
        color: "#fefefe"
        text: "выносной"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text7
        x: 224
        y: 379
        width: 56
        height: 22
        color: "#fefefe"
        text: "датчик"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    OnOffButton {
        id: ledButton
        x: 181
        y: 409
        enabled: false
    }

    Text {
        id: text8
        x: 224
        y: 409
        width: 133
        height: 40
        color: "#fefefe"
        text: qsTr("ИНДИКАЦИЯ LED")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
    }

    Text {
        id: text9
        x: 40
        y: 408
        width: 133
        height: 20
        color: "#fefefe"
        text: qsTr("встроенный и")
        font.pixelSize: 14
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text10
        x: 15
        y: 427
        width: 159
        height: 20
        color: "#fefefe"
        text: qsTr("выносной светодиод")
        font.pixelSize: 14
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    OnOffButton {
        id: linkButton
        x: 181
        y: 455
        text: "Текст кнопки"
        enabled: false
    }

    Text {
        id: text11
        x: 83
        y: 455
        width: 89
        height: 40
        color: "#fefefe"
        text: qsTr("СВЯЗЬ")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
    }

    Text {
        id: text12
        x: 227
        y: 453
        width: 96
        height: 22
        color: "#fefefe"
        text: "наличие связи"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    Text {
        id: text13
        x: 227
        y: 470
        width: 90
        height: 22
        color: "#fefefe"
        text: "с устройством"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        minimumPixelSize: 10
    }

    function update()
    {
        var currentPwswLevel = dataManager.getSettingsValue("PWR/powerButtonPwdLevel");
        switch (currentPwswLevel)
        {
        case 1:
            lowPwswButton.checked = true;
            break;
        case 2:
            mediumPwswButton.checked = true;
            break;
        case 3:
            highPwswButton.checked = true;
            break;
        case 0:
            pwswOffButton.checked = true;
            break;
        }
        //----------------------------------------------------------

        var dustinessValue = dataManager.getMcuValue("dustSensor");
        if(dustinessValue < 40)
        {
            lowDustinessButton.checked = true
        }

        else if (dustinessValue < 60)
        {
            mediumDustinessButton.checked = true
        }

        else
        {
            highDustinessButton.checked = true
        }

        //--------------------------------------------

        temperatureButton.text = dataManager.getMcuValue("temperatureSensor");

        if((dataManager.getMcuValue("temperatureSensor") < dataManager.getSettingsValue("temperatureMinValue")) || (dataManager.getMcuValue("temperatureSensor") > dataManager.getSettingsValue("temperatureMaxValue")))
        {
            temperatureButton.checked = true;
        }
        else
        {
            temperatureButton.checked = false;
        }

        //-----------------------------------------------

        breakInButton1.checked = (dataManager.getMcuValue("breakInSensor1") !== dataManager.getSettingsValue("breakInSensorNormalState1"))
        breakInButton2.checked = (dataManager.getMcuValue("breakInSensor2") !== dataManager.getSettingsValue("breakInSensorNormalState2"))
        ledButton.checked = dataManager.getSettingsValue("ledOn")
        linkButton.checked = portManager.isConnected()
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
