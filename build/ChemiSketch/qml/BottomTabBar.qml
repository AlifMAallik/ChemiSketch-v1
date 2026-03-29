import QtQuick
import QtQuick.Layouts

Rectangle {
    id: root
    width: 520
    height: 72
    radius: Theme.radiusPill
    color: Theme.bgCard
    antialiasing: true

    property int currentIndex: 0
    signal tabClicked(int index)

    border.color: Theme.border
    border.width: 1

    // Sliding active indicator
    Rectangle {
        id: activeIndicator
        width: 80
        height: 56
        radius: Theme.radiusPill
        color: Theme.accentBlue
        y: 8
        x: 16 + root.currentIndex * (root.width - 32) / 5 + ((root.width - 32) / 5 - 80) / 2
        antialiasing: true

        Behavior on x {
            SpringAnimation {
                spring: 3
                damping: 0.7
                mass: 0.5
            }
        }
    }

    Row {
        anchors.fill: parent
        anchors.leftMargin: 16
        anchors.rightMargin: 16

        Repeater {
            model: [
                { label: "SKETCH", icon: "\u270E" },
                { label: "3D VIEW", icon: "\u2B22" },
                { label: "ANALYZE", icon: "\u2261" },
                { label: "PROPS", icon: "\u2699" },
                { label: "EXPORT", icon: "\u21E5" }
            ]

            Item {
                width: (root.width - 32) / 5
                height: root.height

                Column {
                    anchors.centerIn: parent
                    spacing: 4

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: modelData.icon
                        font.pixelSize: 22
                        color: root.currentIndex === index ? "#FFFFFF" : Theme.textMuted
                        Behavior on color { ColorAnimation { duration: Theme.animFast } }
                    }

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: modelData.label
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontXs
                        font.letterSpacing: 0.5
                        font.weight: Font.DemiBold
                        color: root.currentIndex === index ? "#FFFFFF" : Theme.textMuted
                        Behavior on color { ColorAnimation { duration: Theme.animFast } }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        root.currentIndex = index
                        root.tabClicked(index)
                    }
                }
            }
        }
    }
}
