pragma Singleton
import QtQuick

QtObject {
    // Background colors
    readonly property color bgBase: "#0D1117"
    readonly property color bgSurface: "#161B22"
    readonly property color bgCard: "#1C2128"
    readonly property color bgCanvas: "#0D0F14"

    // Accent colors
    readonly property color accentBlue: "#4F9EFF"
    readonly property color accentAmber: "#D29922"
    readonly property color accentPurple: "#A371F7"
    readonly property color accentGreen: "#3FB950"
    readonly property color accentRed: "#F85149"

    // Text colors
    readonly property color textPrimary: "#E6EDF3"
    readonly property color textSecondary: "#8B949E"
    readonly property color textMuted: "#484F58"

    // Border
    readonly property color border: "#30363D"

    // Radii
    readonly property int radiusSm: 6
    readonly property int radiusMd: 10
    readonly property int radiusLg: 16
    readonly property int radiusPill: 999

    // Spacing
    readonly property int spacingXs: 4
    readonly property int spacingSm: 8
    readonly property int spacingMd: 12
    readonly property int spacingLg: 16
    readonly property int spacingXl: 24

    // Font sizes
    readonly property int fontXs: 10
    readonly property int fontSm: 11
    readonly property int fontMd: 13
    readonly property int fontLg: 16
    readonly property int fontXl: 18
    readonly property int fontXxl: 24
    readonly property int fontHero: 28

    // Font family
    readonly property string fontFamily: Qt.platform.os === "osx" ? ".AppleSystemUIFont" : "Inter"

    // Animation durations
    readonly property int animFast: 150
    readonly property int animNormal: 200
    readonly property int animSlow: 300
}
