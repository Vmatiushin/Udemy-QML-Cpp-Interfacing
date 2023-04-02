import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function qmlJSFunction(param)
    {
        console.log("QML Talking, C++ called me with parameter: " + param
                    + "returning back")
        return "This is QML, over to you C++. Thanks for the Call"
    }

    Button {
        id: mButton
        text: "Call QML function from C++"
        onClicked: {
            QmlJsCaller.cppMethod("QML Calling...")
        }
    }
}
