import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Text {
        id: text1
        x: 8
        y: 127
        width: 384
        height: 42
        color: "#fefefe"
        text: "ВВЕДИТЕ КЛЮЧ АКТИВАЦИИ"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    TextField {
        id: keyField
        x: 8
        y: 168
        width: 384
        height: 52
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 15
        placeholderText: ""

        background: Rectangle {
            color: "#636363"
        }
    }

    Button {
        id: attemptKeyButton
        x: 130
        y: 233
        width: 140
        height: 40
        text: "АКТИВИРОВАТЬ"
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

        onClicked: accountManager.attemptLicenseKey(keyField.text)
    }


}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
