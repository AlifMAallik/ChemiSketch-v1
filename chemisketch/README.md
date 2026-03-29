# ChemiSketch (C++ / QML)

A molecular sketcher and visualizer built with Qt 6, C++17, and QML.

## Build Requirements

- CMake 3.16+
- Qt 6.5+ (Core, Gui, Quick, QuickControls2, Multimedia)
- C++17 compiler

## Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## Run

```bash
./ChemiSketch
```

## Project Structure

```
chemisketch/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── models/          # Data/domain classes
│   │   ├── Atom.h/.cpp
│   │   ├── Bond.h/.cpp
│   │   ├── Molecule.h/.cpp
│   │   ├── ElementData.h/.cpp
│   │   └── BenzeneGenerator.h/.cpp
│   ├── controllers/     # Business logic
│   │   ├── ChemController.h/.cpp
│   │   └── CameraController.h
│   └── utils/           # Helpers
│       ├── GeometryUtils.h/.cpp
│       ├── ChemistryUtils.h/.cpp
│       └── FileUtils.h/.cpp
├── qml/
│   ├── main.qml
│   ├── screens/
│   │   ├── DrawScreen.qml
│   │   └── CameraScreen.qml
│   └── components/
│       └── Placeholder.qml
├── resources/
│   ├── assets.qrc
│   ├── icons/
│   └── fonts/
└── tests/
```

## Architecture

- **QML** is view-only — no business logic
- **C++ controllers** handle all interactions via Q_INVOKABLE methods
- **Models** are exposed to QML via Q_PROPERTY and QML_ELEMENT
- All chemical logic (valence validation, formula calculation) is in C++ backend
