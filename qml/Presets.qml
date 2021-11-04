import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3

Item
{
    id: root

    Material.accent: Material.Red
    Material.theme:  Material.Dark

    property string textColor: "white"
    property string highlitedTextColor: "white"
    property string accentColor: Qt.rgba(0.7, 0, 0, 1)

    property int defaultHeight: 48
    property int defaultMargin: 5

    property int h1: 24
    property int h2: 18
    property int h3: 14
    property int h4: 12
    property int h5: 8
}
