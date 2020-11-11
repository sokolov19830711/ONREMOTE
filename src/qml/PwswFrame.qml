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
        y: 0
        width: 401
        height: 30
        color: "#fefefe"
        text: qsTr("УКАЖИТЕ УРОВЕНЬ ЗАЩИТЫ")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Arial"
        font.weight: Font.Light
        minimumPixelSize: 16
    }

    Button {
        id: setPwswLowButton
        x: 0
        y: 38
        width: 112
        height: 60
        text: qsTr("НИЗКИЙ")
        checked: dataManager.powerButtonPwdLevel() === 1
        enabled: true
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

        ButtonGroup.group: setPwswButtons
    }

    Button {
        id: setPwswMediumButton
        x: 115
        y: 38
        width: 112
        height: 60
        text: qsTr("СРЕДНИЙ")
        checked: dataManager.powerButtonPwdLevel() === 2
        enabled: true
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

        ButtonGroup.group: setPwswButtons
    }

    Button {
        id: setPwswHighButton
        x: 230
        y: 38
        width: 112
        height: 60
        text: qsTr("ВЫСОКИЙ")
        checked: dataManager.powerButtonPwdLevel() === 3
        enabled: true
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

        ButtonGroup.group: setPwswButtons
    }

    Button {
        id: setPwswOffButton
        x: 345
        y: 38
        width: 56
        height: 60
        text: qsTr("OFF")
        checked: dataManager.powerButtonPwdLevel() === 0
        enabled: true
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

        ButtonGroup.group: setPwswButtons
    }

    ButtonGroup {
        id: setPwswButtons

        onClicked: {
            if(button == setPwswLowButton) pwswFrame.currentPwswLevel = 1;
            else if(button == setPwswMediumButton) pwswFrame.currentPwswLevel = 2;
            else if(button == setPwswHighButton) pwswFrame.currentPwswLevel = 3;
            else pwswFrame.currentPwswLevel = 0;
        }
    }

    //-------------------------------------------------------------------------------------------------
    MySpinBox {
        id: digitInputPeriodSpinBox
        x: 292
        y: 113

        currentValue: dataManager.digitInputPeriod()

        onCurrentValueChanged: dataManager.setDigitInputPeriod(currentValue)
    }

    MySpinBox {
        id: wrongKeyUsageForPowerOffSpinBox
        x: 292
        y: 159
    }

    MySpinBox {
        id: blockingPeriodSpinBox
        x: 292
        y: 205
    }

    Text {
        id: text1
        x: 92
        y: 115
        width: 196
        height: 14
        color: "#fefefe"
        text: qsTr("ВРЕМЯ ОЖИДАНИЯ КОМБИНАЦИЙ")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
    }

    Text {
        id: text2
        x: 230
        y: 135
        width: 58
        height: 14
        color: "#eccc4a"
        text: qsTr("(секунд)")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
    }

    Text {
        id: text3
        x: 59
        y: 163
        width: 229
        height: 14
        color: "#fefefe"
        text: qsTr("ДОПУСТИМОЕ КОЛИЧЕСТВО НЕВЕРНЫХ")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
    }

    Text {
        id: text4
        x: 208
        y: 183
        width: 80
        height: 14
        color: "#eccc4a"
        text: qsTr("(раз подряд)")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
    }

    Text {
        id: text5
        x: 128
        y: 184
        width: 83
        height: 14
        color: "#fefefe"
        text: qsTr("КОМБИНАЦИЙ")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
    }

    Text {
        id: text6
        x: 92
        y: 208
        width: 196
        height: 14
        color: "#fefefe"
        text: qsTr("БЛОКИРОВАТЬ ПОСЛЕ НЕВЕРНЫХ")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
    }

    Text {
        id: text7
        x: 239
        y: 228
        width: 49
        height: 14
        color: "#eccc4a"
        text: qsTr("(минут)")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
    }

    Text {
        id: text8
        x: 156
        y: 229
        width: 83
        height: 14
        color: "#fefefe"
        text: qsTr("КОМБИНАЦИЙ")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
    }

    Text {
        id: setPwswLevelLabel1
        x: 0
        y: 262
        width: 401
        height: 30
        color: "#fefefe"
        text: qsTr("ВЫБЕРИТЕ ЧИСЛО КОМБИНАЦИИ")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.weight: Font.Light
        font.family: "Arial"
        minimumPixelSize: 16
    }

    DigitValueWidget {
        id: digitValueWidget1
        x: 5
        y: 305
        currentValue: dataManager.powerButtonPwdDigit1()

        onCurrentValueChanged: dataManager.setPowerButtonPwdDigit1(currentValue)
    }

    DigitValueWidget {
        id: digitValueWidget2
        x: 145
        y: 304
        currentValue: dataManager.powerButtonPwdDigit2()
        onCurrentValueChanged: dataManager.setPowerButtonPwdDigit2(currentValue)
    }

    DigitValueWidget {
        id: digitValueWidget3
        x: 283
        y: 304
        currentValue: dataManager.powerButtonPwdDigit3()

        onCurrentValueChanged: dataManager.setPowerButtonPwdDigit3(currentValue)
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
