import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    property int currentPwswLevel: 0

    onCurrentPwswLevelChanged: dataManager.setPowerButtonPwdLevel(currentPwswLevel)

    Text {
        id: setPwswLevelLabel
        x: 16
        y: 136
        width: 231
        height: 30
        color: "#fefefe"
        text: qsTr("ЕСЛИ ТЕМПЕРАТУРА")
        font.pixelSize: 22
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.family: "Calibri Light"
        font.weight: Font.Normal
        minimumPixelSize: 16
    }

    //-------------------------------------------------------------------------------------------------
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
