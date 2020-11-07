import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    property int currentPwswLevel: 0

    Text {
        id: setPwswLevelLabel
        x: 0
        y: 24
        width: 401
        height: 51
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
        y: 82
        width: 112
        height: 60
        text: qsTr("НИЗКИЙ")
        checked: false
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
        y: 82
        width: 112
        height: 60
        text: qsTr("СРЕДНИЙ")
        checked: false
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
        y: 82
        width: 112
        height: 60
        text: qsTr("ВЫСОКИЙ")
        checked: false
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
        y: 82
        width: 56
        height: 60
        text: qsTr("OFF")
        checked: false
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
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}D{i:1}
}
##^##*/
