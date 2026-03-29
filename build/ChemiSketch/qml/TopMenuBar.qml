import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root
    height: 36
    color: Theme.bgSurface

    Rectangle {
        anchors.bottom: parent.bottom
        width: parent.width
        height: 1
        color: Theme.border
    }

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Theme.spacingLg
        anchors.rightMargin: Theme.spacingLg
        spacing: 0

        // App logo + name
        Row {
            spacing: Theme.spacingSm
            Layout.alignment: Qt.AlignVCenter

            Rectangle {
                width: 22; height: 22
                radius: 11
                color: Theme.accentBlue
                anchors.verticalCenter: parent.verticalCenter

                Text {
                    anchors.centerIn: parent
                    text: "C"
                    font.family: Theme.fontFamily
                    font.pixelSize: 12
                    font.bold: true
                    color: "#FFFFFF"
                }
            }

            Text {
                text: "ChemiSketch"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontMd
                font.weight: Font.DemiBold
                color: Theme.textPrimary
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Item { Layout.fillWidth: true }

        // Center menu items
        Row {
            Layout.alignment: Qt.AlignVCenter
            spacing: 2

            Repeater {
                model: ["File", "Edit", "View", "Window", "Help"]

                Rectangle {
                    width: menuLabel.implicitWidth + 20
                    height: 28
                    radius: Theme.radiusSm
                    color: menuMa.containsMouse ? Qt.rgba(1,1,1,0.06) : "transparent"
                    anchors.verticalCenter: parent.verticalCenter

                    Text {
                        id: menuLabel
                        anchors.centerIn: parent
                        text: modelData
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: menuMa.containsMouse ? Theme.textPrimary : Theme.textSecondary
                    }

                    Rectangle {
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width - 8
                        height: 2
                        radius: 1
                        color: Theme.accentBlue
                        opacity: menuMa.containsMouse ? 1.0 : 0.0
                        Behavior on opacity { NumberAnimation { duration: Theme.animFast } }
                    }

                    MouseArea {
                        id: menuMa
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                    }
                }
            }
        }

        Item { Layout.fillWidth: true }

        // Right side: search + avatar
        Row {
            Layout.alignment: Qt.AlignVCenter
            spacing: Theme.spacingSm

            // Search button
            Rectangle {
                width: 28; height: 28
                radius: Theme.radiusSm
                color: searchMa.containsMouse ? Qt.rgba(1,1,1,0.06) : "transparent"
                anchors.verticalCenter: parent.verticalCenter

                Text {
                    anchors.centerIn: parent
                    text: "\u2315"
                    font.pixelSize: 16
                    color: Theme.textSecondary
                }

                MouseArea {
                    id: searchMa
                    anchors.fill: parent
                    hoverEnabled: true
                    cursorShape: Qt.PointingHandCursor
                }
            }

            // Avatar
            Rectangle {
                width: 24; height: 24
                radius: 12
                color: Theme.accentPurple
                anchors.verticalCenter: parent.verticalCenter

                Text {
                    anchors.centerIn: parent
                    text: "J"
                    font.family: Theme.fontFamily
                    font.pixelSize: 11
                    font.bold: true
                    color: "#FFFFFF"
                }
            }
        }
    }
}
