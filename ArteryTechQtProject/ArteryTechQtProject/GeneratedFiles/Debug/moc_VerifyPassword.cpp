/****************************************************************************
** Meta object code from reading C++ file 'VerifyPassword.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VerifyPassword.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VerifyPassword.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VerifyPassword_t {
    QByteArrayData data[6];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VerifyPassword_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VerifyPassword_t qt_meta_stringdata_VerifyPassword = {
    {
QT_MOC_LITERAL(0, 0, 14), // "VerifyPassword"
QT_MOC_LITERAL(1, 15, 13), // "PasswordStatu"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "flag"
QT_MOC_LITERAL(4, 35, 21), // "ConfirmPushButtonSlot"
QT_MOC_LITERAL(5, 57, 20) // "CancelPushButtonSlot"

    },
    "VerifyPassword\0PasswordStatu\0\0flag\0"
    "ConfirmPushButtonSlot\0CancelPushButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VerifyPassword[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VerifyPassword::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VerifyPassword *_t = static_cast<VerifyPassword *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PasswordStatu((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->ConfirmPushButtonSlot(); break;
        case 2: _t->CancelPushButtonSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VerifyPassword::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VerifyPassword::PasswordStatu)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject VerifyPassword::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VerifyPassword.data,
      qt_meta_data_VerifyPassword,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VerifyPassword::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VerifyPassword::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VerifyPassword.stringdata0))
        return static_cast<void*>(const_cast< VerifyPassword*>(this));
    return QDialog::qt_metacast(_clname);
}

int VerifyPassword::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void VerifyPassword::PasswordStatu(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
