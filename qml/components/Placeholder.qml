import QtQuick
import QtQuick.Controls

// Reusable placeholder component for features not yet implemented.
Item {
    id: placeholder

    property string message: "Coming soon"

    Label {
        anchors.centerIn: parent
        text: placeholder.message
        font.pixelSize: 16
        color: "#999999"
    }
}
