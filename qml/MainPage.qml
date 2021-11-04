import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3

import Impact 1.0

Item
{
    id: root
    anchors.fill: parent

    property Impact core: parent.impact
    property var _selectedCharacters: parent.selectedCharacters

    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: presets.defaultMargin

        RowLayout
        {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Rectangle
            {
                Layout.fillWidth: true
                Layout.fillHeight: true

                id: configsRoot
                color: Qt.rgba(0,0,0,0)

                ColumnLayout
                {
                    Switch
                    {
                        id: dragonstrike

                        text: "Dragonstrike"

                        font.bold: true
                        font.pointSize: presets.h4

                        contentItem: CustomContent
                        {
                            textColor: presets.textColor
                        }

                        onCheckedChanged:
                        {
                            core.dragonstrike = checked
                        }

                        Component.onCompleted:
                        {
                            checked = core.dragonstrike
                        }
                    }

                    Switch
                    {
                        text: "Cancel attack animations"

                        font.bold: true
                        font.pointSize: presets.h4

                        contentItem: CustomContent
                        {
                            textColor: presets.textColor
                        }

                        onCheckedChanged:
                        {
                            core.cancelAnimations = checked
                        }

                        Component.onCompleted:
                        {
                            checked = core.cancelAnimations
                        }
                    }

                    Switch
                    {
                        text: "Show cooldown"
                        checked: false

                        font.bold: true
                        font.pointSize: presets.h4

                        contentItem: CustomContent
                        {
                            textColor: presets.textColor
                        }

                        onCheckedChanged:
                        {
                            root.parent.rootWindow.cooldownActivated = checked
                        }
                    }
                }
            }

            ListView
            {
                interactive: false

                width: 64
                Layout.fillHeight: true

                clip: true
                spacing: presets.defaultMargin
                model: _selectedCharacters

                delegate: Character
                {
                    width: 64
                    height: 64

                    isActive: index == core.currentCharacter ? true : false

                    characterID: modelData["id"]
                    name: modelData["name"]
                    characterImage: modelData["image"]

                    isEmpty: false

                    onClicked:
                    {
                        root.parent.selectedIndex = index
                        root.parent.source = "ListPage.qml"
                    }
                }
            }

        }

        Switch
        {
            id: switchState
            text: "Enabled"

            font.bold: true
            font.pointSize: presets.h3

            contentItem: CustomContent
            {
                textColor: presets.textColor
            }

            checkable: !core.ignoring
            checked: core.enabled

            onCheckedChanged:
            {
                core.enabled = checked
            }
        }
    }

    Presets
    {
        id: presets
    }
}
