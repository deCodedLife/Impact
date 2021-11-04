import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls.impl 2.12

CheckLabel
{
    id: root

    property string textColor: ""

    text: root.parent.text
    font: root.parent.font

    color: root.textColor

    leftPadding: root.parent.indicator && !root.parent.mirrored ? root.parent.indicator.width + root.parent.spacing : 0
    rightPadding: root.parent.indicator && root.parent.mirrored ? root.parent.indicator.width + root.parent.spacing : 0
}
