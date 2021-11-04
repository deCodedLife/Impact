import QtQuick 2.0
import Impact 1.0

Item
{
    id: root
    anchors.fill: parent
    anchors.margins: presets.defaultMargin

    property Impact core: parent.impact

    signal selected()

    ListView
    {
        clip: true
        anchors.fill: parent
        spacing: presets.defaultMargin
        model: core.getCharacters()

        delegate: Character
        {
            width: parent.width
            height: 64

            characterID: modelData["id"]
            name: modelData["name"]
            characterImage: modelData["image"]

            isEmpty: false
            onClicked:
            {
                console.log(characterID, root.parent.selectedIndex)
                root.core.addCharacter(characterID, root.parent.selectedIndex)
                root.parent.source = "MainPage.qml"
            }
        }
    }

    Presets
    {
        id: presets
    }
}
