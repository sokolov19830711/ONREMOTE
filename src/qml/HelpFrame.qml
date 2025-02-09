import QtQuick 2.12
import QtQuick.Controls 2.12
import "PrimeboxQmlWidgets"

Item {
    width: 400
    height: 500

    TextField {
        id: activationKeyField
        x: 8
        y: 331
        width: 384
        height: 52
        color: "#fefefe"
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 17
        placeholderText: "XXXX-XXXX-XXXX-XXXX"

        background: Rectangle {
            color: "#636363"
        }
    }

    Button {
        id: activateButton
        x: 8
        y: 394
        width: 119
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
    }

    Rectangle {
        id: rectangle
        x: 290
        y: 394
        width: 100
        height: 20
        color: "#ffffff"
        border.width: 0
    }

    Rectangle {
        id: rectangle1
        x: 290
        y: 414
        width: 100
        height: 20
        color: "#245ae8"
        border.width: 0
    }

    Rectangle {
        id: rectangle2
        x: 290
        y: 434
        width: 100
        height: 20
        color: "#f71d11"
        border.width: 0
    }

    Text {
        id: text9
        x: 196
        y: 394
        width: 89
        height: 20
        color: "#fefefe"
        text: qsTr("разработано и")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 6
    }

    Text {
        id: text10
        x: 154
        y: 412
        width: 130
        height: 20
        color: "#fefefe"
        text: qsTr("произведено в России")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        minimumPixelSize: 6
    }

    Text {
        id: text11
        x: 155
        y: 434
        width: 130
        height: 20
        color: "#fefefe"
        text: qsTr("MADE IN RUSSIA")
        font.pixelSize: 12
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        minimumPixelSize: 6
    }

    Text {
        id: text1
        x: 26
        y: 34
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
        x: 18
        y: 56
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
        x: 18
        y: 76
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
        x: 12
        y: 96
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
        x: 18
        y: 116
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
        x: 18
        y: 136
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
        x: 18
        y: 156
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
        x: 18
        y: 176
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
        id: text12
        x: 18
        y: 196
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
        id: text13
        x: 18
        y: 216
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
        id: text14
        x: 18
        y: 236
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
        id: text15
        x: 18
        y: 256
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
        id: text16
        x: 18
        y: 276
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
        id: text17
        x: 18
        y: 296
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
