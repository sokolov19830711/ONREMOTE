import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Text {
        id: setPwswLevelLabel
        x: 20
        y: 120
        width: 361
        height: 30
        color: "#fefefe"
        text: qsTr("УПРАВЛЕНИЕ ПИТАНИЕМ (SW)")
        font.pixelSize: 22
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.weight: Font.Light
        minimumPixelSize: 16
    }

    OnOffButton {
        id: onOffButton
        x: 352
        y: 8
    }

    Text {
        id: text8
        x: 47
        y: 19
        width: 299
        height: 19
        color: "#fefefe"
        text: qsTr("ПЕРЕЗАГРУЗКА ПК ПРИ ЗАВИСАНИИ (HW)")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
        font.family: "Calibri Light"
    }

    MySpinBox {
        id: resetTimeSpinBox
        x: 284
        y: 61
    }

    Text {
        id: text9
        x: 141
        y: 61
        width: 137
        height: 19
        color: "#fefefe"
        text: qsTr("через сколько, если нет")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
        font.family: "Calibri Light"
    }

    Text {
        id: text10
        x: 141
        y: 80
        width: 137
        height: 19
        color: "#fefefe"
        text: qsTr("отклика (минут)")
        font.pixelSize: 16
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 10
        font.family: "Calibri Light"
    }

    Button {
        id: turnOffButton
        x: 142
        y: 156
        width: 120
        height: 50
        text: "ВЫКЛЮЧИТЬ"
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

        onClicked: osInteractionManager.shutdown()
    }

    Button {
        id: resetButton
        x: 13
        y: 156
        width: 120
        height: 50
        text: "ПЕРЕЗАГРУЗИТЬ"
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

        onClicked: osInteractionManager.reset()
    }

    Button {
        id: hyberButton
        x: 272
        y: 156
        width: 120
        height: 50
        text: "ГИБЕРНАЦИЯ"
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

        onClicked: osInteractionManager.hybernate()
    }

    Text {
        id: setPwswLevelLabel1
        x: 16
        y: 238
        width: 361
        height: 30
        color: "#fefefe"
        text: qsTr("УПРАВЛЕНИЕ ПИТАНИЕМ (HW)")
        font.pixelSize: 22
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.family: "Calibri Light"
        font.weight: Font.Light
    }

    Button {
        id: turnOffHwButton
        x: 206
        y: 274
        width: 120
        height: 50
        text: "ВЫКЛЮЧИТЬ"
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
    }

    Button {
        id: resetHwButton
        x: 77
        y: 274
        width: 120
        height: 50
        text: "ПЕРЕЗАГРУЗИТЬ"
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
    }

    //-------------------------------------------------------------------------------------------------
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
