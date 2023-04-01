import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        anchors.centerIn: parent
        spacing: 10

        Button {
            id: button
            text: "Shit!"
            font.pixelSize: 50
            onClicked: {
                Sender.consoleLog();
                button.text = Sender.buttonTextChange("Anal!");
            }
        }
    }
}
