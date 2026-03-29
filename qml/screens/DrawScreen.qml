import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ChemiSketch 1.0

Item {
    id: drawScreen

    required property ChemController controller

    RowLayout {
        anchors.fill: parent
        spacing: 0

        // Drawing canvas
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: controller.isDarkTheme ? "#1E1E2F" : "#FAFAFA"
            clip: true

            Canvas {
                id: canvas
                anchors.fill: parent

                property var atomData: []
                property var bondData: []
                property var tempLine: ({})

                function refresh() {
                    atomData = controller.getAtomRenderData()
                    bondData = controller.getBondRenderData()
                    tempLine = controller.getTempLine()
                    requestPaint()
                }

                Component.onCompleted: refresh()

                Connections {
                    target: controller
                    function onCanvasNeedsRepaint() { canvas.refresh() }
                }

                onPaint: {
                    var ctx = getContext("2d")
                    ctx.reset()
                    ctx.clearRect(0, 0, width, height)

                    var zoom = controller.zoomFactor

                    // Draw bonds
                    for (var i = 0; i < bondData.length; i++) {
                        var b = bondData[i]
                        ctx.strokeStyle = b.isInvalid ? "#FF3333" : (controller.isDarkTheme ? "#CCCCCC" : "#333333")
                        ctx.lineWidth = 2

                        var x1 = b.x1 * zoom, y1 = b.y1 * zoom
                        var x2 = b.x2 * zoom, y2 = b.y2 * zoom

                        if (b.type === "single" || b.type === "wedge" ||
                            b.type === "hash" || b.type === "dashed" || b.type === "arrow") {
                            ctx.beginPath()
                            if (b.type === "dashed") {
                                ctx.setLineDash([5, 5])
                            } else {
                                ctx.setLineDash([])
                            }
                            ctx.moveTo(x1, y1)
                            ctx.lineTo(x2, y2)
                            ctx.stroke()
                            ctx.setLineDash([])
                        } else if (b.type === "double") {
                            var dx = x2 - x1, dy = y2 - y1
                            var len = Math.sqrt(dx*dx + dy*dy)
                            if (len > 0) {
                                var nx = -dy/len * 3, ny = dx/len * 3
                                ctx.beginPath()
                                ctx.moveTo(x1+nx, y1+ny); ctx.lineTo(x2+nx, y2+ny)
                                ctx.stroke()
                                ctx.beginPath()
                                ctx.moveTo(x1-nx, y1-ny); ctx.lineTo(x2-nx, y2-ny)
                                ctx.stroke()
                            }
                        } else if (b.type === "triple") {
                            var tdx = x2 - x1, tdy = y2 - y1
                            var tlen = Math.sqrt(tdx*tdx + tdy*tdy)
                            if (tlen > 0) {
                                var tnx = -tdy/tlen * 4, tny = tdx/tlen * 4
                                ctx.beginPath()
                                ctx.moveTo(x1, y1); ctx.lineTo(x2, y2)
                                ctx.stroke()
                                ctx.beginPath()
                                ctx.moveTo(x1+tnx, y1+tny); ctx.lineTo(x2+tnx, y2+tny)
                                ctx.stroke()
                                ctx.beginPath()
                                ctx.moveTo(x1-tnx, y1-tny); ctx.lineTo(x2-tnx, y2-tny)
                                ctx.stroke()
                            }
                        } else if (b.type === "aromatic") {
                            var adx = x2 - x1, ady = y2 - y1
                            var alen = Math.sqrt(adx*adx + ady*ady)
                            if (alen > 0) {
                                var anx = -ady/alen * 3, any = adx/alen * 3
                                ctx.setLineDash([4, 4])
                                ctx.beginPath()
                                ctx.moveTo(x1+anx, y1+any); ctx.lineTo(x2+anx, y2+any)
                                ctx.stroke()
                                ctx.beginPath()
                                ctx.moveTo(x1-anx, y1-any); ctx.lineTo(x2-anx, y2-any)
                                ctx.stroke()
                                ctx.setLineDash([])
                            }
                        }
                    }

                    // Draw temp line (bond in progress)
                    if (tempLine.visible) {
                        ctx.strokeStyle = "#6699FF"
                        ctx.lineWidth = 1.5
                        ctx.setLineDash([4, 4])
                        ctx.beginPath()
                        ctx.moveTo(tempLine.x1 * zoom, tempLine.y1 * zoom)
                        ctx.lineTo(tempLine.x2 * zoom, tempLine.y2 * zoom)
                        ctx.stroke()
                        ctx.setLineDash([])
                    }

                    // Draw atoms (label non-carbon atoms)
                    for (var j = 0; j < atomData.length; j++) {
                        var a = atomData[j]
                        var ax = a.x * zoom, ay = a.y * zoom

                        if (a.highlighted) {
                            ctx.fillStyle = "rgba(100, 200, 255, 0.3)"
                            ctx.beginPath()
                            ctx.arc(ax, ay, 15, 0, 2 * Math.PI)
                            ctx.fill()
                        }

                        // Show element label for non-carbon atoms
                        if (a.element !== "C" || a.bondCount === 0) {
                            ctx.fillStyle = a.color || (controller.isDarkTheme ? "#FFFFFF" : "#333333")
                            ctx.font = "bold 14px sans-serif"
                            ctx.textAlign = "center"
                            ctx.textBaseline = "middle"
                            ctx.fillText(a.element, ax, ay)
                        }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton
                    preventStealing: true

                    onPressed: function(mouse) {
                        controller.canvasPressed(Qt.point(mouse.x / controller.zoomFactor,
                                                          mouse.y / controller.zoomFactor))
                    }
                    onPositionChanged: function(mouse) {
                        controller.canvasDragged(Qt.point(mouse.x / controller.zoomFactor,
                                                          mouse.y / controller.zoomFactor))
                    }
                    onReleased: function(mouse) {
                        controller.canvasReleased(Qt.point(mouse.x / controller.zoomFactor,
                                                           mouse.y / controller.zoomFactor))
                    }
                    onWheel: function(wheel) {
                        if (wheel.angleDelta.y > 0) controller.zoomIn()
                        else controller.zoomOut()
                    }
                }
            }
        }

        // Info sidebar
        Rectangle {
            Layout.preferredWidth: 220
            Layout.fillHeight: true
            color: controller.isDarkTheme ? "#252538" : "#F5F5F5"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 8

                Label {
                    text: "Molecule Info"
                    font.bold: true
                    font.pixelSize: 14
                    color: controller.isDarkTheme ? "#FFFFFF" : "#333333"
                }

                Rectangle {
                    Layout.fillWidth: true
                    height: 1
                    color: controller.isDarkTheme ? "#444466" : "#DDDDDD"
                }

                Label {
                    text: "Formula: " + (controller.moleculeInfo.formula || "—")
                    color: controller.isDarkTheme ? "#CCCCCC" : "#555555"
                    wrapMode: Text.Wrap
                    Layout.fillWidth: true
                }

                Label {
                    text: "Weight: " + (controller.moleculeInfo.molecularWeight
                          ? controller.moleculeInfo.molecularWeight.toFixed(2) : "—")
                    color: controller.isDarkTheme ? "#CCCCCC" : "#555555"
                }

                Label {
                    text: "Atoms: " + (controller.moleculeInfo.atomCount || 0)
                    color: controller.isDarkTheme ? "#CCCCCC" : "#555555"
                }

                Label {
                    text: "Bonds: " + (controller.moleculeInfo.bondCount || 0)
                    color: controller.isDarkTheme ? "#CCCCCC" : "#555555"
                }

                Label {
                    text: "Electrons: " + (controller.moleculeInfo.electronCount || 0)
                    color: controller.isDarkTheme ? "#CCCCCC" : "#555555"
                }

                Label {
                    text: "Type: " + (controller.moleculeInfo.classification || "—")
                    color: controller.isDarkTheme ? "#CCCCCC" : "#555555"
                    wrapMode: Text.Wrap
                    Layout.fillWidth: true
                }

                Label {
                    text: "Valid: " + (controller.moleculeInfo.isValid ? "Yes" : "No")
                    color: controller.moleculeInfo.isValid
                           ? (controller.isDarkTheme ? "#66FF66" : "#228B22")
                           : "#FF3333"
                }

                Item { Layout.fillHeight: true }
            }
        }
    }
}
