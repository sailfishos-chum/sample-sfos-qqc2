import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QQC2 Sample")

    Column {
        Text {
            text: "QQC2 Sample"
        }

        Button{
            text: "Red"
            onClicked: {
                rect.color = "red"
            }
        }
        Button {
            text: "Blue"
            onClicked: {
                rect.color = "blue"
            }
        }
        Rectangle {
            id: rect
            width: 100
            height: 100
        }
    }
}
