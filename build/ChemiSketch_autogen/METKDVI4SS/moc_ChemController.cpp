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
        "activeElementChanged",
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
        "setActiveElement",
        "element",
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
        "addCyclohexaneAt",
        "addCyclopentaneAt",
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
        "activeElement",
        "isDarkTheme",
        "moleculeInfo",
        "zoomFactor"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activeToolChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'activeElementChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isDarkThemeChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'moleculeInfoChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'zoomFactorChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canvasNeedsRepaint'
        QtMocHelpers::SignalData<void()>(9, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'moleculeValidated'
        QtMocHelpers::SignalData<void(bool)>(10, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Signal 'bondRejected'
        QtMocHelpers::SignalData<void(const QString &, double, double)>(12, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 }, { QMetaType::Double, 14 }, { QMetaType::Double, 15 },
        }}),
        // Method 'setActiveElement'
        QtMocHelpers::MethodData<void(const QString &)>(16, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 17 },
        }}),
        // Method 'canvasPressed'
        QtMocHelpers::MethodData<void(const QPointF &)>(18, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 19 },
        }}),
        // Method 'canvasDragged'
        QtMocHelpers::MethodData<void(const QPointF &)>(20, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 19 },
        }}),
        // Method 'canvasReleased'
        QtMocHelpers::MethodData<void(const QPointF &)>(21, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 19 },
        }}),
        // Method 'canAtomAcceptBond'
        QtMocHelpers::MethodData<bool(const QString &, double) const>(22, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 13 }, { QMetaType::Double, 23 },
        }}),
        // Method 'remainingValence'
        QtMocHelpers::MethodData<double(const QString &) const>(24, 4, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::QString, 13 },
        }}),
        // Method 'addBenzeneAt'
        QtMocHelpers::MethodData<void(const QPointF &, double)>(25, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 26 }, { QMetaType::Double, 27 },
        }}),
        // Method 'addBenzeneAt'
        QtMocHelpers::MethodData<void(const QPointF &)>(25, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QPointF, 26 },
        }}),
        // Method 'addCyclohexaneAt'
        QtMocHelpers::MethodData<void(const QPointF &, double)>(28, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 26 }, { QMetaType::Double, 27 },
        }}),
        // Method 'addCyclohexaneAt'
        QtMocHelpers::MethodData<void(const QPointF &)>(28, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QPointF, 26 },
        }}),
        // Method 'addCyclopentaneAt'
        QtMocHelpers::MethodData<void(const QPointF &, double)>(29, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 26 }, { QMetaType::Double, 27 },
        }}),
        // Method 'addCyclopentaneAt'
        QtMocHelpers::MethodData<void(const QPointF &)>(29, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QPointF, 26 },
        }}),
        // Method 'changeAtomElement'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(30, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 }, { QMetaType::QString, 31 },
        }}),
        // Method 'clearCanvas'
        QtMocHelpers::MethodData<void()>(32, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'saveToFile'
        QtMocHelpers::MethodData<bool(const QString &) const>(33, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 34 },
        }}),
        // Method 'loadFromFile'
        QtMocHelpers::MethodData<bool(const QString &)>(35, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 34 },
        }}),
        // Method 'exportMol'
        QtMocHelpers::MethodData<bool(const QString &) const>(36, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 34 },
        }}),
        // Method 'importMol'
        QtMocHelpers::MethodData<bool(const QString &)>(37, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 34 },
        }}),
        // Method 'zoomIn'
        QtMocHelpers::MethodData<void()>(38, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'zoomOut'
        QtMocHelpers::MethodData<void()>(39, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'resetZoom'
        QtMocHelpers::MethodData<void()>(40, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'getAtomRenderData'
        QtMocHelpers::MethodData<QVariantList() const>(41, 4, QMC::AccessPublic, 0x80000000 | 42),
        // Method 'getBondRenderData'
        QtMocHelpers::MethodData<QVariantList() const>(43, 4, QMC::AccessPublic, 0x80000000 | 42),
        // Method 'getTempLine'
        QtMocHelpers::MethodData<QVariantMap() const>(44, 4, QMC::AccessPublic, 0x80000000 | 45),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'molecule'
        QtMocHelpers::PropertyData<Molecule*>(46, 0x80000000 | 47, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'activeTool'
        QtMocHelpers::PropertyData<QString>(48, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'activeElement'
        QtMocHelpers::PropertyData<QString>(49, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'isDarkTheme'
        QtMocHelpers::PropertyData<bool>(50, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'moleculeInfo'
        QtMocHelpers::PropertyData<QVariantMap>(51, 0x80000000 | 45, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 3),
        // property 'zoomFactor'
        QtMocHelpers::PropertyData<double>(52, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
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
        case 1: _t->activeElementChanged(); break;
        case 2: _t->isDarkThemeChanged(); break;
        case 3: _t->moleculeInfoChanged(); break;
        case 4: _t->zoomFactorChanged(); break;
        case 5: _t->canvasNeedsRepaint(); break;
        case 6: _t->moleculeValidated((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->bondRejected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3]))); break;
        case 8: _t->setActiveElement((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->canvasPressed((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 10: _t->canvasDragged((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 11: _t->canvasReleased((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 12: { bool _r = _t->canAtomAcceptBond((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { double _r = _t->remainingValence((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->addBenzeneAt((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 15: _t->addBenzeneAt((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 16: _t->addCyclohexaneAt((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 17: _t->addCyclohexaneAt((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 18: _t->addCyclopentaneAt((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 19: _t->addCyclopentaneAt((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 20: _t->changeAtomElement((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 21: _t->clearCanvas(); break;
        case 22: { bool _r = _t->saveToFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->loadFromFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->exportMol((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->importMol((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->zoomIn(); break;
        case 27: _t->zoomOut(); break;
        case 28: _t->resetZoom(); break;
        case 29: { QVariantList _r = _t->getAtomRenderData();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 30: { QVariantList _r = _t->getBondRenderData();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        case 31: { QVariantMap _r = _t->getTempLine();
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::activeToolChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::activeElementChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::isDarkThemeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::moleculeInfoChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::zoomFactorChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)()>(_a, &ChemController::canvasNeedsRepaint, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)(bool )>(_a, &ChemController::moleculeValidated, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (ChemController::*)(const QString & , double , double )>(_a, &ChemController::bondRejected, 7))
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
        case 2: *reinterpret_cast<QString*>(_v) = _t->activeElement(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isDarkTheme(); break;
        case 4: *reinterpret_cast<QVariantMap*>(_v) = _t->moleculeInfo(); break;
        case 5: *reinterpret_cast<double*>(_v) = _t->zoomFactor(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setActiveTool(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setActiveElement(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setIsDarkTheme(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setZoomFactor(*reinterpret_cast<double*>(_v)); break;
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
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 32;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ChemController::activeToolChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ChemController::activeElementChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ChemController::isDarkThemeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ChemController::moleculeInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ChemController::zoomFactorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ChemController::canvasNeedsRepaint()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ChemController::moleculeValidated(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void ChemController::bondRejected(const QString & _t1, double _t2, double _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
