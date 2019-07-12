/****************************************************************************
** Meta object code from reading C++ file 'VariableParametersDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VariableParametersDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VariableParametersDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VariableParametersDialog_t {
    QByteArrayData data[11];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VariableParametersDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VariableParametersDialog_t qt_meta_stringdata_VariableParametersDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "VariableParametersDialog"
QT_MOC_LITERAL(1, 25, 24), // "VariableParametersSignal"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 19), // "InputPushButtonSlot"
QT_MOC_LITERAL(4, 71, 17), // "SetPushButtonSlot"
QT_MOC_LITERAL(5, 89, 21), // "ConfirmPushButtonSlot"
QT_MOC_LITERAL(6, 111, 20), // "CancelPushButtonSlot"
QT_MOC_LITERAL(7, 132, 20), // "FileNameLineEditSlot"
QT_MOC_LITERAL(8, 153, 24), // "ExecMatlabPushButtonSlot"
QT_MOC_LITERAL(9, 178, 13), // "on_readoutput"
QT_MOC_LITERAL(10, 192, 12) // "on_readerror"

    },
    "VariableParametersDialog\0"
    "VariableParametersSignal\0\0InputPushButtonSlot\0"
    "SetPushButtonSlot\0ConfirmPushButtonSlot\0"
    "CancelPushButtonSlot\0FileNameLineEditSlot\0"
    "ExecMatlabPushButtonSlot\0on_readoutput\0"
    "on_readerror"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VariableParametersDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   62,    2, 0x08 /* Private */,
       4,    0,   63,    2, 0x08 /* Private */,
       5,    0,   64,    2, 0x08 /* Private */,
       6,    0,   65,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VariableParametersDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VariableParametersDialog *_t = static_cast<VariableParametersDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->VariableParametersSignal((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->InputPushButtonSlot(); break;
        case 2: _t->SetPushButtonSlot(); break;
        case 3: _t->ConfirmPushButtonSlot(); break;
        case 4: _t->CancelPushButtonSlot(); break;
        case 5: _t->FileNameLineEditSlot(); break;
        case 6: _t->ExecMatlabPushButtonSlot(); break;
        case 7: _t->on_readoutput(); break;
        case 8: _t->on_readerror(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VariableParametersDialog::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VariableParametersDialog::VariableParametersSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject VariableParametersDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VariableParametersDialog.data,
      qt_meta_data_VariableParametersDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VariableParametersDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VariableParametersDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VariableParametersDialog.stringdata0))
        return static_cast<void*>(const_cast< VariableParametersDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int VariableParametersDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void VariableParametersDialog::VariableParametersSignal(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
