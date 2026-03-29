import QtQuick
import QtQuick.Layouts

Rectangle {
    id: root
    color: Theme.bgSurface

    property var moleculeInfo: ({})

    opacity: 0.0
    Component.onCompleted: opacity = 1.0
    Behavior on opacity { NumberAnimation { duration: Theme.animNormal } }

    Flickable {
        anchors.fill: parent
        contentHeight: propsCol.height + Theme.spacingXl
        clip: true
        boundsBehavior: Flickable.StopAtBounds

        Column {
            id: propsCol
            width: parent.width
            spacing: Theme.spacingLg
            padding: Theme.spacingXl

            // Hero section
            Column {
                width: parent.width - 2 * Theme.spacingXl
                spacing: Theme.spacingSm

                Row {
                    width: parent.width

                    Column {
                        spacing: Theme.spacingXs
                        width: parent.width - 60

                        Text {
                            text: root.moleculeInfo.formula ? "Aspirin" : "No Molecule"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontHero
                            font.weight: Font.Bold
                            color: Theme.textPrimary
                        }

                        Text {
                            text: root.moleculeInfo.formula || "C\u2089H\u2088O\u2084"
                            font.family: Theme.fontFamily
                            font.pixelSize: 20
                            color: Theme.accentBlue
                        }
                    }

                    // 3D thumbnail placeholder
                    Rectangle {
                        width: 48; height: 48
                        radius: Theme.radiusMd
                        color: Theme.bgCard
                        border.color: Theme.border
                        border.width: 1
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            anchors.centerIn: parent
                            text: "\u2B22"
                            font.pixelSize: 20
                            color: Theme.textMuted
                        }
                    }
                }

                // SMILES
                Rectangle {
                    width: parent.width
                    height: 28
                    radius: Theme.radiusSm
                    color: Theme.bgCard

                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: Theme.spacingMd
                        text: "CC(=O)OC1=CC=CC=C1C(=O)O"
                        font.family: "monospace"
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                    }
                }

                // InChIKey
                Text {
                    text: "InChIKey: BSYNRYMUTXBXSQ-UHFFFAOYSA-N"
                    font.family: Theme.fontFamily
                    font.pixelSize: 9
                    color: Theme.textMuted
                }
            }

            // Property grid 2x2
            Column {
                width: parent.width - 2 * Theme.spacingXl
                spacing: Theme.spacingSm

                Text {
                    text: "PROPERTIES"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontXs
                    font.letterSpacing: 1.0
                    color: Theme.textMuted
                }

                Grid {
                    columns: 2
                    spacing: Theme.spacingSm
                    width: parent.width

                    Repeater {
                        model: [
                            { label: "MW", value: "180.16", unit: "g/mol" },
                            { label: "Exact Mass", value: "180.042", unit: "Da" },
                            { label: "LogP", value: "1.24", unit: "" },
                            { label: "PSA", value: "63.6", unit: "\u00C5\u00B2" }
                        ]

                        Rectangle {
                            width: (parent.width - Theme.spacingSm) / 2
                            height: 72
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
                                    text: modelData.value
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontXxl
                                    font.weight: Font.Bold
                                    color: modelData.label === "LogP" ? Theme.accentAmber : Theme.textPrimary
                                }
                                Text {
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    text: modelData.label + (modelData.unit ? " (" + modelData.unit + ")" : "")
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontXs
                                    color: Theme.textSecondary
                                }
                            }
                        }
                    }
                }
            }

            // DRUG-LIKENESS
            Column {
                width: parent.width - 2 * Theme.spacingXl
                spacing: Theme.spacingSm

                Text {
                    text: "DRUG-LIKENESS (LIPINSKI)"
                    font.family: Theme.fontFamily
                    font.pixelSize: Theme.fontXs
                    font.letterSpacing: 1.0
                    color: Theme.textMuted
                }

                Repeater {
                    model: [
                        { label: "MW \u2264 500", value: "180.16", pass: true },
                        { label: "LogP \u2264 5", value: "1.24", pass: true },
                        { label: "HBD \u2264 5", value: "1", pass: true },
                        { label: "HBA \u2264 10", value: "4", pass: true }
                    ]

                    Rectangle {
                        width: parent.width
                        height: 36
                        radius: Theme.radiusSm
                        color: Theme.bgCard

                        Row {
                            anchors.fill: parent
                            anchors.leftMargin: Theme.spacingMd
                            anchors.rightMargin: Theme.spacingMd

                            Text {
                                text: modelData.pass ? "\u2713" : "\u2717"
                                font.pixelSize: 12
                                color: modelData.pass ? Theme.accentGreen : Theme.accentRed
                                anchors.verticalCenter: parent.verticalCenter
                                width: 20
                            }
                            Text {
                                text: modelData.label
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                color: Theme.textSecondary
                                anchors.verticalCenter: parent.verticalCenter
                                Layout.fillWidth: true
                                width: parent.width - 80
                            }
                            Text {
                                text: modelData.value
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                font.weight: Font.DemiBold
                                color: Theme.textPrimary
                                anchors.verticalCenter: parent.verticalCenter
                                horizontalAlignment: Text.AlignRight
                            }
                        }
                    }
                }
            }

            // VALIDATION
            Rectangle {
                width: parent.width - 2 * Theme.spacingXl
                height: valCol.height + 2 * Theme.spacingLg
                radius: Theme.radiusMd
                color: Qt.rgba(0.82, 0.60, 0.13, 0.08)
                border.color: Qt.rgba(0.82, 0.60, 0.13, 0.3)
                border.width: 1
                antialiasing: true

                Column {
                    id: valCol
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
                            text: "Valence Check"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSm
                            font.weight: Font.DemiBold
                            color: Theme.accentAmber
                        }
                    }
                    Text {
                        text: "All atoms satisfy standard valence rules."
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                        wrapMode: Text.WordWrap
                        width: parent.width
                    }
                }
            }

            // RECENT VERSIONS
            Column {
                width: parent.width - 2 * Theme.spacingXl
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

            // CTA button
            Rectangle {
                width: parent.width - 2 * Theme.spacingXl
                height: 44
                radius: Theme.radiusMd
                color: Theme.accentBlue
                antialiasing: true

                Rectangle {
                    anchors.fill: parent
                    anchors.margins: -8
                    radius: Theme.radiusMd + 8
                    color: Theme.accentBlue
                    opacity: 0.15
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
                    onContainsMouseChanged: parent.opacity = containsMouse ? 0.9 : 1.0
                }

                Behavior on opacity { NumberAnimation { duration: Theme.animFast } }
            }
        }
    }
}
