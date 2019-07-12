/****************************************************************************
** Meta object code from reading C++ file 'ComputingMultipleBP.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ComputingMultipleBP.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ComputingMultipleBP.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ComputingMultipleBP_t {
    QByteArrayData data[10];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComputingMultipleBP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComputingMultipleBP_t qt_meta_stringdata_ComputingMultipleBP = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ComputingMultipleBP"
QT_MOC_LITERAL(1, 20, 25), // "ComputingMultipleBPSignal"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 10), // "uiDateList"
QT_MOC_LITERAL(4, 58, 14), // "PushButtonSlot"
QT_MOC_LITERAL(5, 73, 16), // "PushButton_2Slot"
QT_MOC_LITERAL(6, 90, 26), // "GetCreateOPTFileSignalSlot"
QT_MOC_LITERAL(7, 117, 12), // "createStatus"
QT_MOC_LITERAL(8, 130, 13), // "on_readoutput"
QT_MOC_LITERAL(9, 144, 12) // "on_readerror"

    },
    "ComputingMultipleBP\0ComputingMultipleBPSignal\0"
    "\0uiDateList\0PushButtonSlot\0PushButton_2Slot\0"
    "GetCreateOPTFileSignalSlot\0createStatus\0"
    "on_readoutput\0on_readerror"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComputingMultipleBP[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ComputingMultipleBP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ComputingMultipleBP *_t = static_cast<ComputingMultipleBP *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ComputingMultipleBPSignal((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->PushButtonSlot(); break;
        case 2: _t->PushButton_2Slot(); break;
        case 3: _t->GetCreateOPTFileSignalSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_readoutput(); break;
        case 5: _t->on_readerror(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ComputingMultipleBP::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComputingMultipleBP::ComputingMultipleBPSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ComputingMultipleBP::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ComputingMultipleBP.data,
      qt_meta_data_ComputingMultipleBP,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ComputingMultipleBP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComputingMultipleBP::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ComputingMultipleBP.stringdata0))
        return static_cast<void*>(const_cast< ComputingMultipleBP*>(this));
    return QDialog::qt_metacast(_clname);
}

int ComputingMultipleBP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ComputingMultipleBP::ComputingMultipleBPSignal(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
