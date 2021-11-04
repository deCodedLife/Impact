import QtQuick 2.9
import QtQuick.Window 2.3

import Impact 1.0

Window
{
    width: 480
    height: 320
    visible: true
    title: qsTr("Impact")

    maximumHeight: 340
    maximumWidth: 500

    minimumHeight: 340
    minimumWidth: 500

    Image
    {
        anchors.fill: parent
        source: "qrc:/images/background.jpg"
    }

    Rectangle
    {
        anchors.fill: parent
        color: Qt.rgba(0, 0, 0, 0.8)
    }

    Loader
    {
        property Impact impact: core
        property int selectedIndex: 0
        property var selectedCharacters: core.activeCharacters

        anchors.fill: parent
        source: "MainPage.qml"
    }

    Impact
    {
        id: core
        enabled: false
    }

    Presets
    {
        id: presets
    }
}
