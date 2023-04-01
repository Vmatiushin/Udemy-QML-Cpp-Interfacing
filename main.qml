import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Connections {
        target: Sender
        onCallQml: {
            console.log("This is QML: callQML signal cought!")
            mText.text = parameter
        }

        onCppTimer: {
            mRectText.text = value;
        }
    }

    Row {
        Rectangle {
            width: 200
            height: 200
            color: "red"
            radius: 20

            Text {
                id: mRectText
                text: "0"
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 30
            }
        }

        Button {
            text: "Call C++ Method"
            onClicked: {
                Sender.cppSlot();
            }
        }

        Text {
            id: mText
            text: "Default"
        }
    }
}
