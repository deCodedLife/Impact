import QtQuick 2.9

Item
{
    id: root

    width: 200
    height: 64

    property bool isActive: false
    property string characterImage: ""

    property int firstSkillCooldown: 0
    property int ultimateCooldown: 0

    Rectangle
    {
        clip: true
        radius: 5
        anchors.fill: parent
        color: isActive ? Qt.rgba(0,0.5,0,1) : Qt.rgba(0,0,0,0.3)

        Image
        {
            width: root.height
            height: root.height

            source: characterImage !== "" ? "qrc:/images/" + characterImage : ""
        }
    }
}
