import QtQuick 2.9
import QtQuick.Window 2.3

Window
{
    id: root

    width: 64
    height: 64

    x: pressets.defaultMargin
    y: Screen.height - (root.height + pressets.defaultMargin)

    visible: true
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    color: Qt.rgba(0,0,0,0.5)

//    property var parentObj: PARENT_OBJ

    Image
    {
        anchors.fill: parent
        source: "qrc:/images/FloatingButton.png"
        sourceSize: Qt.size(256, 256)
    }

    Presets
    {
        id: pressets
    }

    MouseArea
    {
        anchors.fill: parent

        onClicked:
        {
            PARENT_OBJ.visible = true
//            console.log(PARENT_OBJ)
        }
    }
}
