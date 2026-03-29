/****************************************************************************
** Meta object code from reading C++ file 'ElementData.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/models/ElementData.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ElementData.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11ElementDataE_t {};
} // unnamed namespace

template <> constexpr inline auto ElementData::qt_create_metaobjectdata<qt_meta_tag_ZN11ElementDataE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ElementData",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "maxValence",
        "",
        "symbol",
        "commonValences",
        "QList<int>",
        "elementName",
        "atomicNumber",
        "atomicWeight",
        "elementColor",
        "classify",
        "isValidElement",
        "allSymbols"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'maxValence'
        QtMocHelpers::MethodData<int(const QString &) const>(5, 6, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'commonValences'
        QtMocHelpers::MethodData<QVector<int>(const QString &) const>(8, 6, QMC::AccessPublic, 0x80000000 | 9, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'elementName'
        QtMocHelpers::MethodData<QString(const QString &) const>(10, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'atomicNumber'
        QtMocHelpers::MethodData<int(const QString &) const>(11, 6, QMC::AccessPublic, QMetaType::Int, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'atomicWeight'
        QtMocHelpers::MethodData<double(const QString &) const>(12, 6, QMC::AccessPublic, QMetaType::Double, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'elementColor'
        QtMocHelpers::MethodData<QColor(const QString &) const>(13, 6, QMC::AccessPublic, QMetaType::QColor, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'classify'
        QtMocHelpers::MethodData<QString(const QString &) const>(14, 6, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'isValidElement'
        QtMocHelpers::MethodData<bool(const QString &) const>(15, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 7 },
        }}),
        // Method 'allSymbols'
        QtMocHelpers::MethodData<QStringList() const>(16, 6, QMC::AccessPublic, QMetaType::QStringList),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<ElementData, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject ElementData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ElementDataE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ElementDataE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11ElementDataE_t>.metaTypes,
    nullptr
} };

void ElementData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ElementData *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = _t->maxValence((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { QList<int> _r = _t->commonValences((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->elementName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->atomicNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { double _r = _t->atomicWeight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 5: { QColor _r = _t->elementColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->classify((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->isValidElement((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { QStringList _r = _t->allSymbols();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *ElementData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ElementData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11ElementDataE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ElementData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
