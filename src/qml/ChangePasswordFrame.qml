import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    function checkFields ()
    {
        if (accountManager.checkPassword(passwordField.text) && (newPasswordField1.text === newPasswordField2.text))
        {
            savePasswordButton.enabled = true
        }

        else
        {
            savePasswordButton.enabled = false
        }
    }

    Text {
        id: text1
        x: 8
        y: 13
        width: 384
        height: 42
        color: "#fefefe"
        text: "ВВЕДИТЕ ТЕКУЩИЙ ПАРОЛЬ"
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
        id: savePasswordButton
        x: 138
        y: 312
        width: 124
        height: 40
        text: "СОХРАНИТЬ"
        enabled: false

        contentItem: Text {
            color: "#fefefe"
            text: "СОХРАНИТЬ"
            elide: Text.ElideRight
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font: parent.font
        }
        font.pointSize: 10
        background: Rectangle {
            color: parent.enabled ? (parent.pressed ? "#166999" : "#30859B") : "#636363"
        }

        onClicked: accountManager.savePassword(newPasswordField1.text)
    }

    Text {
        id: text2
        x: 8
        y: 142
        width: 384
        height: 42
        color: "#fefefe"
        text: "ВВЕДИТЕ НОВЫЙ ПАРОЛЬ"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    TextField {
        id: newPasswordField1
        x: 8
        y: 183
        width: 384
        height: 52
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        passwordMaskDelay: 300
        background: Rectangle {
            color: "#636363"
        }
        placeholderText: ""
        echoMode: TextInput.Password
    }

    TextField {
        id: newPasswordField2
        x: 8
        y: 241
        width: 384
        height: 52
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        passwordMaskDelay: 300
        font.pointSize: 15
        background: Rectangle {
            color: "#636363"
        }
        echoMode: TextInput.Password
        placeholderText: ""
    }

    Connections {
        target: passwordField
        function onTextEdited() {checkFields()}
    }

    Connections {
        target: newPasswordField1
        function onTextEdited() {checkFields()}
    }

    Connections {
        target: newPasswordField2
        function onTextEdited() {checkFields()}
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
