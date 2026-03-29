/****************************************************************************
** Meta object code from reading C++ file 'Molecule.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/models/Molecule.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Molecule.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8MoleculeE_t {};
} // unnamed namespace

template <> constexpr inline auto Molecule::qt_create_metaobjectdata<qt_meta_tag_ZN8MoleculeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Molecule",
        "QML.Element",
        "auto",
        "moleculeChanged",
        "",
        "atomAdded",
        "Atom*",
        "atom",
        "atomRemoved",
        "atomId",
        "bondAdded",
        "Bond*",
        "bond",
        "bondRemoved",
        "bondId",
        "atomAtPoint",
        "point",
        "radius",
        "bondBetween",
        "atom1Id",
        "atom2Id",
        "bondsForAtom",
        "QList<Bond*>",
        "usedValence",
        "clear",
        "atomCount",
        "bondCount",
        "atomList",
        "QVariantList",
        "bondList"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'moleculeChanged'
        QtMocHelpers::SignalData<void()>(3, 4, QMC::AccessPublic, QMetaType::Void),
        // Signal 'atomAdded'
        QtMocHelpers::SignalData<void(Atom *)>(5, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'atomRemoved'
        QtMocHelpers::SignalData<void(const QString &)>(8, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Signal 'bondAdded'
        QtMocHelpers::SignalData<void(Bond *)>(10, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Signal 'bondRemoved'
        QtMocHelpers::SignalData<void(const QString &)>(13, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Method 'atomAtPoint'
        QtMocHelpers::MethodData<Atom *(const QPointF &, double) const>(15, 4, QMC::AccessPublic, 0x80000000 | 6, {{
            { QMetaType::QPointF, 16 }, { QMetaType::Double, 17 },
        }}),
        // Method 'atomAtPoint'
        QtMocHelpers::MethodData<Atom *(const QPointF &) const>(15, 4, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 6, {{
            { QMetaType::QPointF, 16 },
        }}),
        // Method 'bondBetween'
        QtMocHelpers::MethodData<Bond *(const QString &, const QString &) const>(18, 4, QMC::AccessPublic, 0x80000000 | 11, {{
            { QMetaType::QString, 19 }, { QMetaType::QString, 20 },
        }}),
        // Method 'bondsForAtom'
        QtMocHelpers::MethodData<QList<Bond*>(const QString &) const>(21, 4, QMC::AccessPublic, 0x80000000 | 22, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'usedValence'
        QtMocHelpers::MethodData<double(const QString &) const>(23, 4, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'clear'
        QtMocHelpers::MethodData<void()>(24, 4, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'atomCount'
        QtMocHelpers::PropertyData<int>(25, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'bondCount'
        QtMocHelpers::PropertyData<int>(26, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'atomList'
        QtMocHelpers::PropertyData<QVariantList>(27, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'bondList'
        QtMocHelpers::PropertyData<QVariantList>(29, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<Molecule, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject Molecule::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8MoleculeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8MoleculeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8MoleculeE_t>.metaTypes,
    nullptr
} };

void Molecule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Molecule *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->moleculeChanged(); break;
        case 1: _t->atomAdded((*reinterpret_cast< std::add_pointer_t<Atom*>>(_a[1]))); break;
        case 2: _t->atomRemoved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->bondAdded((*reinterpret_cast< std::add_pointer_t<Bond*>>(_a[1]))); break;
        case 4: _t->bondRemoved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: { Atom* _r = _t->atomAtPoint((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< Atom**>(_a[0]) = std::move(_r); }  break;
        case 6: { Atom* _r = _t->atomAtPoint((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Atom**>(_a[0]) = std::move(_r); }  break;
        case 7: { Bond* _r = _t->bondBetween((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< Bond**>(_a[0]) = std::move(_r); }  break;
        case 8: { QList<Bond*> _r = _t->bondsForAtom((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<Bond*>*>(_a[0]) = std::move(_r); }  break;
        case 9: { double _r = _t->usedValence((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->clear(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Atom* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Bond* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Molecule::*)()>(_a, &Molecule::moleculeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Molecule::*)(Atom * )>(_a, &Molecule::atomAdded, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Molecule::*)(const QString & )>(_a, &Molecule::atomRemoved, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Molecule::*)(Bond * )>(_a, &Molecule::bondAdded, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Molecule::*)(const QString & )>(_a, &Molecule::bondRemoved, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->atomCount(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->bondCount(); break;
        case 2: *reinterpret_cast<QVariantList*>(_v) = _t->atomList(); break;
        case 3: *reinterpret_cast<QVariantList*>(_v) = _t->bondList(); break;
        default: break;
        }
    }
}

const QMetaObject *Molecule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Molecule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8MoleculeE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Molecule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Molecule::moleculeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Molecule::atomAdded(Atom * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Molecule::atomRemoved(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Molecule::bondAdded(Bond * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void Molecule::bondRemoved(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
