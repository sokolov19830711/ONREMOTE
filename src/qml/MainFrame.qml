import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    width: 400
    height: 500

    Text {
        id: currentPwswLevelLabel
        x: 0
        y: 24
        width: 401
        height: 51
        color: "#fefefe"
        text: qsTr("ТЕКУЩИЙ УРОВЕНЬ ЗАЩИТЫ PWSW")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Arial"
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

        ButtonGroup.group: pwswButtons
    }

    Button {
        id: mediumPwswButton
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

        ButtonGroup.group: pwswButtons
    }

    Button {
        id: highPwswButton
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

        ButtonGroup.group: pwswButtons
    }

    Button {
        id: pwswOffButton
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

        ButtonGroup.group: pwswButtons
    }

    ButtonGroup {
        id: pwswButtons
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
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.weight: Font.Light
        font.family: "Arial"
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
        enabled: true
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
        id: lowPwswButton2
        x: 134
        y: 211
        width: 132
        height: 60
        text: qsTr("СРЕДНИЙ")
        checked: false
        checkable: true
        enabled: true
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
        id: lowPwswButton3
        x: 269
        y: 211
        width: 131
        height: 60
        text: qsTr("ВЫСОКИЙ")
        checked: false
        checkable: true
        enabled: true
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
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
