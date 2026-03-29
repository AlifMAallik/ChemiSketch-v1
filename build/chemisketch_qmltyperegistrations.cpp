/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#if __has_include(<Atom.h>)
#  include <Atom.h>
#endif
#if __has_include(<Bond.h>)
#  include <Bond.h>
#endif
#if __has_include(<CameraController.h>)
#  include <CameraController.h>
#endif
#if __has_include(<ChemController.h>)
#  include <ChemController.h>
#endif
#if __has_include(<ChemistryUtils.h>)
#  include <ChemistryUtils.h>
#endif
#if __has_include(<ElementData.h>)
#  include <ElementData.h>
#endif
#if __has_include(<FileUtils.h>)
#  include <FileUtils.h>
#endif
#if __has_include(<Molecule.h>)
#  include <Molecule.h>
#endif


#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif
Q_QMLTYPE_EXPORT void qml_register_types_ChemiSketch()
{
    QT_WARNING_PUSH QT_WARNING_DISABLE_DEPRECATED
    qmlRegisterTypesAndRevisions<Atom>("ChemiSketch", 1);
    qmlRegisterTypesAndRevisions<Bond>("ChemiSketch", 1);
    qmlRegisterEnum<Bond::BondType>("Bond::BondType");
    qmlRegisterTypesAndRevisions<CameraController>("ChemiSketch", 1);
    qmlRegisterTypesAndRevisions<ChemController>("ChemiSketch", 1);
    qmlRegisterTypesAndRevisions<ChemistryUtils>("ChemiSketch", 1);
    qmlRegisterTypesAndRevisions<ElementData>("ChemiSketch", 1);
    qmlRegisterTypesAndRevisions<FileUtils>("ChemiSketch", 1);
    qmlRegisterTypesAndRevisions<Molecule>("ChemiSketch", 1);
    QT_WARNING_POP
    qmlRegisterModule("ChemiSketch", 1, 0);
}

static const QQmlModuleRegistration chemiSketchRegistration("ChemiSketch", qml_register_types_ChemiSketch);
