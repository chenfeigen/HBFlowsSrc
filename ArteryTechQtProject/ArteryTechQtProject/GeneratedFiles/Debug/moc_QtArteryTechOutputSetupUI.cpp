/****************************************************************************
** Meta object code from reading C++ file 'QtArteryTechOutputSetupUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtArteryTechOutputSetupUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtArteryTechOutputSetupUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtArteryTechOutputSetupUI_t {
    QByteArrayData data[10];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtArteryTechOutputSetupUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtArteryTechOutputSetupUI_t qt_meta_stringdata_QtArteryTechOutputSetupUI = {
    {
QT_MOC_LITERAL(0, 0, 25), // "QtArteryTechOutputSetupUI"
QT_MOC_LITERAL(1, 26, 34), // "NumberOfStepsForOutputLineEdi..."
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 33), // "TimeIntervalForOutputLineEdit..."
QT_MOC_LITERAL(4, 96, 17), // "OkPushButtonSlots"
QT_MOC_LITERAL(5, 114, 21), // "CancelPushButtonSlots"
QT_MOC_LITERAL(6, 136, 26), // "GetVerifyPasswordStatuSlot"
QT_MOC_LITERAL(7, 163, 4), // "flag"
QT_MOC_LITERAL(8, 168, 31), // "GetVariableParametersSignalSlot"
QT_MOC_LITERAL(9, 200, 22) // "VariableParametersList"

    },
    "QtArteryTechOutputSetupUI\0"
    "NumberOfStepsForOutputLineEditSlot\0\0"
    "TimeIntervalForOutputLineEditSlot\0"
    "OkPushButtonSlots\0CancelPushButtonSlots\0"
    "GetVerifyPasswordStatuSlot\0flag\0"
    "GetVariableParametersSignalSlot\0"
    "VariableParametersList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtArteryTechOutputSetupUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QStringList,    9,

       0        // eod
};

void QtArteryTechOutputSetupUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtArteryTechOutputSetupUI *_t = static_cast<QtArteryTechOutputSetupUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NumberOfStepsForOutputLineEditSlot(); break;
        case 1: _t->TimeIntervalForOutputLineEditSlot(); break;
        case 2: _t->OkPushButtonSlots(); break;
        case 3: _t->CancelPushButtonSlots(); break;
        case 4: _t->GetVerifyPasswordStatuSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->GetVariableParametersSignalSlot((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QtArteryTechOutputSetupUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QtArteryTechOutputSetupUI.data,
      qt_meta_data_QtArteryTechOutputSetupUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtArteryTechOutputSetupUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtArteryTechOutputSetupUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtArteryTechOutputSetupUI.stringdata0))
        return static_cast<void*>(const_cast< QtArteryTechOutputSetupUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int QtArteryTechOutputSetupUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
