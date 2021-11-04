import QtQuick 2.9
import QtQuick.Window 2.3

Window
{
    id: root

    width: Screen.width
    height: Screen.height

    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint
    visible: PARENT_OBJ.cooldownActivated

    color: Qt.rgba(0,0,0,0)

    ListView
    {
        interactive: false
        anchors.margins: pressets.defaultMargin
        spacing: pressets.defaultMargin
        anchors.fill: parent
        model: PARENT_OBJ.characters

        delegate:
        CharacterCooldown
        {
            property int indexOfThisDelegate: index
            x: Screen.width - width

            characterImage: modelData["image"]

            firstSkillCooldown: modelData["firstSkillCooldown"]
            ultimateCooldown: modelData["ultimateCooldown"]

            isActive: index == PARENT_OBJ.selectedCharacter ? true : false

            Component.onCompleted:
            {
                console.log(PARENT_OBJ.selectedCharacter)
                console.log(index)
            }

            MouseArea
            {
                id: mouse
                anchors.fill: parent

                drag
                {
                    target: mouse.parent
                    axis: Drag.XandYAxis
                }
            }
        }

    }

    Presets
    {
        id: pressets
    }
}
