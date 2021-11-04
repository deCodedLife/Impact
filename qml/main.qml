import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Window 2.3

import Impact 1.0

Window
{
    id: root

    visible: true
    title: qsTr("Impact")

    width: Screen.width
    height: Screen.height

    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    property bool isMinimized: true
    property bool canHide: true
    property bool canDrag: false
    property bool cooldownActivated: false

    property var floatingButtonWindow
    property var floatingCooldownWindow

    property int selectedCharacter: core.currentCharacter
    property var characters: core.activeCharacters

    color: Qt.rgba(0,0,0,0)

    Rectangle
    {
        id: activeZone

        width: 480
        height: 350

        radius: 10
        clip: true

        state: "normal"
        states: [
            State
            {
                name: "normal"
                PropertyChanges
                {
                    target: mouseArea
                    drag.target: undefined
                }
                PropertyChanges
                {
                    target: activeZone
                    color: Qt.rgba(0, 0, 0, 0)
                }
            },
            State
            {
                name: "dragged"
                PropertyChanges
                {
                    target: mouseArea
                    drag.target: activeZone
                }
                PropertyChanges
                {
                    target: activeZone
                    color: Qt.rgba(0, 0, 0, 0.5)
                }
            }

        ]

        Rectangle
        {
            anchors.fill: parent
            radius: 10
            color: Qt.rgba(0, 0, 0, 0.6)
        }

        Loader
        {
            id: loader
            property Impact impact: core
            property Window rootWindow: root
            property int selectedIndex: 0
            property var selectedCharacters: characters

            anchors.fill: parent
            source: "MainPage.qml"
        }

        Keys.onPressed:
        {
            if ( event.key === Qt.Key_Alt )
            {
                canDrag = true
            }
        }

        Keys.onReleased:
        {
            canDrag = false
        }

        MouseArea
        {
            id: mouseArea
            hoverEnabled: true

            anchors.fill: parent
            propagateComposedEvents: true

            onDoubleClicked: mouse.accepted = false;
            onPositionChanged: mouse.accepted = false;
            onPressAndHold: mouse.accepted = false;

            onPressed:
            {
                if ( root.canDrag )
                {
                    mouse.accepted = true
                    activeZone.state = "dragged"
                }
                else
                {
                    mouse.accepted = false
                }
            }

            onReleased: activeZone.state = "normal"

            onHoveredChanged:
            {
                if ( containsMouse )
                {
                    canHide = false
                }
                else
                {
                    canHide = true
                }
            }

            drag
            {
                smoothed: true
                axis: Drag.XAndYAxis
            }
        }
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

    MouseArea
    {
        z: -1

        anchors.fill: parent
        propagateComposedEvents: true

        onReleased: mouse.accepted = false;
        onDoubleClicked: mouse.accepted = false;
        onPositionChanged: mouse.accepted = false;
        onPressAndHold: mouse.accepted = false;

        onClicked:
        {
            if ( canHide )
            {
                root.visible = false
            }
        }
    }
}
