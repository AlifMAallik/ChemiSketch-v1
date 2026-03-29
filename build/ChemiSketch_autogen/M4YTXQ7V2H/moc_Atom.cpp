/****************************************************************************
** Meta object code from reading C++ file 'Atom.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/models/Atom.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Atom.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN4AtomE_t {};
} // unnamed namespace

template <> constexpr inline auto Atom::qt_create_metaobjectdata<qt_meta_tag_ZN4AtomE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Atom",
        "QML.Element",
        "auto",
        "elementSymbolChanged",
        "",
        "positionChanged",
        "chargeChanged",
        "highlightedChanged",
        "isotopeChanged",
        "containsPoint",
        "point",
        "radius",
        "bondCount",
        "elementSymbol",
        "position",
        "charge",
        "atomId",
        "highlighted",
        "isotope"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'elementSymbolChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'positionChanged'
        QtMocHelpers::SignalData<void()>(5, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'chargeChanged'
        QtMocHelpers::SignalData<void()>(6, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'highlightedChanged'
        QtMocHelpers::SignalData<void()>(7, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isotopeChanged'
        QtMocHelpers::SignalData<void()>(8, 4, QMC::AccessPublic, QMetaType::Void),
        // Method 'containsPoint'
        QtMocHelpers::MethodData<bool(const QPointF &, double) const>(9, 4, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QPointF, 10 }, { QMetaType::Double, 11 },
        }}),
        // Method 'containsPoint'
        QtMocHelpers::MethodData<bool(const QPointF &) const>(9, 4, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::QPointF, 10 },
        }}),
        // Method 'bondCount'
        QtMocHelpers::MethodData<int() const>(12, 4, QMC::AccessPublic, QMetaType::Int),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'elementSymbol'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'position'
        QtMocHelpers::PropertyData<QPointF>(14, QMetaType::QPointF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'charge'
        QtMocHelpers::PropertyData<int>(15, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'atomId'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'highlighted'
        QtMocHelpers::PropertyData<bool>(17, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'isotope'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<Atom, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Atom::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4AtomE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4AtomE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN4AtomE_t>.metaTypes,
    nullptr
} };

void Atom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Atom *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->elementSymbolChanged(); break;
        case 1: _t->positionChanged(); break;
        case 2: _t->chargeChanged(); break;
        case 3: _t->highlightedChanged(); break;
        case 4: _t->isotopeChanged(); break;
        case 5: { bool _r = _t->containsPoint((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->containsPoint((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->bondCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Atom::*)()>(_a, &Atom::elementSymbolChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Atom::*)()>(_a, &Atom::positionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Atom::*)()>(_a, &Atom::chargeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Atom::*)()>(_a, &Atom::highlightedChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Atom::*)()>(_a, &Atom::isotopeChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->elementSymbol(); break;
        case 1: *reinterpret_cast<QPointF*>(_v) = _t->position(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->charge(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->atomId(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isHighlighted(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->isotope(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setElementSymbol(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setPosition(*reinterpret_cast<QPointF*>(_v)); break;
        case 2: _t->setCharge(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setHighlighted(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setIsotope(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Atom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Atom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN4AtomE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Atom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
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
void Atom::elementSymbolChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Atom::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Atom::chargeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Atom::highlightedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Atom::isotopeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
