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
        y: 8
        width: 363
        height: 45
        color: "#fefefe"
        text: "PRIMEBOX | ONREMOTE+"
        font.pixelSize: 36
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.weight: Font.Bold
        font.family: "Calibri Light"
    }

    Text {
        id: generalLabel2
        x: 67
        y: 46
        width: 157
        height: 24
        color: "#fefefe"
        text: "by. TRUEDEVICE"
        font.pixelSize: 17
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
    }

    Item {
        id: switchFrameButtonsItem
        y: 601
        height: 92
        visible: false
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
            width: 91
            ButtonGroup.group: switchFrameButtons

            onClicked: framesLayout.currentIndex = 0
        }

        SwitchFrameButton {
            id: controlsFrameButton
            text: "НАСТРОЙКИ"
            width: 91
            x: 92
            ButtonGroup.group: switchFrameButtons

            onClicked: framesLayout.currentIndex = 1
        }

        SwitchFrameButton {
            id: pwswFrameButton
            text: "PWSW"
            width: 91
            x: 184
            ButtonGroup.group: switchFrameButtons

            onClicked: framesLayout.currentIndex = 2
        }

        SwitchFrameButton {
            id: sensorsFrameButton
            text: "SENS"
            x: 276
            width: 91
            ButtonGroup.group: switchFrameButtons

            onClicked: framesLayout.currentIndex = 11
        }

        SwitchFrameButton {
            id: helpFrameButton
            text: "ПОМОЩЬ"
            width: 91
            x: 368
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
        currentIndex: function ()
        {
            if(accountManager.licenseKeyActivated())
            {
                if(accountManager.passwordAttempted())
                {
                    switchFrameButtonsItem.visible = true;
                    return 0;
                }
                else
                    return 6;
            }
            else
            {
                return 4;
            }
        }()

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

        EnterActivationKeyFrame {
            id: enterActivationKeyFrame
        }

        LicenseAgreementFrame {
            id: licenseAgreementFrame
        }

        EnterPasswordFrame {
            id: enterPasswordFrame
        }

        ChangePasswordFrame {
            id: changePasswordFrame
        }

        SmtpFrame {
            id: smtpFrame
        }

        RunningHoursFrame {
            id: runnigHoursFrame
        }

       ExPwswFrame {
            id: exPwswFrame
        }

       SensFrame {
           id: sensFrame
       }
    }

    Connections {
        target:updateTimer
        function onTimeout()
        {
            framesLayout.children[framesLayout.currentIndex].update()
        }
    }

    Connections {
        target: enterActivationKeyFrame.children[2] // Кнопка "АКТИВИРОВАТЬ"
        function onClicked() {if(accountManager.licenseKeyActivated()) framesLayout.currentIndex = 5}
    }

    Connections {
        target: licenseAgreementFrame.children[1] // Кнопка "ПРИНЯТЬ"
        function onClicked()
        {
            if(accountManager.passwordAttempted())
            {
                switchFrameButtonsItem.visible = true;
                framesLayout.currentIndex = 0;
            }
            else
                framesLayout.currentIndex = 6;
        }
    }

    Connections {
        target: enterPasswordFrame.children[2] // Кнопка "ВОЙТИ"
        function onClicked()
        {
            if(accountManager.passwordAttempted())
            {
                framesLayout.currentIndex = 0;
                switchFrameButtonsItem.visible = true;
            }
        }
    }

    Connections {
        target: controlsFrame.children[0] // Кнопка "ПАРОЛЬ"
        function onClicked() {framesLayout.currentIndex = 7}
    }

    Connections {
        target: controlsFrame.children[1] // Кнопка "SMTP"
        function onClicked() {framesLayout.currentIndex = 8}
    }

    Connections {
        target: controlsFrame.children[2] // Кнопка "НАРАБОТКА"
        function onClicked() {framesLayout.currentIndex = 9}
    }

    Connections {
        target: pwswFrame.children[0] // Кнопка "ДОПОЛНИТЕЛЬНО"
        function onClicked() {framesLayout.currentIndex = 10}
    }

//----------------------------------------------------------------------------------------------------------------------------

    onClosing: { close.accepted = false; hide() }

    Connections {
        target: trayIconManager
        function onShowAppWindow()
        {
            if(!accountManager.licenseKeyActivated())
            {
                switchFrameButtonsItem.visible = false;
                framesLayout.currentIndex = 4;
            }

            else if(accountManager.isPasswordSet())
            {
                switchFrameButtonsItem.visible = false;
                framesLayout.currentIndex = 6;
            }

            else
            {
                switchFrameButtonsItem.visible = true;
                framesLayout.currentIndex = 0;
                mainFrameButton.checked = true;
            }

            show();
        }
    }
}
