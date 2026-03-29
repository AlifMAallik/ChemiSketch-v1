pragma Singleton
import QtQuick

QtObject {
    // Active tab index: 0=Sketch, 1=3DView, 2=Analyze, 3=Properties, 4=Export
    property int activeTab: 0

    // Active tool in sidebar
    property string activeTool: "single_bond"

    // Active element for atom placement
    property string activeElement: "C"

    // Active nav in left sidebar (0=Sketch, 1=3D View, 2=Search)
    property int activeNav: 0

    // Whether a paint operation is in progress (guards against mid-paint mutations)
    property bool isPainting: false

    // Safe setter that prevents changes during paint
    function setActiveTab(index) {
        if (isPainting) return
        activeTab = index
    }

    function setActiveTool(tool) {
        if (isPainting) return
        activeTool = tool
    }

    function setActiveElement(element) {
        activeElement = element
    }

    function setActiveNav(index) {
        activeNav = index
    }
}
