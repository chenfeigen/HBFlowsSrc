/****************************************************************************
** Meta object code from reading C++ file 'QtTcpClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtTcpClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtTcpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtTcpClient_t {
    QByteArrayData data[10];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtTcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtTcpClient_t qt_meta_stringdata_QtTcpClient = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QtTcpClient"
QT_MOC_LITERAL(1, 12, 4), // "send"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 13), // "startTransfer"
QT_MOC_LITERAL(4, 32, 20), // "updateClientProgress"
QT_MOC_LITERAL(5, 53, 12), // "displayError"
QT_MOC_LITERAL(6, 66, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(7, 95, 8), // "openFile"
QT_MOC_LITERAL(8, 104, 21), // "on_openButton_clicked"
QT_MOC_LITERAL(9, 126, 21) // "on_sendButton_clicked"

    },
    "QtTcpClient\0send\0\0startTransfer\0"
    "updateClientProgress\0displayError\0"
    "QAbstractSocket::SocketError\0openFile\0"
    "on_openButton_clicked\0on_sendButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtTcpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       5,    1,   54,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtTcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtTcpClient *_t = static_cast<QtTcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send(); break;
        case 1: _t->startTransfer(); break;
        case 2: _t->updateClientProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->openFile(); break;
        case 5: _t->on_openButton_clicked(); break;
        case 6: _t->on_sendButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject QtTcpClient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QtTcpClient.data,
      qt_meta_data_QtTcpClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtTcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtTcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtTcpClient.stringdata0))
        return static_cast<void*>(const_cast< QtTcpClient*>(this));
    return QWidget::qt_metacast(_clname);
}

int QtTcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
