/****************************************************************************
** Meta object code from reading C++ file 'userinterfaz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ragnarok/userinterfaz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinterfaz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserInterfaz_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserInterfaz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserInterfaz_t qt_meta_stringdata_UserInterfaz = {
    {
QT_MOC_LITERAL(0, 0, 12), // "UserInterfaz"
QT_MOC_LITERAL(1, 13, 3), // "fin"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 1), // "x"
QT_MOC_LITERAL(4, 20, 6), // "LoginS"
QT_MOC_LITERAL(5, 27, 9), // "RegisterS"
QT_MOC_LITERAL(6, 37, 18), // "CloseWindownOpenMe"
QT_MOC_LITERAL(7, 56, 7) // "closeMe"

    },
    "UserInterfaz\0fin\0\0x\0LoginS\0RegisterS\0"
    "CloseWindownOpenMe\0closeMe"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserInterfaz[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UserInterfaz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UserInterfaz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->LoginS(); break;
        case 2: _t->RegisterS(); break;
        case 3: _t->CloseWindownOpenMe(); break;
        case 4: _t->closeMe(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UserInterfaz::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UserInterfaz::fin)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UserInterfaz::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_UserInterfaz.data,
    qt_meta_data_UserInterfaz,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UserInterfaz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserInterfaz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserInterfaz.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UserInterfaz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void UserInterfaz::fin(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
