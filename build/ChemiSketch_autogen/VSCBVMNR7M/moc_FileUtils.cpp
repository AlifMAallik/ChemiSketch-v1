/****************************************************************************
** Meta object code from reading C++ file 'FileUtils.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/utils/FileUtils.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FileUtils.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9FileUtilsE_t {};
} // unnamed namespace

template <> constexpr inline auto FileUtils::qt_create_metaobjectdata<qt_meta_tag_ZN9FileUtilsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "FileUtils",
        "QML.Element",
        "auto",
        "QML.Singleton",
        "true",
        "saveToJson",
        "",
        "Molecule*",
        "molecule",
        "filePath",
        "loadFromJson",
        "parent",
        "exportToMol",
        "importFromMol",
        "center"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'saveToJson'
        QtMocHelpers::MethodData<bool(Molecule *, const QString &) const>(5, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 7, 8 }, { QMetaType::QString, 9 },
        }}),
        // Method 'loadFromJson'
        QtMocHelpers::MethodData<Molecule *(const QString &, QObject *) const>(10, 6, QMC::AccessPublic, 0x80000000 | 7, {{
            { QMetaType::QString, 9 }, { QMetaType::QObjectStar, 11 },
        }}),
        // Method 'loadFromJson'
        QtMocHelpers::MethodData<Molecule *(const QString &) const>(10, 6, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 7, {{
            { QMetaType::QString, 9 },
        }}),
        // Method 'exportToMol'
        QtMocHelpers::MethodData<bool(Molecule *, const QString &) const>(12, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 7, 8 }, { QMetaType::QString, 9 },
        }}),
        // Method 'importFromMol'
        QtMocHelpers::MethodData<Molecule *(const QString &, const QPointF &, QObject *) const>(13, 6, QMC::AccessPublic, 0x80000000 | 7, {{
            { QMetaType::QString, 9 }, { QMetaType::QPointF, 14 }, { QMetaType::QObjectStar, 11 },
        }}),
        // Method 'importFromMol'
        QtMocHelpers::MethodData<Molecule *(const QString &, const QPointF &) const>(13, 6, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 7, {{
            { QMetaType::QString, 9 }, { QMetaType::QPointF, 14 },
        }}),
        // Method 'importFromMol'
        QtMocHelpers::MethodData<Molecule *(const QString &) const>(13, 6, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 7, {{
            { QMetaType::QString, 9 },
        }}),
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
    return QtMocHelpers::metaObjectData<FileUtils, void>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject FileUtils::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9FileUtilsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9FileUtilsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9FileUtilsE_t>.metaTypes,
    nullptr
} };

void FileUtils::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FileUtils *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = _t->saveToJson((*reinterpret_cast< std::add_pointer_t<Molecule*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { Molecule* _r = _t->loadFromJson((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< Molecule**>(_a[0]) = std::move(_r); }  break;
        case 2: { Molecule* _r = _t->loadFromJson((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Molecule**>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->exportToMol((*reinterpret_cast< std::add_pointer_t<Molecule*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { Molecule* _r = _t->importFromMol((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[3])));
            if (_a[0]) *reinterpret_cast< Molecule**>(_a[0]) = std::move(_r); }  break;
        case 5: { Molecule* _r = _t->importFromMol((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2])));
            if (_a[0]) *reinterpret_cast< Molecule**>(_a[0]) = std::move(_r); }  break;
        case 6: { Molecule* _r = _t->importFromMol((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Molecule**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Molecule* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Molecule* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *FileUtils::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileUtils::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9FileUtilsE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileUtils::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
