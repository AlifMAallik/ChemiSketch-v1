cmake_minimum_required(VERSION 3.16)
project(ChemiSketch VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS
    Core
    Gui
    Quick
    QuickControls2
    Multimedia
)

qt_standard_project_setup(REQUIRES 6.5)

set(MODEL_SOURCES
    src/models/Atom.h
    src/models/Atom.cpp
    src/models/Bond.h
    src/models/Bond.cpp
    src/models/Molecule.h
    src/models/Molecule.cpp
    src/models/ElementData.h
    src/models/ElementData.cpp
    src/models/BenzeneGenerator.h
    src/models/BenzeneGenerator.cpp
)

set(CONTROLLER_SOURCES
    src/controllers/ChemController.h
    src/controllers/ChemController.cpp
    src/controllers/CameraController.h
)

set(UTIL_SOURCES
    src/utils/GeometryUtils.h
    src/utils/GeometryUtils.cpp
    src/utils/ChemistryUtils.h
    src/utils/ChemistryUtils.cpp
    src/utils/FileUtils.h
    src/utils/FileUtils.cpp
)

qt_add_executable(ChemiSketch
    src/main.cpp
    ${MODEL_SOURCES}
    ${CONTROLLER_SOURCES}
    ${UTIL_SOURCES}
)

set_target_properties(ChemiSketch PROPERTIES
    OUTPUT_NAME "chemisketch-app"
)

set_source_files_properties(qml/Theme.qml PROPERTIES
    QT_QML_SINGLETON_TYPE TRUE
)
set_source_files_properties(qml/AppState.qml PROPERTIES
    QT_QML_SINGLETON_TYPE TRUE
)

qt_add_qml_module(ChemiSketch
    URI ChemiSketch
    VERSION 1.0
    SOURCES
        ${MODEL_SOURCES}
        ${CONTROLLER_SOURCES}
        ${UTIL_SOURCES}
    QML_FILES
        qml/Main.qml
        qml/Theme.qml
        qml/TopMenuBar.qml
        qml/LeftSidebar.qml
        qml/BottomTabBar.qml
        qml/RightPanel.qml
        qml/CollapsibleSection.qml
        qml/AppState.qml
        qml/BondValidator.qml
        qml/SketchView.qml
        qml/PropertiesView.qml
        qml/screens/DrawScreen.qml
        qml/screens/CameraScreen.qml
        qml/components/Placeholder.qml
    RESOURCES
        resources/assets.qrc
)

target_include_directories(ChemiSketch PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controllers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
)

target_link_libraries(ChemiSketch PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Multimedia
)

install(TARGETS ChemiSketch
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
