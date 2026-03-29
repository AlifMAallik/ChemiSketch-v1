import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ChemiSketch 1.0

ApplicationWindow {
    id: root
    width: 1024
    height: 768
    visible: true
    title: "ChemiSketch"
    color: controller.isDarkTheme ? "#1E1E2F" : "#FFFFFF"

    ChemController {
        id: controller
    }

    header: ToolBar {
        background: Rectangle {
            color: controller.isDarkTheme ? "#2A2A3D" : "#F0F0F0"
        }

        RowLayout {
            anchors.fill: parent
            anchors.margins: 4

            Label {
                text: "ChemiSketch"
                font.pixelSize: 18
                font.bold: true
                color: controller.isDarkTheme ? "#FFFFFF" : "#333333"
            }

            Item { Layout.fillWidth: true }

            // Tool selector
            ComboBox {
                id: toolSelector
                model: [
                    "single_bond", "double_bond", "triple_bond",
                    "benzene", "wedge", "hash", "dashed",
                    "arrow", "aromatic", "eraser"
                ]
                currentIndex: 0
                onCurrentTextChanged: controller.activeTool = currentText

                Layout.preferredWidth: 150
            }

            Button {
                text: "Clear"
                onClicked: controller.clearCanvas()
            }

            Button {
                text: controller.isDarkTheme ? "Light" : "Dark"
                onClicked: controller.isDarkTheme = !controller.isDarkTheme
            }
        }
    }

    StackLayout {
        id: mainStack
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        DrawScreen {
            controller: controller
        }

        CameraScreen {}
    }

    footer: TabBar {
        id: tabBar
        background: Rectangle {
            color: controller.isDarkTheme ? "#2A2A3D" : "#F0F0F0"
        }

        TabButton {
            text: "Sketch"
            width: implicitWidth
        }
        TabButton {
            text: "Camera"
            width: implicitWidth
        }
    }
}
