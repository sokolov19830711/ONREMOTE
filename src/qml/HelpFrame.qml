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
        height: 312
        color: "#fefefe"
        text: "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\">\n<tr>\n<td width=\"550\">\n<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">Все исключительные права на данный<br />программно-аппаратный комплекс принадлежат<br />торговым маркам PRIMEBOX и TRUEDEVICE.<br />Пользователю (или иным третьим лицам)<br />запрещается менять, дизассемблировать,<br />декомпилировать, дешифровать или проводить<br />другие действия с объектным кодом и аппаратной<br />частью данного комплекса без письменного<br />согласия Правообладателя. Пользователь не<br />имеет права распространять данный программно<br />аппаратный комплекс, воспроизводить и<br />доводить ее до всеобщего сведения в какой-либо<br />форме и способом без письменного согласия<br />Правообладателя. Невыполнение<br />вышеперечисленных требований преследуется<br />административной и уголовной ответственностью.</span></p></td></tr></table></body></html>"
        font.pixelSize: 14
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

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


}

/*##^##
Designer {
    D{i:0;formeditorColor:"#808080"}
}
##^##*/
