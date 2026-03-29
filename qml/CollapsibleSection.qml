import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Column {
    id: root

    property string title: ""
    property bool expanded: true
    default property alias content: contentContainer.data

    width: parent ? parent.width : 200
    spacing: 0

    // Header
    Rectangle {
        width: parent.width
        height: 28
        color: "transparent"

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            onClicked: root.expanded = !root.expanded
        }

        RowLayout {
            anchors.fill: parent
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            spacing: Theme.spacingXs

            Text {
                text: root.expanded ? "\u25BE" : "\u25B8"
                font.pixelSize: 10
                color: Theme.textMuted
            }

            Text {
                text: root.title
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontXs
                font.weight: Font.DemiBold
                font.letterSpacing: 1.0
                color: Theme.textMuted
                Layout.fillWidth: true
            }
        }
    }

    // Content
    Item {
        id: contentWrapper
        width: parent.width
        height: root.expanded ? contentContainer.implicitHeight : 0
        clip: true
        opacity: root.expanded ? 1.0 : 0.0

        Behavior on height {
            SpringAnimation {
                spring: 3
                damping: 0.8
                mass: 0.5
            }
        }
        Behavior on opacity {
            NumberAnimation { duration: Theme.animNormal }
        }

        Column {
            id: contentContainer
            width: parent.width
            spacing: Theme.spacingSm
        }
    }
}
