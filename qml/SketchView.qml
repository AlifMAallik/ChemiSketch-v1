import QtQuick
import QtQuick.Layouts
import ChemiSketch 1.0

Item {
    id: root

    required property ChemController controller

    // Track rejected atom flash
    property string rejectedAtomId: ""
    property real rejectedX: 0
    property real rejectedY: 0

    Connections {
        target: root.controller
        function onBondRejected(atomId, x, y) {
            root.rejectedAtomId = atomId
            root.rejectedX = x
            root.rejectedY = y
            rejectFlash.restart()
        }
    }

    SequentialAnimation {
        id: rejectFlash
        PropertyAnimation {
            target: rejectIndicator; property: "opacity"
            from: 0.0; to: 0.8; duration: 80
        }
        PropertyAnimation {
            target: rejectIndicator; property: "scale"
            from: 0.5; to: 1.5; duration: 150
        }
        PropertyAnimation {
            target: rejectIndicator; property: "opacity"
            from: 0.8; to: 0.0; duration: 300
        }
        onFinished: root.rejectedAtomId = ""
    }

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

        onWidthChanged:  requestPaint()
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
            if (!root.controller) return
            atomData = root.controller.getAtomRenderData()
            bondData = root.controller.getBondRenderData()
            tempLine = root.controller.getTempLine()
            requestPaint()
        }

        Component.onCompleted: refresh()

        Connections {
            target: root.controller
            function onCanvasNeedsRepaint() {
                if (canvas) canvas.refresh()
            }
        }

        onPaint: {
            var ctx = getContext("2d")

            // ── FIX: use clearRect instead of ctx.reset() ──────────────
            // ctx.reset() wipes font, strokeStyle, lineWidth etc. every
            // frame causing flicker and inconsistent text rendering.
            // clearRect only clears pixel data, preserving the context state.
            // ───────────────────────────────────────────────────────────
            ctx.clearRect(0, 0, width, height)

            if (!root.controller) return
            var zoom = root.controller.zoomFactor
            var atomR = 8  // atom circle radius in canvas pixels

            // ── Draw bonds ──────────────────────────────────────────────
            ctx.lineWidth = 1.5
            ctx.setLineDash([])

            for (var i = 0; i < bondData.length; i++) {
                var b = bondData[i]
                if (!b) continue

                ctx.strokeStyle = b.isInvalid ? "#FF3333" : "#AAAAAA"

                var x1 = b.x1 * zoom
                var y1 = b.y1 * zoom
                var x2 = b.x2 * zoom
                var y2 = b.y2 * zoom

                // Shorten bond endpoints so lines don't go through atom circles
                var bdx = x2 - x1
                var bdy = y2 - y1
                var blen = Math.sqrt(bdx * bdx + bdy * bdy)
                if (blen < 2) continue  // atoms on top of each other, skip

                var ux = bdx / blen
                var uy = bdy / blen
                var margin = atomR + 2

                // Only shorten if bond is long enough
                if (blen > margin * 2) {
                    x1 = x1 + ux * margin
                    y1 = y1 + uy * margin
                    x2 = x2 - ux * margin
                    y2 = y2 - uy * margin
                }

                if (b.type === "single" || b.type === "wedge" ||
                    b.type === "hash"   || b.type === "arrow") {
                    ctx.setLineDash([])
                    ctx.beginPath()
                    ctx.moveTo(x1, y1)
                    ctx.lineTo(x2, y2)
                    ctx.stroke()

                } else if (b.type === "dashed") {
                    ctx.setLineDash([5, 5])
                    ctx.beginPath()
                    ctx.moveTo(x1, y1)
                    ctx.lineTo(x2, y2)
                    ctx.stroke()
                    ctx.setLineDash([])

                } else if (b.type === "double") {
                    var ddx = x2 - x1, ddy = y2 - y1
                    var dlen = Math.sqrt(ddx*ddx + ddy*ddy)
                    if (dlen > 0) {
                        var nx = -ddy/dlen * 3
                        var ny =  ddx/dlen * 3
                        ctx.setLineDash([])
                        ctx.beginPath()
                        ctx.moveTo(x1+nx, y1+ny)
                        ctx.lineTo(x2+nx, y2+ny)
                        ctx.stroke()
                        ctx.beginPath()
                        ctx.moveTo(x1-nx, y1-ny)
                        ctx.lineTo(x2-nx, y2-ny)
                        ctx.stroke()
                    }

                } else if (b.type === "triple") {
                    var tdx = x2 - x1, tdy = y2 - y1
                    var tlen = Math.sqrt(tdx*tdx + tdy*tdy)
                    if (tlen > 0) {
                        var tnx = -tdy/tlen * 4
                        var tny =  tdx/tlen * 4
                        ctx.setLineDash([])
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
                        var anx = -ady/alen * 3
                        var any_ = adx/alen * 3
                        ctx.setLineDash([])
                        ctx.beginPath()
                        ctx.moveTo(x1+anx, y1+any_); ctx.lineTo(x2+anx, y2+any_)
                        ctx.stroke()
                        ctx.setLineDash([4, 4])
                        ctx.beginPath()
                        ctx.moveTo(x1-anx, y1-any_); ctx.lineTo(x2-anx, y2-any_)
                        ctx.stroke()
                        ctx.setLineDash([])
                    }
                }
            }

            // ── Draw temp preview line while dragging ───────────────────
            if (tempLine && tempLine.visible) {
                ctx.strokeStyle = Theme.accentBlue
                ctx.lineWidth = 1.5
                ctx.setLineDash([4, 4])
                ctx.beginPath()
                ctx.moveTo(tempLine.x1 * zoom, tempLine.y1 * zoom)
                ctx.lineTo(tempLine.x2 * zoom, tempLine.y2 * zoom)
                ctx.stroke()
                ctx.setLineDash([])
            }

            // ── Draw atoms (on top of bonds) ─────────────────────────────
            for (var j = 0; j < atomData.length; j++) {
                var a = atomData[j]
                if (!a) continue
                var ax = a.x * zoom
                var ay = a.y * zoom

                // Background fill so bonds don't show through label area
                ctx.beginPath()
                ctx.arc(ax, ay, atomR, 0, 2 * Math.PI)
                ctx.fillStyle = Theme.bgCanvas
                ctx.fill()

                // Circle stroke
                ctx.beginPath()
                ctx.arc(ax, ay, atomR, 0, 2 * Math.PI)
                if (a.highlighted) {
                    ctx.strokeStyle = "#D4A017"
                    ctx.lineWidth = 2.5
                } else {
                    ctx.strokeStyle = Theme.accentBlue
                    ctx.lineWidth = 1.5
                }
                ctx.stroke()

                // Orange fill for highlighted/selected atom
                if (a.highlighted) {
                    ctx.beginPath()
                    ctx.arc(ax, ay, atomR, 0, 2 * Math.PI)
                    ctx.fillStyle = Qt.rgba(0.82, 0.60, 0.13, 0.6)
                    ctx.fill()
                }

                // Element label — always show
                // For carbon with bonds: show just a dot to keep it clean
                // For all others: show the symbol
                ctx.textAlign    = "center"
                ctx.textBaseline = "middle"

                if (a.element !== "C" || a.bondCount === 0) {
                    ctx.fillStyle = "#FFFFFF"
                    ctx.font = "bold 11px sans-serif"
                    ctx.fillText(a.element, ax, ay)
                } else {
                    // Carbon with bonds: just show a small dot
                    ctx.fillStyle = Theme.accentBlue
                    ctx.beginPath()
                    ctx.arc(ax, ay, 2, 0, 2 * Math.PI)
                    ctx.fill()
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton
            preventStealing: true
            propagateComposedEvents: false

            onPressed: function(mouse) {
                if (!root.controller) return
                root.controller.canvasPressed(
                    Qt.point(mouse.x / root.controller.zoomFactor,
                             mouse.y / root.controller.zoomFactor))
            }
            onPositionChanged: function(mouse) {
                if (!root.controller) return
                root.controller.canvasDragged(
                    Qt.point(mouse.x / root.controller.zoomFactor,
                             mouse.y / root.controller.zoomFactor))
            }
            onReleased: function(mouse) {
                if (!root.controller) return
                root.controller.canvasReleased(
                    Qt.point(mouse.x / root.controller.zoomFactor,
                             mouse.y / root.controller.zoomFactor))
                // Force an immediate extra refresh so the temp line
                // (dashed preview) is cleared in the same frame.
                canvas.refresh()
            }

            // ── KEY FIX ──────────────────────────────────────────────
            // onCanceled fires when the OS cancels the mouse/touch event
            // (e.g. macOS trackpad fast gestures, window focus loss).
            // Without this, m_isDragging stays true in C++ forever and
            // the dashed preview line gets stuck on screen.
            // ─────────────────────────────────────────────────────────
            onCanceled: {
                if (!root.controller) return
                // Pass current drag end position to finalize or cancel
                root.controller.canvasReleased(
                    Qt.point(mouseX / root.controller.zoomFactor,
                             mouseY / root.controller.zoomFactor))
                canvas.refresh()
            }
            onWheel: function(wheel) {
                if (!root.controller) return
                if (wheel.angleDelta.y > 0) root.controller.zoomIn()
                else root.controller.zoomOut()
            }
        }
    }

    // Red flash indicator for rejected bonds
    Rectangle {
        id: rejectIndicator
        width: 32; height: 32
        radius: 16
        color: "transparent"
        border.color: Theme.accentRed
        border.width: 3
        opacity: 0
        visible: opacity > 0
        x: root.rejectedX * (root.controller ? root.controller.zoomFactor : 1) - 16
        y: root.rejectedY * (root.controller ? root.controller.zoomFactor : 1) - 16
        antialiasing: true

        Rectangle {
            anchors.fill: parent
            radius: parent.radius
            color: Theme.accentRed
            opacity: 0.2
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

        property var info: root.controller ? root.controller.moleculeInfo : ({})

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

                Row {
                    width: parent.width
                    Text {
                        text: "Formula"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                        width: 80
                    }
                    Text {
                        text: (metadataCard.info && metadataCard.info.formula)
                              ? metadataCard.info.formula : "\u2014"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        font.weight: Font.DemiBold
                        color: Theme.textPrimary
                    }
                }

                Row {
                    width: parent.width
                    Text {
                        text: "Molar Mass"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                        width: 80
                    }
                    Text {
                        text: (metadataCard.info && metadataCard.info.molecularWeight)
                              ? metadataCard.info.molecularWeight.toFixed(2) + " g/mol"
                              : "\u2014"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        font.weight: Font.DemiBold
                        color: Theme.textPrimary
                    }
                }

                Row {
                    width: parent.width
                    Text {
                        text: "Atoms"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                        width: 80
                    }
                    Text {
                        text: (metadataCard.info && metadataCard.info.atomCount !== undefined)
                              ? metadataCard.info.atomCount : "0"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        font.weight: Font.DemiBold
                        color: Theme.textPrimary
                    }
                }

                Row {
                    width: parent.width
                    Text {
                        text: "Valid"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        color: Theme.textSecondary
                        width: 80
                    }
                    Text {
                        text: (metadataCard.info && metadataCard.info.isValid !== undefined)
                              ? (metadataCard.info.isValid ? "Yes \u2713" : "No \u26A0")
                              : "\u2014"
                        font.family: Theme.fontFamily
                        font.pixelSize: Theme.fontSm
                        font.weight: Font.DemiBold
                        color: (metadataCard.info && metadataCard.info.isValid)
                               ? Theme.accentGreen : Theme.accentAmber
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
                    { icon: "\u270E", tool: "pen",     active: true  },
                    { icon: "\u25A1", tool: "select",  active: false },
                    { icon: "\u2B21", tool: "shape",   active: false },
                    { icon: "T",      tool: "text",    active: false },
                    { icon: "\u2316", tool: "measure", active: false }
                ]

                Rectangle {
                    property bool isActive: index === 0
                    width: 32; height: 32
                    radius: Theme.radiusSm
                    color: isActive ? Theme.accentBlue
                                    : (ftbMa.containsMouse ? Qt.rgba(1,1,1,0.08) : "transparent")
                    antialiasing: true
                    Behavior on color { ColorAnimation { duration: Theme.animFast } }

                    Text {
                        anchors.centerIn: parent
                        text: modelData.icon
                        font.pixelSize: 14
                        color: parent.isActive ? "#FFFFFF" : Theme.textSecondary
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
        anchors.bottomMargin: Theme.spacingLg + 80
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
                text: "ZOOM: " + (root.controller
                      ? Math.round(root.controller.zoomFactor * 100) + "%"
                      : "100%")
                font.family: Theme.fontFamily
                font.pixelSize: Theme.fontXs
                color: Theme.textSecondary
            }
        }
    }
}
