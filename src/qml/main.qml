import QtQuick 2.12
import QtQuick.Controls 2.12
import "qrc:/"

ApplicationWindow
{
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
        x: 68
        y: 28
        width: 325
        height: 45
        color: "#fefefe"
        text: qsTr("PRIMEBOX | ONREMOTE+")
        font.pixelSize: 23
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.weight: Font.Bold
        font.family: "Arial"
    }

    Text {
        id: generalLabel2
        x: 88
        y: 57
        width: 157
        height: 24
        color: "#fefefe"
        text: qsTr("by. TRUEDEVICE")
        font.pixelSize: 11
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Arial"
    }
}
