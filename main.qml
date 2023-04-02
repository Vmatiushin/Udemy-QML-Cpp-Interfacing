import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rect1
        width: text1.implicitWidth + 20
        height: text1.implicitHeight + 20
        color: "beige"
        border.color: "yellowgreen"

        Text {
            id: text1
            anchors.centerIn: parent
            text: firstname
            font.pointSize: 20
        }
    }

    Rectangle {
        id: rect2
        anchors.left: rect1.right
        anchors.leftMargin: 5
        width: text2.implicitWidth + 20
        height: text2.implicitHeight + 20
        color: "beige"
        border.color: "yellowgreen"

        Text {
            id: text2
            anchors.centerIn: parent
            text: lastname
            font.pointSize: 20
        }
    }
}
