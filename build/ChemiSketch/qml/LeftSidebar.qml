import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root
    width: 240
    color: Theme.bgSurface

    property string activeTool: "single_bond"
    property string activeElement: "C"
    property int activeNavIndex: 0

    signal toolSelected(string tool)
    signal elementSelected(string element)

    Rectangle {
        anchors.right: parent.right
        width: 1
        height: parent.height
        color: Theme.border
    }

    Flickable {
        anchors.fill: parent
        anchors.rightMargin: 1
        contentHeight: sidebarColumn.height
        clip: true
        boundsBehavior: Flickable.StopAtBounds

        Column {
            id: sidebarColumn
            width: parent.width
            spacing: 0

            // Project card
            Rectangle {
                width: parent.width
                height: 64
                color: "transparent"

                Row {
                    anchors.fill: parent
                    anchors.margins: Theme.spacingLg
                    spacing: Theme.spacingMd

                    Rectangle {
                        width: 32; height: 32
                        radius: Theme.radiusSm
                        color: Theme.accentBlue
                        opacity: 0.15
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            anchors.centerIn: parent
                            text: "\u2697"
                            font.pixelSize: 16
                            color: Theme.accentBlue
                        }
                    }

                    Column {
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 2

                        Text {
                            text: "Research Unit 01"
                            font.family: Theme.fontFamily
                            font.pixelSize: Theme.fontSm
                            font.weight: Font.DemiBold
                            color: Theme.textPrimary
                        }
                        Text {
                            text: "ORGANIC SYNTHESIS"
                            font.family: Theme.fontFamily
                            font.pixelSize: 9
                            font.letterSpacing: 1.0
                            color: Theme.textMuted
                        }
                    }
                }

                Rectangle {
                    anchors.bottom: parent.bottom
                    width: parent.width
                    height: 1
                    color: Theme.border
                }
            }

            // Navigation items
            Column {
                width: parent.width
                topPadding: Theme.spacingSm
                bottomPadding: Theme.spacingSm

                Repeater {
                    model: [
                        { label: "Sketch", icon: "\u270E" },
                        { label: "3D View", icon: "\u2B22" },
                        { label: "Search Molecule", icon: "\u2315" }
                    ]

                    Rectangle {
                        width: parent.width
                        height: 36
                        color: "transparent"

                        // Active highlight pill
                        Rectangle {
                            anchors.left: parent.left
                            anchors.leftMargin: Theme.spacingSm
                            anchors.right: parent.right
                            anchors.rightMargin: Theme.spacingSm
                            anchors.verticalCenter: parent.verticalCenter
                            height: 32
                            radius: Theme.radiusSm
                            color: root.activeNavIndex === index ? Qt.rgba(0.31, 0.62, 1.0, 0.1) : (navItemMa.containsMouse ? Qt.rgba(1,1,1,0.04) : "transparent")

                            Behavior on color { ColorAnimation { duration: Theme.animFast } }
                        }

                        // Blue left border for active
                        Rectangle {
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            width: 3
                            height: 20
                            radius: 2
                            color: Theme.accentBlue
                            opacity: root.activeNavIndex === index ? 1.0 : 0.0
                            Behavior on opacity { NumberAnimation { duration: Theme.animNormal } }
                        }

                        Row {
                            anchors.left: parent.left
                            anchors.leftMargin: Theme.spacingLg + 4
                            anchors.verticalCenter: parent.verticalCenter
                            spacing: Theme.spacingMd

                            Text {
                                text: modelData.icon
                                font.pixelSize: 14
                                color: root.activeNavIndex === index ? Theme.accentBlue : Theme.textSecondary
                                Behavior on color { ColorAnimation { duration: Theme.animFast } }
                            }
                            Text {
                                text: modelData.label
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                font.weight: root.activeNavIndex === index ? Font.DemiBold : Font.Normal
                                color: root.activeNavIndex === index ? Theme.accentBlue : Theme.textSecondary
                                Behavior on color { ColorAnimation { duration: Theme.animFast } }
                            }
                        }

                        MouseArea {
                            id: navItemMa
                            anchors.fill: parent
                            hoverEnabled: true
                            cursorShape: Qt.PointingHandCursor
                            onClicked: root.activeNavIndex = index
                        }
                    }
                }

                Rectangle {
                    width: parent.width - 2 * Theme.spacingLg
                    height: 1
                    color: Theme.border
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            // Sketch tools (visible when Sketch nav active)
            // leftPadding/rightPadding removed — each section wrapped in an Item
            // that applies the margin via x + width so CollapsibleSection.width
            // resolves correctly through its own "width: parent.width" binding.
            Column {
                width: parent.width
                visible: root.activeNavIndex === 0
                spacing: Theme.spacingMd
                topPadding: Theme.spacingSm

                // BONDS section
                Item {
                    x: Theme.spacingLg
                    width: parent.width - 2 * Theme.spacingLg
                    height: bondsSection.height

                    CollapsibleSection {
                        id: bondsSection
                        title: "BONDS"

                        Grid {
                            columns: 2
                            spacing: Theme.spacingSm
                            width: parent.width

                            Repeater {
                                model: [
                                    { label: "Single", tool: "single_bond", icon: "\u2014" },
                                    { label: "Double", tool: "double_bond", icon: "=" },
                                    { label: "Triple", tool: "triple_bond", icon: "\u2261" },
                                    { label: "Aromatic", tool: "aromatic", icon: "\u25CB" }
                                ]

                                Rectangle {
                                    width: (parent.width - Theme.spacingSm) / 2
                                    height: 52
                                    radius: Theme.radiusSm
                                    color: root.activeTool === modelData.tool ? Qt.rgba(0.31, 0.62, 1.0, 0.12) : Theme.bgCard
                                    border.color: root.activeTool === modelData.tool ? Theme.accentBlue : Theme.border
                                    border.width: root.activeTool === modelData.tool ? 1.5 : 1
                                    antialiasing: true
                                    scale: root.activeTool === modelData.tool ? 1.05 : 1.0

                                    Behavior on scale {
                                        SpringAnimation { spring: 3; damping: 0.6 }
                                    }
                                    Behavior on border.color { ColorAnimation { duration: Theme.animFast } }

                                    Column {
                                        anchors.centerIn: parent
                                        spacing: 2

                                        Text {
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            text: modelData.icon
                                            font.pixelSize: 14
                                            color: root.activeTool === modelData.tool ? Theme.accentBlue : Theme.textSecondary
                                        }
                                        Text {
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            text: modelData.label
                                            font.family: Theme.fontFamily
                                            font.pixelSize: 11
                                            color: root.activeTool === modelData.tool ? Theme.accentBlue : Theme.textMuted
                                        }
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: {
                                            root.activeTool = modelData.tool
                                            root.toolSelected(modelData.tool)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                // ATOMS section
                Item {
                    x: Theme.spacingLg
                    width: parent.width - 2 * Theme.spacingLg
                    height: atomsSection.height

                    CollapsibleSection {
                        id: atomsSection
                        title: "ATOMS"

                        Flow {
                            width: parent.width
                            spacing: Theme.spacingXs

                            Repeater {
                                model: ["C", "N", "O", "S", "P", "F", "Cl", "Br", "I", "H"]

                                Rectangle {
                                    width: modelData.length > 1 ? 36 : 30
                                    height: 28
                                    radius: Theme.radiusPill
                                    color: root.activeElement === modelData ? Theme.accentBlue : Theme.bgCard
                                    border.color: root.activeElement === modelData ? Theme.accentBlue : Theme.border
                                    border.width: 1
                                    antialiasing: true

                                    Behavior on color { ColorAnimation { duration: Theme.animFast } }

                                    Text {
                                        anchors.centerIn: parent
                                        text: modelData
                                        font.family: Theme.fontFamily
                                        font.pixelSize: Theme.fontSm
                                        font.weight: Font.DemiBold
                                        color: root.activeElement === modelData ? "#FFFFFF" : Theme.textPrimary
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: {
                                            root.activeElement = modelData
                                            root.elementSelected(modelData)
                                        }
                                    }
                                }
                            }

                            // + More button
                            Rectangle {
                                width: 50; height: 28
                                radius: Theme.radiusPill
                                color: "transparent"
                                border.color: Theme.border
                                border.width: 1

                                Text {
                                    anchors.centerIn: parent
                                    text: "+ More"
                                    font.family: Theme.fontFamily
                                    font.pixelSize: 9
                                    color: Theme.textSecondary
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    cursorShape: Qt.PointingHandCursor
                                }
                            }
                        }
                    }
                }

                // TOOLS section
                Item {
                    x: Theme.spacingLg
                    width: parent.width - 2 * Theme.spacingLg
                    height: toolsSection.height

                    CollapsibleSection {
                        id: toolsSection
                        title: "TOOLS"

                        Grid {
                            columns: 3
                            spacing: Theme.spacingSm
                            width: parent.width

                            Repeater {
                                model: [
                                    { label: "Eraser", tool: "eraser", icon: "\u2421" },
                                    { label: "Lasso", tool: "lasso", icon: "\u2B55" },
                                    { label: "Move", tool: "move", icon: "\u2725" },
                                    { label: "Charge+", tool: "charge_plus", icon: "\u207A" },
                                    { label: "Charge-", tool: "charge_minus", icon: "\u207B" },
                                    { label: "Clean", tool: "clean", icon: "\u2728" }
                                ]

                                Rectangle {
                                    width: (parent.width - 2 * Theme.spacingSm) / 3
                                    height: 44
                                    radius: Theme.radiusSm
                                    color: root.activeTool === modelData.tool ? Qt.rgba(0.31, 0.62, 1.0, 0.12) : Theme.bgCard
                                    border.color: root.activeTool === modelData.tool ? Theme.accentBlue : Theme.border
                                    border.width: 1
                                    antialiasing: true

                                    Column {
                                        anchors.centerIn: parent
                                        spacing: 1

                                        Text {
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            text: modelData.icon
                                            font.pixelSize: 12
                                            color: root.activeTool === modelData.tool ? Theme.accentBlue : Theme.textSecondary
                                        }
                                        Text {
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            text: modelData.label
                                            font.family: Theme.fontFamily
                                            font.pixelSize: 10
                                            color: Theme.textMuted
                                        }
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: {
                                            root.activeTool = modelData.tool
                                            root.toolSelected(modelData.tool)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                // RING TEMPLATES section
                Item {
                    x: Theme.spacingLg
                    width: parent.width - 2 * Theme.spacingLg
                    height: ringSection.height

                    CollapsibleSection {
                        id: ringSection
                        title: "RING TEMPLATES"

                        Row {
                            spacing: Theme.spacingSm
                            width: parent.width

                            Repeater {
                                model: [
                                    { label: "Benzene", tool: "benzene" },
                                    { label: "Cyclohexane", tool: "cyclohexane" },
                                    { label: "Cyclopentane", tool: "cyclopentane" }
                                ]

                                Rectangle {
                                    width: (parent.width - 2 * Theme.spacingSm) / 3
                                    height: 56
                                    radius: Theme.radiusSm
                                    color: root.activeTool === modelData.tool ? Qt.rgba(0.31, 0.62, 1.0, 0.12) : Theme.bgCard
                                    border.color: root.activeTool === modelData.tool ? Theme.accentBlue : Theme.border
                                    border.width: root.activeTool === modelData.tool ? 1.5 : 1
                                    antialiasing: true

                                    Column {
                                        anchors.centerIn: parent
                                        spacing: 4

                                        // Simple ring icon
                                        Rectangle {
                                            width: 24; height: 24
                                            radius: modelData.tool === "cyclopentane" ? 12 : 4
                                            color: "transparent"
                                            border.color: root.activeTool === modelData.tool ? Theme.accentBlue : Theme.textSecondary
                                            border.width: 1.5
                                            anchors.horizontalCenter: parent.horizontalCenter
                                        }

                                        Text {
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            text: modelData.label
                                            font.family: Theme.fontFamily
                                            font.pixelSize: 8
                                            color: root.activeTool === modelData.tool ? Theme.accentBlue : Theme.textMuted
                                        }
                                    }

                                    MouseArea {
                                        anchors.fill: parent
                                        cursorShape: Qt.PointingHandCursor
                                        onClicked: {
                                            root.activeTool = modelData.tool
                                            root.toolSelected(modelData.tool)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                // AI ASSIST section
                Item {
                    x: Theme.spacingLg
                    width: parent.width - 2 * Theme.spacingLg
                    height: aiSection.height

                    CollapsibleSection {
                        id: aiSection
                        title: "AI ASSIST"

                        Rectangle {
                            width: parent.width
                            height: 56
                            radius: Theme.radiusMd
                            antialiasing: true

                            gradient: Gradient {
                                GradientStop { position: 0.0; color: Qt.rgba(0.64, 0.44, 0.97, 0.15) }
                                GradientStop { position: 1.0; color: Qt.rgba(0.64, 0.44, 0.97, 0.05) }
                            }

                            border.color: Qt.rgba(0.64, 0.44, 0.97, 0.3)
                            border.width: 1

                            Row {
                                anchors.centerIn: parent
                                spacing: Theme.spacingSm

                                Text {
                                    text: "\u2728"
                                    font.pixelSize: 16
                                    color: Theme.accentPurple
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                                Text {
                                    text: "Suggest Structure"
                                    font.family: Theme.fontFamily
                                    font.pixelSize: Theme.fontSm
                                    font.weight: Font.DemiBold
                                    color: Theme.accentPurple
                                    anchors.verticalCenter: parent.verticalCenter
                                }
                            }

                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                            }
                        }
                    }
                }
            }

            // Spacer
            Item {
                width: parent.width
                height: Theme.spacingLg
            }

            // Bottom section: Active Experiment
            Rectangle {
                width: parent.width
                height: activeExpCol.height + 2 * Theme.spacingLg
                color: "transparent"

                Rectangle {
                    anchors.top: parent.top
                    width: parent.width
                    height: 1
                    color: Theme.border
                }

                Column {
                    id: activeExpCol
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.margins: Theme.spacingLg
                    anchors.topMargin: Theme.spacingLg
                    spacing: Theme.spacingSm

                    Text {
                        text: "ACTIVE EXPERIMENT"
                        font.family: Theme.fontFamily
                        font.pixelSize: 9
                        font.letterSpacing: 1.0
                        color: Theme.textMuted
                    }

                    Text {
                        text: "Aspirin Synthesis"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontMd
                        font.weight: Font.Bold
                        color: Theme.textPrimary
                    }

                    // Progress bar
                    Rectangle {
                        width: parent.width
                        height: 4
                        radius: 2
                        color: Theme.bgCard

                        Rectangle {
                            width: parent.width * 0.65
                            height: parent.height
                            radius: 2
                            color: Theme.accentBlue
                        }
                    }

                    Row {
                        spacing: Theme.spacingSm

                        Rectangle {
                            width: 20; height: 20
                            radius: 10
                            color: Theme.accentGreen
                            anchors.verticalCenter: parent.verticalCenter

                            Text {
                                anchors.centerIn: parent
                                text: "J"
                                font.family: Theme.fontFamily
                                font.pixelSize: 9
                                font.bold: true
                                color: "#FFFFFF"
                            }
                        }

                        Column {
                            spacing: 1

                            Text {
                                text: "Dr. J. Smith"
                                font.family: Theme.fontFamily
                                font.pixelSize: Theme.fontSm
                                color: Theme.textPrimary
                            }
                            Text {
                                text: "Lead Researcher"
                                font.family: Theme.fontFamily
                                font.pixelSize: 9
                                color: Theme.textMuted
                            }
                        }
                    }
                }
            }
        }
    }
}
