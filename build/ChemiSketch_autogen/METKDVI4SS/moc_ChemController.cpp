/****************************************************************************
** Meta object code from reading C++ file 'ChemController.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/controllers/ChemController.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChemController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14ChemControllerE_t {};
} // unnamed namespace

template <> constexpr inline auto ChemController::qt_create_metaobjectdata<qt_meta_tag_ZN14ChemControllerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ChemController",
        "QML.Element",
        "auto",
        "activeToolChanged",
        "",
        "isDarkThemeChanged",
        "moleculeInfoChanged",
        "zoomFactorChanged",
        "canvasNeedsRepaint",
        "moleculeValidated",
        "isValid",
        "bondRejected",
        "atomId",
        "x",
        "y",
        "canvasPressed",
        "pos",
        "canvasDragged",
        "canvasReleased",
        "canAtomAcceptBond",
        "bondValence",
        "remainingValence",
        "addBenzeneAt",
        "center",
        "radius",
        "changeAtomElement",
        "newElement",
        "clearCanvas",
        "saveToFile",
        "filePath",
        "loadFromFile",
        "exportMol",
        "importMol",
        "zoomIn",
        "zoomOut",
        "resetZoom",
        "getAtomRenderData",
        "QVariantList",
        "getBondRenderData",
        "getTempLine",
        "QVariantMap",
        "molecule",
        "Molecule*",
        "activeTool",
        "isDarkTheme",
        "moleculeInfo",
        "zoomFactor"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activeToolChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isDarkThemeChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'moleculeInfoChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'zoomFactorChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canvasNeedsRepaint'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'moleculeValidated'
        QtMocHelpers::SignalData<void(bool)>(9, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 10 },
        }}),
        // Signal 'bondRejected'
        QtMocHelpers::SignalData<void(const QString &, double, double)>(11, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 12 }, { QMetaType::Double, 13 }, { QMetaType::Double, 14 },
        }}),
        // Method 'canvasPressed'
        QtMocHelpers::MethodData<void(const QPointF &)>(15, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 16 },
        }}),
        // Method 'canvasDragged'
        QtMocHelpers::MethodData<void(const QPointF &)>(17, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 16 },
        }}),
        // Method 'canvasReleased'
        QtMocHelpers::MethodData<void(const QPointF &)>(18, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 16 },
        }}),
        // Method 'canAtomAcceptBond'
        QtMocHelpers::MethodData<bool(const QString &, double) const>(19, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 12 }, { QMetaType::Double, 20 },
        }}),
        // Method 'remainingValence'
        QtMocHelpers::MethodData<double(const QString &) const>(21, 4, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::QString, 12 },
        }}),
        // Method 'addBenzeneAt'
        QtMocHelpers::MethodData<void(const QPointF &, double)>(22, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 23 }, { QMetaType::Double, 24 },
        }}),
        // Method 'addBenzeneAt'
        QtMocHelpers::MethodData<void(const QPointF &)>(22, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QPointF, 23 },
        }}),
        // Method 'changeAtomElement'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(25, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 12 }, { QMetaType::QString, 26 },
        }}),
        // Method 'clearCanvas'
        QtMocHelpers::MethodData<void()>(27, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'saveToFile'
        QtMocHelpers::MethodData<bool(const QString &) const>(28, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 29 },
        }}),
        // Method 'loadFromFile'
        QtMocHelpers::MethodData<bool(const QString &)>(30, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 29 },
        }}),
        // Method 'exportMol'
        QtMocHelpers::MethodData<bool(const QString &) const>(31, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 29 },
        }}),
        // Method 'importMol'
        QtMocHelpers::MethodData<bool(const QString &)>(32, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 29 },
        }}),
        // Method 'zoomIn'
        QtMocHelpers::MethodData<void()>(33, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'zoomOut'
        QtMocHelpers::MethodData<void()>(34, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'resetZoom'
        QtMocHelpers::MethodData<void()>(35, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'getAtomRenderData'
        QtMocHelpers::MethodData<QVariantList() const>(36, 4, QMC::AccessPublic, 0x80000000 | 37),
        // Method 'getBondRenderData'
        QtMocHelpers::MethodData<QVariantList() const>(38, 4, QMC::AccessPublic, 0x80000000 | 37),
        // Method 'getTempLine'
        QtMocHelpers::MethodData<QVariantMap() const>(39, 4, QMC::AccessPublic, 0x80000000 | 40),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'molecule'
        QtMocHelpers::PropertyData<Molecule*>(41, 0x80000000 | 42, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'activeTool'
        QtMocHelpers::PropertyData<QString>(43, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'isDarkTheme'
        QtMocHelpers::PropertyData<bool>(44, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'moleculeInfo'
        QtMocHelpers::PropertyData<QVariantMap>(45, 0x80000000 | 40, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 2),
        // property 'zoomFactor'
        QtMocHelpers::PropertyData<double>(46, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<ChemController, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ChemController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ChemControllerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ChemControllerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14ChemControllerE_t>.metaTypes,
    nullptr
} };

void ChemController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ChemController *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activeToolChanged(); break;
        case 1: _t->isDarkThemeChanged(); break;
        case 2: _t->moleculeInfoChanged(); break;
        case 3: _t->zoomFactorChanged(); break;
        case 4: _t->canvasNeedsRepaint(); break;
        case 5: _t->moleculeValidated((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->bondRejected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 7: _t->canvasPressed((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 8: _t->canvasDragged((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 9: _t->canvasReleased((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 10: { bool _r = _t->canAtomAcceptBond((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { double _r = _t->remainingValence((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->addBenzeneAt((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 13: _t->addBenzeneAt((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 14: _t->changeAtomElement((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->clearCanvas(); break;
        case 16: { bool _r = _t->saveToFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->loadFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->exportMol((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->importMol((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->zoomIn(); break;
        case 21: _t->zoomOut(); break;
        case 22: _t->resetZoom(); break;
        case 23: { QVariantList _r = _t->getAtomRenderData();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 24: { QVariantList _r = _t->getBondRenderData();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 25: { QVariantMap _r = _t->getTempLine();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::activeToolChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::isDarkThemeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::moleculeInfoChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::zoomFactorChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::canvasNeedsRepaint, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)(bool )>(_a, &ChemController::moleculeValidated, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)(const QString & , double , double )>(_a, &ChemController::bondRejected, 6))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Molecule* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Molecule**>(_v) = _t->molecule(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->activeTool(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isDarkTheme(); break;
        case 3: *reinterpret_cast<QVariantMap*>(_v) = _t->moleculeInfo(); break;
        case 4: *reinterpret_cast<double*>(_v) = _t->zoomFactor(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setActiveTool(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setIsDarkTheme(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setZoomFactor(*reinterpret_cast<double*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *ChemController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChemController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14ChemControllerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChemController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ChemController::activeToolChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ChemController::isDarkThemeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ChemController::moleculeInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ChemController::zoomFactorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ChemController::canvasNeedsRepaint()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ChemController::moleculeValidated(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void ChemController::bondRejected(const QString & _t1, double _t2, double _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
