import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3

Item
{
    id: hero;

    property int characterID: -1
    property bool isEmpty: true
    property bool isActive: false
    property string name: ""
    property string characterImage: ""

    signal clicked()

    Rectangle
    {
        id: background

        anchors.fill: parent
        color: isActive ? Qt.rgba(0,0.5,0,1) : Qt.rgba(0,0,0,0.3)
        radius: 5
        clip: true

        RowLayout
        {
            anchors.fill: parent
            spacing: presets.defaultMargin

            Image
            {
                width: hero.height
                height: hero.height

                source: characterImage !== "" ? "qrc:/images/" + characterImage : ""
                sourceSize: Qt.size(hero.height, hero.height)
            }

            Text
            {
                text: name
                color: presets.textColor

                font.bold: true
                font.pointSize: presets.h2

                visible: !isEmpty
            }

            Rectangle{ Layout.fillWidth: true; color: Qt.rgba(0,0,0,0) }
        }
    }



    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            hero.clicked(hero.index)

            if ( isEmpty == false )
            {
                isActive = !isActive
            }
        }
    }

    Presets
    {
        id: presets
    }
}
