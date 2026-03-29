import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ChemiSketch 1.0

ApplicationWindow {
    id: root
    width: 1440
    height: 900
    visible: true
    title: "ChemiSketch"
    color: Theme.bgBase

    ChemController {
        id: controller

        onActiveToolChanged: {
            AppState.activeTool = controller.activeTool
        }
    }

    BondValidator {
        id: bondValidator
        controller: controller
    }

    // Cache moleculeInfo in a local property with null guard.
    // This prevents repeated evaluation of the binding during view transitions.
    property var safeInfo: ({})

    Connections {
        target: controller
        function onMoleculeInfoChanged() {
            var info = controller.moleculeInfo
            if (info) {
                root.safeInfo = info
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        TopMenuBar {
            Layout.fillWidth: true
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            LeftSidebar {
                Layout.fillHeight: true
                activeTool: AppState.activeTool
                activeNavIndex: AppState.activeNav
                onToolSelected: function(tool) {
                    AppState.setActiveTool(tool)
                    controller.activeTool = tool
                }
                onElementSelected: function(element) {
                    AppState.setActiveElement(element)
                    controller.setActiveElement(element)
                }
                onActiveNavIndexChanged: {
                    AppState.setActiveNav(activeNavIndex)
                }
            }

            // Canvas area (center)
            Item {
                id: canvasArea
                Layout.fillWidth: true
                Layout.fillHeight: true

                // Both views always exist in memory — use visible, never Loader
                SketchView {
                    id: sketchView
                    anchors.fill: parent
                    controller: controller
                    visible: AppState.activeTab !== 3
                    opacity: visible ? 1.0 : 0.0
                    Behavior on opacity { NumberAnimation { duration: Theme.animNormal } }
                }

                PropertiesView {
                    id: propertiesView
                    anchors.fill: parent
                    moleculeInfo: root.safeInfo
                    visible: AppState.activeTab === 3
                    opacity: visible ? 1.0 : 0.0
                    Behavior on opacity { NumberAnimation { duration: Theme.animNormal } }
                }

                BottomTabBar {
                    id: bottomTabBar
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottomMargin: Theme.spacingLg
                    currentIndex: AppState.activeTab
                    onTabClicked: function(index) {
                        AppState.setActiveTab(index)
                    }
                }
            }

            // Right Panel — always in memory, toggle visibility only
            RightPanel {
                id: rightPanel
                Layout.fillHeight: true
                moleculeInfo: root.safeInfo
                visible: AppState.activeTab !== 3
            }
        }
    }
}
