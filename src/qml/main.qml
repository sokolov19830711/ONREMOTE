import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15
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

    Item {
        id: switchFrameButtonsItem
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
            checked: true
            width: 114
            ButtonGroup.group: switchFrameButtons

            onClicked: framesLayout.currentIndex = 0
        }

        SwitchFrameButton {
            id: controlsFrameButton
            text: "НАСТРОЙКИ"
            width: 114
            x: 115
            ButtonGroup.group: switchFrameButtons

            onClicked: framesLayout.currentIndex = 1
        }

        SwitchFrameButton {
            id: pwswFrameButton
            text: "КОДИРОВАНИЕ"
            width: 114
            x: 230
            ButtonGroup.group: switchFrameButtons

            onClicked: framesLayout.currentIndex = 2
        }

//        SwitchFrameButton {
//            id: sensorsFrameButton
//            text: "SENS"
//            ButtonGroup.group: switchFrameButtons
//        }

        SwitchFrameButton {
            id: helpFrameButton
            text: "ПОМОЩЬ"
            width: 114
            x: 345
            ButtonGroup.group: switchFrameButtons

            onClicked: framesLayout.currentIndex = 3
        }

        ButtonGroup {
            id: switchFrameButtons
        }
    }

    StackLayout {
        id: framesLayout
        x: 30
        y: 90
        width: 400
        height: 500
        currentIndex: 4

        MainFrame {
            id: mainFrame
        }

        ControlsFrame {
            id: controlsFrame
        }

        PwswFrame {
            id: pwswFrame
        }

        HelpFrame {
            id: helpFrame
        }

        EnterPasswordFrame {
            id: enterPasswordFrame
        }
    }

    Connections {
        target: pwswFrame
        function onCurrentPwswLevelChanged() { mainFrame.currentPwswLevel = pwswFrame.currentPwswLevel }
    }

    Connections {
        target: enterPasswordFrame
        function onPasswordAttemptedChanged() {if(enterPasswordFrame.passwordAttempted) framesLayout.currentIndex = 0}
    }
}
