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
        x: 0
        y: 170
        width: 401
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

    ButtonGroup {
        id: setPwswButtons

        onClicked: {
            if(button == setPwswLowButton) pwswFrame.currentPwswLevel = 1;
            else if(button == setPwswMediumButton) pwswFrame.currentPwswLevel = 2;
            else if(button == setPwswHighButton) pwswFrame.currentPwswLevel = 3;
            else pwswFrame.currentPwswLevel = 0;
        }
    }

    //-------------------------------------------------------------------------------------------------
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
