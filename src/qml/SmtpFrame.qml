import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Button {
        id: testButton
        x: 292
        y: 431
        width: 100
        height: 40
        text: "ТЕСТ"
        font.pointSize: 10

        background: Rectangle {
            color: parent.pressed ? "#166999" : "#30859B"
        }

        contentItem: Text {
            color: "#fefefe"
            text: parent.text
            font: parent.font
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }
    }

    Text {
        id: text16
        x: 30
        y: 433
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("нажмите, чтобы отправить")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        minimumPixelSize: 10
    }

    Text {
        id: text17
        x: 30
        y: 450
        width: 256
        height: 19
        color: "#fefefe"
        text: qsTr("тестовое сообщение")
        font.pixelSize: 15
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.family: "Calibri Light"
        font.italic: true
        minimumPixelSize: 10
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
