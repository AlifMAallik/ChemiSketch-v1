#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "models/Atom.h"
#include "models/Bond.h"
#include "models/Molecule.h"
#include "models/ElementData.h"
#include "models/BenzeneGenerator.h"
#include "controllers/ChemController.h"
#include "controllers/CameraController.h"
#include "utils/ChemistryUtils.h"
#include "utils/FileUtils.h"
#include "utils/GeometryUtils.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("ChemiSketch");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("ChemiSketch");

    QQuickStyle::setStyle("Basic");

    QQmlApplicationEngine engine;

    // All C++ types use QML_ELEMENT / QML_SINGLETON and are auto-registered
    // via qt_add_qml_module SOURCES — no manual registration needed.

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    // Qt 6.5+: load the root QML file directly from the registered module
    engine.loadFromModule("ChemiSketch", "Main");

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
