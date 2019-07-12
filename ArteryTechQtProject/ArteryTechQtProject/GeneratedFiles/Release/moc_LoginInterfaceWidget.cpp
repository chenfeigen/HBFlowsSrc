/****************************************************************************
** Meta object code from reading C++ file 'LoginInterfaceWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LoginInterfaceWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoginInterfaceWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginInterfaceWidget_t {
    QByteArrayData data[7];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginInterfaceWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginInterfaceWidget_t qt_meta_stringdata_LoginInterfaceWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "LoginInterfaceWidget"
QT_MOC_LITERAL(1, 21, 30), // "RetrievePasswordPushButtonSlot"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 22), // "RegisterPushButtonSlot"
QT_MOC_LITERAL(4, 76, 19), // "LoginPushButtonSlot"
QT_MOC_LITERAL(5, 96, 28), // "getInstallationAlignmentSlot"
QT_MOC_LITERAL(6, 125, 12) // "serialNumber"

    },
    "LoginInterfaceWidget\0"
    "RetrievePasswordPushButtonSlot\0\0"
    "RegisterPushButtonSlot\0LoginPushButtonSlot\0"
    "getInstallationAlignmentSlot\0serialNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginInterfaceWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void LoginInterfaceWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginInterfaceWidget *_t = static_cast<LoginInterfaceWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->RetrievePasswordPushButtonSlot(); break;
        case 1: _t->RegisterPushButtonSlot(); break;
        case 2: _t->LoginPushButtonSlot(); break;
        case 3: _t->getInstallationAlignmentSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject LoginInterfaceWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoginInterfaceWidget.data,
      qt_meta_data_LoginInterfaceWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LoginInterfaceWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginInterfaceWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LoginInterfaceWidget.stringdata0))
        return static_cast<void*>(const_cast< LoginInterfaceWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoginInterfaceWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
