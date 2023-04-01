import QtQuick 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        width: parent.width
        height: parent.height
        spacing: 20
        anchors.centerIn: parent

        Rectangle {
            id: redRect
            height: parent.height
            width: parent.width / 3
            color: "red"

            MouseArea {
                id: redRectMouseArea
                anchors.fill: parent
                onClicked: {
                    console.log("Red Rectangle Clicked!")
                }
            }
        }

        Rectangle {
            height: parent.height
            width: parent.width / 3
            color: "green"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Also Green Rect!")
                }
            }

            Connections {
                target: redRectMouseArea
                onClicked: {
                    console.log("Also Green Rect!")
                }
            }
        }

        Rectangle {
            height: parent.height
            width: parent.width / 3
            color: "blue"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Also Blue Rect!")
                }
            }

            Connections {
                target: redRectMouseArea
                onClicked: {
                    console.log("Also Blue Rect!")
                }
            }
        }
    }
}
