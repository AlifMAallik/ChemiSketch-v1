import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root
    width: 280
    color: Theme.bgSurface

    property var moleculeInfo: ({})

    Rectangle {
        anchors.left: parent.left
        width: 1
        height: parent.height
        color: Theme.border
    }

    Flickable {
        anchors.fill: parent
        anchors.leftMargin: 1
        contentHeight: panelColumn.height + Theme.spacingXl
        clip: true
        boundsBehavior: Flickable.StopAtBounds

        Column {
            id: panelColumn
            width: parent.width
            spacing: Theme.spacingLg
            padding: Theme.spacingLg

            // Title
            Text {
                text: "Properties"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontXl
                font.weight: Font.Bold
                color: Theme.textPrimary
            }

            // ATOMIC COMPOSITION
            Column {
                width: parent.width - 2 * Theme.spacingLg
                spacing: Theme.spacingSm

                Text {
                    text: "ATOMIC COMPOSITION"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontXs
                    font.letterSpacing: 1.0
                    color: Theme.textMuted
                }

                Row {
                    spacing: Theme.spacingSm
                    width: parent.width

                    Repeater {
                        model: [
                            { count: root.moleculeInfo.atomCount || 0, label: "Atoms" },
                            { count: root.moleculeInfo.bondCount || 0, label: "Bonds" }
                        ]

                        Rectangle {
                            width: (parent.parent.width - Theme.spacingSm) / 2
                            height: 64
                            radius: Theme.radiusMd
                            color: Theme.bgCard
                            border.color: Theme.border
                            border.width: 1
                            antialiasing: true

                            Column {
                                anchors.centerIn: parent
                                spacing: 4

                                Text {
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    text: modelData.count.toString()
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontXxl
                                    font.weight: Font.Bold
                                    color: Theme.textPrimary
                                }
                                Text {
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    text: modelData.label
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontXs
                                    color: Theme.textSecondary
                                }
                            }
                        }
                    }
                }
            }

            // VALIDATION
            Column {
                width: parent.width - 2 * Theme.spacingLg
                spacing: Theme.spacingSm

                Text {
                    text: "VALIDATION"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontXs
                    font.letterSpacing: 1.0
                    color: Theme.textMuted
                }

                Rectangle {
                    width: parent.width
                    height: validationCol.height + 2 * Theme.spacingLg
                    radius: Theme.radiusMd
                    color: Qt.rgba(0.82, 0.60, 0.13, 0.08)
                    border.color: Qt.rgba(0.82, 0.60, 0.13, 0.3)
                    border.width: 1
                    antialiasing: true

                    Column {
                        id: validationCol
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.margins: Theme.spacingLg
                        spacing: Theme.spacingSm

                        Row {
                            spacing: Theme.spacingSm

                            Text {
                                text: "\u26A0"
                                font.pixelSize: 14
                                color: Theme.accentAmber
                            }
                            Text {
                                text: "Valence Warning"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                font.weight: Font.DemiBold
                                color: Theme.accentAmber
                            }
                        }

                        Text {
                            text: root.moleculeInfo.isValid ? "Structure passes all valence checks." : "Check atom valences — some atoms may have unusual bonding."
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSm
                            color: Theme.textSecondary
                            wrapMode: Text.WordWrap
                            width: parent.width
                        }
                    }
                }
            }

            // MOLECULE INFO
            Column {
                width: parent.width - 2 * Theme.spacingLg
                spacing: Theme.spacingSm

                Text {
                    text: "MOLECULE"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontXs
                    font.letterSpacing: 1.0
                    color: Theme.textMuted
                }

                Column {
                    width: parent.width
                    spacing: Theme.spacingXs

                    Repeater {
                        model: [
                            { key: "Formula", value: root.moleculeInfo.formula || "\u2014" },
                            { key: "Weight", value: root.moleculeInfo.molecularWeight ? root.moleculeInfo.molecularWeight.toFixed(2) + " g/mol" : "\u2014" },
                            { key: "Type", value: root.moleculeInfo.classification || "\u2014" }
                        ]

                        Rectangle {
                            width: parent.width
                            height: 32
                            radius: Theme.radiusSm
                            color: Theme.bgCard

                            Row {
                                anchors.fill: parent
                                anchors.leftMargin: Theme.spacingMd
                                anchors.rightMargin: Theme.spacingMd

                                Text {
                                    text: modelData.key
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontSm
                                    color: Theme.textSecondary
                                    anchors.verticalCenter: parent.verticalCenter
                                    width: 60
                                }
                                Text {
                                    text: modelData.value
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontSm
                                    font.weight: Font.DemiBold
                                    color: Theme.textPrimary
                                    anchors.verticalCenter: parent.verticalCenter
                                }
                            }
                        }
                    }
                }
            }

            // RECENT VERSIONS
            Column {
                width: parent.width - 2 * Theme.spacingLg
                spacing: Theme.spacingSm

                Text {
                    text: "RECENT VERSIONS"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontXs
                    font.letterSpacing: 1.0
                    color: Theme.textMuted
                }

                Repeater {
                    model: [
                        { name: "Aspirin v2.1", time: "2 min ago" },
                        { name: "Aspirin v2.0", time: "15 min ago" }
                    ]

                    Rectangle {
                        width: parent.width
                        height: 48
                        radius: Theme.radiusSm
                        color: Theme.bgCard
                        border.color: Theme.border
                        border.width: 1
                        antialiasing: true

                        Row {
                            anchors.fill: parent
                            anchors.margins: Theme.spacingMd
                            spacing: Theme.spacingMd

                            // Thumbnail placeholder
                            Rectangle {
                                width: 32; height: 32
                                radius: Theme.radiusSm
                                color: Theme.bgBase
                                anchors.verticalCenter: parent.verticalCenter

                                Text {
                                    anchors.centerIn: parent
                                    text: "\u2B22"
                                    font.pixelSize: 14
                                    color: Theme.textMuted
                                }
                            }

                            Column {
                                anchors.verticalCenter: parent.verticalCenter
                                spacing: 2

                                Text {
                                    text: modelData.name
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontSm
                                    font.weight: Font.DemiBold
                                    color: Theme.textPrimary
                                }
                                Text {
                                    text: modelData.time
                                    font.family: Theme.fontFamily
                                    font.pixelSize: 9
                                    color: Theme.textMuted
                                }
                            }
                        }
                    }
                }
            }

            // CTA Button
            Rectangle {
                width: parent.width - 2 * Theme.spacingLg
                height: 44
                radius: Theme.radiusMd
                color: Theme.accentBlue
                antialiasing: true

                // Glow
                Rectangle {
                    anchors.fill: parent
                    anchors.margins: -8
                    radius: Theme.radiusMd + 8
                    color: "transparent"
                    border.color: "transparent"

                    Rectangle {
                        anchors.fill: parent
                        radius: parent.radius
                        color: Theme.accentBlue
                        opacity: 0.15
                    }
                }

                Text {
                    anchors.centerIn: parent
                    text: "Execute Synthesis Plan"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontMd
                    font.weight: Font.DemiBold
                    color: "#FFFFFF"
                }

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                    hoverEnabled: true

                    onContainsMouseChanged: {
                        parent.opacity = containsMouse ? 0.9 : 1.0
                    }
                }

                Behavior on opacity { NumberAnimation { duration: Theme.animFast } }
            }
        }
    }
}
