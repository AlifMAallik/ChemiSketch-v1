# ChemiSketch — Claude Code Guide

## Build

```bash
cd chemisketch
mkdir -p build && cd build
cmake ..
cmake --build .
./chemisketch-app
```

## Architecture Rules

- **No logic in QML.** All business logic lives in C++ controllers. QML is view-only.
- **Rendering** is done by `DrawScreen.qml` using a QML `Canvas` (JS 2D context). Bond/atom data is fetched from `ChemController` via `Q_INVOKABLE` methods (`getAtomRenderData()`, `getBondRenderData()`).
- **Model ownership:** `Molecule` owns all `Atom` and `Bond` objects via Qt parent-child. Never `delete` them manually — use `removeAtom()`/`removeBond()` which call `deleteLater()`.
- **Singletons:** `ElementData`, `ChemistryUtils`, and `FileUtils` are singletons created in `main.cpp` and registered with `qmlRegisterSingletonInstance`. Only one instance ever exists.

## Key Files

| File | Purpose |
|---|---|
| `src/main.cpp` | App entry point; creates singletons, loads QML via `loadFromModule("ChemiSketch", "Main")` |
| `src/controllers/ChemController.h/.cpp` | All canvas interaction, tool logic, zoom, file ops |
| `src/models/Molecule.h/.cpp` | Owns all atoms and bonds; emits `moleculeChanged` |
| `src/models/Atom.h/.cpp` | Position, element, charge, bond ID list |
| `src/models/Bond.h/.cpp` | Connects two atom IDs, bond type enum, valence |
| `src/models/ElementData.h/.cpp` | Singleton: valence, atomic weight, color per element |
| `src/models/BenzeneGenerator.h/.cpp` | Generates Kekule benzene `Molecule` |
| `src/utils/ChemistryUtils.h/.cpp` | Singleton: validates valence, molecular formula, weight |
| `src/utils/FileUtils.h/.cpp` | Singleton: JSON save/load, MOL import/export |
| `src/utils/GeometryUtils.h/.cpp` | Pure functions: polygon vertices, perpendicular offsets |
| `qml/Main.qml` | Root window; tab bar → DrawScreen / CameraScreen |
| `qml/screens/DrawScreen.qml` | Canvas + tool selector + info sidebar |
| `qml/screens/CameraScreen.qml` | Placeholder (Phase 3) |

## CMake Notes

- QML files are registered in `qt_add_qml_module` under URI `"ChemiSketch"`.
- QML files must start with **capital letters** (e.g. `Main.qml`, `DrawScreen.qml`) to be importable as types.
- C++ source files are listed under `SOURCES` in `qt_add_qml_module` so MOC runs once.
- Output binary is named `chemisketch-app` to avoid collision with the `ChemiSketch` build directory.
- `Qt6::Multimedia` is linked now; required for camera features in Phase 3.

## Tool Modes (`ChemController::activeTool`)

`single_bond`, `double_bond`, `triple_bond`, `benzene`, `wedge`, `hash`, `dashed`, `arrow`, `aromatic`, `eraser`

Clicking an existing bond between two atoms with a bond tool **upgrades** it (single → double → triple → single).

## Bond Types

| Enum | String | Valence |
|---|---|---|
| `Single` | `"single"` | 1.0 |
| `Double` | `"double"` | 2.0 |
| `Triple` | `"triple"` | 3.0 |
| `Aromatic` | `"aromatic"` | 1.5 |
| `Wedge` | `"wedge"` | 1.0 |
| `Hash` | `"hash"` | 1.0 |
| `Dashed` | `"dashed"` | 1.0 |
| `Arrow` | `"arrow"` | 0.0 |

## Phase Roadmap

- **Phase 1 (done):** C++ backend + minimal QML canvas. All chemistry logic ported.
- **Phase 2:** Redesign full QML UI (tool palette, info panel, IUPAC search, theming).
- **Phase 3:** Camera/3D viewer via `CameraController` and `CameraScreen.qml`.
