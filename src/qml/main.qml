import QtQuick 2.12
import QtQuick.Controls 2.12
import "qrc:/"
import "./PrimeboxQmlWidgets"

ApplicationWindow
{
    id: applicationWindow
    width: 460
    height: 700
    visible: true
    color: "#585858"
    maximumWidth: 460
    maximumHeight: 700
    minimumWidth: 460
    minimumHeight: 700
    title: qsTr("ONREMOTE+")

    Text {
        id: generalLabel1
        x: 49
        y: 22
        width: 363
        height: 45
        color: "#fefefe"
        text: "PRIMEBOX | ONREMOTE+"
        font.pixelSize: 28
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.weight: Font.Bold
        font.family: "Arial"
    }

    Text {
        id: generalLabel2
        x: 82
        y: 54
        width: 157
        height: 24
        color: "#fefefe"
        text: "by. TRUEDEVICE"
        font.pixelSize: 11
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Arial"
    }

    Row {
        id: switchFrameButtonsLayout
        y: 601
        height: 92
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0

        SwitchFrameButton {
            id: mainFrameButton
            text: "ГЛАВНАЯ"
            ButtonGroup.group: switchFrameButtons
        }

        SwitchFrameButton {
            id: controlsFrameButton
            text: "НАСТРОЙКИ"
            ButtonGroup.group: switchFrameButtons
        }

        SwitchFrameButton {
            id: pwswFrameButton
            text: "PWSW"
            ButtonGroup.group: switchFrameButtons
        }

        SwitchFrameButton {
            id: sensorsFrameButton
            text: "SENS"
            ButtonGroup.group: switchFrameButtons
        }

        SwitchFrameButton {
            id: helpFrameButton
            text: "ПОМОЩЬ"
            ButtonGroup.group: switchFrameButtons
        }

        ButtonGroup {
            id: switchFrameButtons
        }
    }
}
