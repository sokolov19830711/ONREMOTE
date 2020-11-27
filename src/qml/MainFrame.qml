import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    property int currentPwswLevel: 0
    property bool ledActive: false

    Text {
        id: currentPwswLevelLabel
        x: 0
        y: 24
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
        y: 82
        width: 112
        height: 60
        text: qsTr("НИЗКИЙ")
        checked: dataManager.powerButtonPwdLevel() === 1
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
        y: 82
        width: 112
        height: 60
        text: qsTr("СРЕДНИЙ")
        checked: dataManager.powerButtonPwdLevel() === 2
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
        y: 82
        width: 112
        height: 60
        text: qsTr("ВЫСОКИЙ")
        checked: dataManager.powerButtonPwdLevel() === 3
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
        y: 82
        width: 56
        height: 60
        text: qsTr("OFF")
        checked: dataManager.powerButtonPwdLevel() === 0
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

    onCurrentPwswLevelChanged: {
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
    }

//----------------------------------------------------------------------------------------------
    Text {
        id: currentDustinessLevelLabel
        x: 0
        y: 152
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
        y: 211
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
        y: 211
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
        y: 211
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
        x: 180
        y: 302
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

        Connections {
            target: dataManager
            function onTemperatureValueChanged(value) {temperatureButton.text = value}
        }

    }

    Text {
        id: text1
        x: 58
        y: 302
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
        x: 180
        y: 348
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

        Connections {
            target: dataManager
            function onBreakIn1ValueChanged(value) {breakInButton1.checked = !value}
        }
    }

    Text {
        id: text2
        x: 224
        y: 348
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
        x: 90
        y: 348
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
        x: 122
        y: 366
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
        x: 180
        y: 394
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

        Connections {
            target: dataManager
            function onBreakIn2ValueChanged(value) {breakInButton2.checked = value}
        }
    }

    Text {
        id: text5
        x: 88
        y: 394
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
        x: 223
        y: 393
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
        x: 223
        y: 410
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
        x: 180
        y: 440
        enabled: false
        checked: dataManager.isLedActive()

        Connections {
            target: dataManager
            function onLedActiveChanged(state) {ledButton.checked = state}
        }
    }

    Text {
        id: text8
        x: 223
        y: 440
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
        x: 39
        y: 439
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
        x: 14
        y: 458
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

    onLedActiveChanged: ledButton.checked = ledActive

    Connections {
        target: dataManager
        function onDustinessValueChanged(value)
        {
            if(value < 40)
            {
                lowDustinessButton.checked = true
            }

            else if (value < 60)
            {
                mediumDustinessButton.checked = true
            }

            else
            {
                highDustinessButton.checked = true
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
