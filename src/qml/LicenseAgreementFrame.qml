import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    Text {
        id: currentPwswLevelLabel
        x: 0
        y: 16
        width: 401
        height: 51
        color: "#fefefe"
        text: qsTr("ЛИЦЕНЗИОННОЕ СОГЛАШЕНИЕ")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 16
        font.family: "Arial"
        font.weight: Font.Light
    }

    Button {
        id: agreeButton
        x: 141
        y: 407
        width: 119
        height: 40
        text: "ПРИНЯТЬ"
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
    }

    Text {
        id: text1
        x: 34
        y: 76
        width: 384
        height: 23
        color: "#fefefe"
        text: "Все  исключительные  права    на  данный  программно-"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text2
        x: 26
        y: 94
        width: 384
        height: 23
        color: "#fefefe"
        text: "аппаратный комплекс принадлежат торговым маркам            "
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text3
        x: 26
        y: 114
        width: 384
        height: 23
        color: "#fefefe"
        text: "PRIMEBOX и TRUEDEVICE.                                                "
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text4
        x: 20
        y: 134
        width: 384
        height: 23
        color: "#fefefe"
        text: "Пользователю (или иным третьим лицам) запрещается"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text5
        x: 26
        y: 154
        width: 384
        height: 23
        color: "#fefefe"
        text: "менять, дизассемблировать, декомпилировать, дешиф-"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text6
        x: 26
        y: 174
        width: 384
        height: 23
        color: "#fefefe"
        text: "фровать или проводить другие действия с объектным"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text7
        x: 26
        y: 194
        width: 384
        height: 23
        color: "#fefefe"
        text: "кодом или аппаратной частью данного комплекса без"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text8
        x: 26
        y: 214
        width: 384
        height: 23
        color: "#fefefe"
        text: " письменнго согласия Правообладателя. Пользователь"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text9
        x: 26
        y: 234
        width: 384
        height: 23
        color: "#fefefe"
        text: "не имеет право распространять данный программно-"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text10
        x: 26
        y: 254
        width: 384
        height: 23
        color: "#fefefe"
        text: "аппаратный комплекс, воспроизводить и доводить ин-"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text11
        x: 26
        y: 274
        width: 384
        height: 23
        color: "#fefefe"
        text: "формацию о нем до всеобщего сведения без письмен-"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text12
        x: 26
        y: 294
        width: 384
        height: 23
        color: "#fefefe"
        text: "ного разрешения Правообладателя. Невыполнение вы-"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text13
        x: 26
        y: 314
        width: 384
        height: 23
        color: "#fefefe"
        text: "шеперечисленных требований преследуется админи-"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: text14
        x: 26
        y: 334
        width: 384
        height: 23
        color: "#fefefe"
        text: "стративной и уголовной ответсвенностью."
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }
}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
