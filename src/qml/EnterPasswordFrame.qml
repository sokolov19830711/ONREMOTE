import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Text {
        id: text1
        x: 8
        y: 13
        width: 384
        height: 42
        color: "#fefefe"
        text: "ВВЕДИТЕ ПАРОЛЬ"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    TextField {
        id: passwordField
        x: 8
        y: 54
        width: 384
        height: 52
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        placeholderText: ""
        echoMode: TextInput.Password
        passwordMaskDelay: 300

        background: Rectangle {
            color: "#636363"
        }
    }

    Button {
        id: attemptPasswordButton
        x: 150
        y: 122
        width: 101
        height: 40
        text: "ВОЙТИ"
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

        onClicked: { if (accountManager.attemptPassword(passwordField.text)) passwordField.clear()}
    }


}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
