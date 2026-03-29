import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root
    width: 280
    color: Theme.bgSurface

    property var moleculeInfo: ({})

    // Safe accessors that never crash on null/undefined
    readonly property int safeAtomCount: (moleculeInfo && moleculeInfo.atomCount) ? moleculeInfo.atomCount : 0
    readonly property int safeBondCount: (moleculeInfo && moleculeInfo.bondCount) ? moleculeInfo.bondCount : 0
    readonly property string safeFormula: (moleculeInfo && moleculeInfo.formula) ? moleculeInfo.formula : "\u2014"
    readonly property string safeWeight: (moleculeInfo && moleculeInfo.molecularWeight) ? moleculeInfo.molecularWeight.toFixed(2) + " g/mol" : "\u2014"
    readonly property string safeClassification: (moleculeInfo && moleculeInfo.classification) ? moleculeInfo.classification : "\u2014"
    readonly property bool safeIsValid: (moleculeInfo && moleculeInfo.isValid !== undefined) ? moleculeInfo.isValid : true

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
                                text: root.safeAtomCount.toString()
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontXxl
                                font.weight: Font.Bold
                                color: Theme.textPrimary
                            }
                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: "Atoms"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontXs
                                color: Theme.textSecondary
                            }
                        }
                    }

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
                                text: root.safeBondCount.toString()
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontXxl
                                font.weight: Font.Bold
                                color: Theme.textPrimary
                            }
                            Text {
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: "Bonds"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontXs
                                color: Theme.textSecondary
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
                    color: root.safeIsValid ? Qt.rgba(0.25, 0.72, 0.31, 0.08) : Qt.rgba(0.82, 0.60, 0.13, 0.08)
                    border.color: root.safeIsValid ? Qt.rgba(0.25, 0.72, 0.31, 0.3) : Qt.rgba(0.82, 0.60, 0.13, 0.3)
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
                                text: root.safeIsValid ? "\u2713" : "\u26A0"
                                font.pixelSize: 14
                                color: root.safeIsValid ? Theme.accentGreen : Theme.accentAmber
                            }
                            Text {
                                text: root.safeIsValid ? "Structure Valid" : "Valence Warning"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                font.weight: Font.DemiBold
                                color: root.safeIsValid ? Theme.accentGreen : Theme.accentAmber
                            }
                        }

                        Text {
                            text: root.safeIsValid
                                  ? "Structure passes all valence checks."
                                  : "Check atom valences \u2014 some atoms may have unusual bonding."
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
                                text: "Formula"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                color: Theme.textSecondary
                                anchors.verticalCenter: parent.verticalCenter
                                width: 60
                            }
                            Text {
                                text: root.safeFormula
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                font.weight: Font.DemiBold
                                color: Theme.textPrimary
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }

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
                                text: "Weight"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                color: Theme.textSecondary
                                anchors.verticalCenter: parent.verticalCenter
                                width: 60
                            }
                            Text {
                                text: root.safeWeight
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                font.weight: Font.DemiBold
                                color: Theme.textPrimary
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }

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
                                text: "Type"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                color: Theme.textSecondary
                                anchors.verticalCenter: parent.verticalCenter
                                width: 60
                            }
                            Text {
                                text: root.safeClassification
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
