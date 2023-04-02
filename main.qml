import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        spacing: 20

        Text {
            id: titleId
            width: 500
            text: Movie.title
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: mainCharId
            width: 500
            text: Movie.mainCharacter
            font.pointSize: 50
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            TextField {
                id: titleTextFieldId
                width: 300
            }

            Button {
                id: button1
                width: 200
                text: "Change Title"
                onClicked: {
                    Movie.title = titleTextFieldId.text
                }
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter

            TextField {
                id: mainCharacterTextFieldId
                width: 300
            }

            Button {
                id: button2
                width: 200
                text: "Change Main Character"
                onClicked: {
                    Movie.mainCharacter = mainCharacterTextFieldId.text
                }
            }
        }
    }
}
