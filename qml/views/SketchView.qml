import QtQuick
import QtQuick.Layouts
import ChemiSketch 1.0

Item {
    id: root

    required property ChemController controller

    // Canvas background
    Rectangle {
        anchors.fill: parent
        color: Theme.bgCanvas
    }

    // Dot grid pattern
    Canvas {
        id: dotGrid
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)
            ctx.fillStyle = Qt.rgba(1, 1, 1, 0.06)
            var spacing = 24
            for (var x = spacing; x < width; x += spacing) {
                for (var y = spacing; y < height; y += spacing) {
                    ctx.beginPath()
                    ctx.arc(x, y, 1, 0, 2 * Math.PI)
                    ctx.fill()
                }
            }
        }

        onWidthChanged: requestPaint()
        onHeightChanged: requestPaint()
    }

    // Molecule canvas
    Canvas {
        id: canvas
        anchors.fill: parent

        property var atomData: []
        property var bondData: []
        property var tempLine: ({})

        function refresh() {
            atomData = root.controller.getAtomRenderData()
            bondData = root.controller.getBondRenderData()
            tempLine = root.controller.getTempLine()
            requestPaint()
        }

        Component.onCompleted: refresh()

        Connections {
            target: root.controller
            function onCanvasNeedsRepaint() { canvas.refresh() }
        }

        onPaint: {
            var ctx = getContext("2d")
            ctx.reset()
            ctx.clearRect(0, 0, width, height)

            var zoom = root.controller.zoomFactor

            // Draw bonds
            for (var i = 0; i < bondData.length; i++) {
                var b = bondData[i]
                ctx.strokeStyle = b.isInvalid ? "#FF3333" : "#FFFFFF"
                ctx.lineWidth = 1.5

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
                        var anx = -ady/alen * 3, any_ = adx/alen * 3
                        ctx.setLineDash([4, 4])
                        ctx.beginPath()
                        ctx.moveTo(x1+anx, y1+any_); ctx.lineTo(x2+anx, y2+any_)
                        ctx.stroke()
                        ctx.beginPath()
                        ctx.moveTo(x1-anx, y1-any_); ctx.lineTo(x2-anx, y2-any_)
                        ctx.stroke()
                        ctx.setLineDash([])
                    }
                }
            }

            // Temp line
            if (tempLine.visible) {
                ctx.strokeStyle = Theme.accentBlue
                ctx.lineWidth = 1.5
                ctx.setLineDash([4, 4])
                ctx.beginPath()
                ctx.moveTo(tempLine.x1 * zoom, tempLine.y1 * zoom)
                ctx.lineTo(tempLine.x2 * zoom, tempLine.y2 * zoom)
                ctx.stroke()
                ctx.setLineDash([])
            }

            // Draw atoms
            for (var j = 0; j < atomData.length; j++) {
                var a = atomData[j]
                var ax = a.x * zoom, ay = a.y * zoom

                // Atom node circle
                ctx.strokeStyle = Theme.accentBlue
                ctx.lineWidth = 1.5
                ctx.beginPath()
                ctx.arc(ax, ay, 8, 0, 2 * Math.PI)
                ctx.stroke()

                // Highlighted = selected atom (orange fill)
                if (a.highlighted) {
                    ctx.fillStyle = Qt.rgba(0.82, 0.60, 0.13, 0.8)
                    ctx.beginPath()
                    ctx.arc(ax, ay, 8, 0, 2 * Math.PI)
                    ctx.fill()
                }

                // Element label
                if (a.element !== "C" || a.bondCount === 0) {
                    ctx.fillStyle = "#FFFFFF"
                    ctx.font = "bold 11px Inter, sans-serif"
                    ctx.textAlign = "center"
                    ctx.textBaseline = "middle"
                    ctx.fillText(a.element, ax, ay)
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton

            onPressed: function(mouse) {
                root.controller.canvasPressed(Qt.point(mouse.x / root.controller.zoomFactor,
                                                       mouse.y / root.controller.zoomFactor))
            }
            onPositionChanged: function(mouse) {
                root.controller.canvasDragged(Qt.point(mouse.x / root.controller.zoomFactor,
                                                       mouse.y / root.controller.zoomFactor))
            }
            onReleased: function(mouse) {
                root.controller.canvasReleased(Qt.point(mouse.x / root.controller.zoomFactor,
                                                        mouse.y / root.controller.zoomFactor))
            }
            onWheel: function(wheel) {
                if (wheel.angleDelta.y > 0) root.controller.zoomIn()
                else root.controller.zoomOut()
            }
        }
    }

    // Floating Metadata Card (top-right)
    Rectangle {
        id: metadataCard
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: Theme.spacingLg
        anchors.rightMargin: Theme.spacingLg
        width: 220
        height: metadataCol.height + 2 * Theme.spacingLg
        radius: Theme.radiusLg
        color: Qt.rgba(0.11, 0.13, 0.16, 0.92)
        border.color: Theme.border
        border.width: 1
        antialiasing: true

        opacity: 0.0
        Component.onCompleted: opacity = 1.0
        Behavior on opacity { NumberAnimation { duration: Theme.animNormal } }

        Column {
            id: metadataCol
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: Theme.spacingLg
            spacing: Theme.spacingMd

            Text {
                text: "MOLECULAR METADATA"
                font.family: Theme.fontFamily
                font.pixelSize: 9
                font.letterSpacing: 1.0
                color: Theme.textMuted
            }

            Column {
                width: parent.width
                spacing: Theme.spacingSm

                // Name row
                Row {
                    width: parent.width
                    Text {
                        text: "Name"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                        width: 70
                    }
                    Text {
                        text: root.controller.moleculeInfo.formula ? "Molecule" : "\u2014"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        font.weight: Font.DemiBold
                        color: Theme.textPrimary
                    }
                }

                // Molar Mass row
                Row {
                    width: parent.width
                    Text {
                        text: "Molar Mass"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                        width: 70
                    }
                    Text {
                        text: root.controller.moleculeInfo.molecularWeight
                              ? root.controller.moleculeInfo.molecularWeight.toFixed(2) + " g/mol"
                              : "\u2014"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        font.weight: Font.DemiBold
                        color: Theme.textPrimary
                    }
                }

                // LogP row
                Row {
                    width: parent.width
                    Text {
                        text: "LogP"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                        width: 70
                    }
                    Text {
                        text: "1.24"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        font.weight: Font.DemiBold
                        color: Theme.accentAmber
                    }
                }
            }
        }
    }

    // Floating toolbar (top-left)
    Rectangle {
        id: floatingToolbar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: Theme.spacingLg
        anchors.leftMargin: Theme.spacingLg
        width: toolbarRow.width + 2 * Theme.spacingMd
        height: 40
        radius: Theme.radiusPill
        color: Theme.bgCard
        border.color: Theme.border
        border.width: 1
        antialiasing: true

        opacity: 0.0
        Component.onCompleted: opacity = 1.0
        Behavior on opacity { NumberAnimation { duration: Theme.animNormal } }

        Row {
            id: toolbarRow
            anchors.centerIn: parent
            spacing: 4

            Repeater {
                model: [
                    { icon: "\u270E", tool: "pen", active: true },
                    { icon: "\u25A1", tool: "select", active: false },
                    { icon: "\u2B21", tool: "shape", active: false },
                    { icon: "T", tool: "text", active: false },
                    { icon: "\u2316", tool: "measure", active: false }
                ]

                Rectangle {
                    property bool isActive: index === 0
                    width: 32; height: 32
                    radius: Theme.radiusSm
                    color: isActive ? Theme.accentBlue : (ftbMa.containsMouse ? Qt.rgba(1,1,1,0.08) : "transparent")
                    antialiasing: true

                    Behavior on color { ColorAnimation { duration: Theme.animFast } }

                    Text {
                        anchors.centerIn: parent
                        text: modelData.icon
                        font.pixelSize: 14
                        color: isActive ? "#FFFFFF" : Theme.textSecondary
                    }

                    MouseArea {
                        id: ftbMa
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                    }
                }
            }
        }
    }

    // Bottom status badges
    Row {
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.bottomMargin: Theme.spacingLg + 80  // above bottom tab bar
        anchors.leftMargin: Theme.spacingLg
        spacing: Theme.spacingSm

        Rectangle {
            width: statusText1.implicitWidth + 20
            height: 28
            radius: Theme.radiusPill
            color: Theme.bgCard
            border.color: Theme.border
            border.width: 1
            antialiasing: true

            Text {
                id: statusText1
                anchors.centerIn: parent
                text: "\u25CF  LIVE RENDER ACTIVE"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontXs
                color: Theme.accentGreen
            }
        }

        Rectangle {
            width: statusText2.implicitWidth + 20
            height: 28
            radius: Theme.radiusPill
            color: Theme.bgCard
            border.color: Theme.border
            border.width: 1
            antialiasing: true

            Text {
                id: statusText2
                anchors.centerIn: parent
                text: "RESOLUTION: 2.4\u00C5"
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontXs
                color: Theme.textSecondary
            }
        }
    }
}
