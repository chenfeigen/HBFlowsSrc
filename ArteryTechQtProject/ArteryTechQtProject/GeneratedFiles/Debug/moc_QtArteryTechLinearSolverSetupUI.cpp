/****************************************************************************
** Meta object code from reading C++ file 'QtArteryTechLinearSolverSetupUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtArteryTechLinearSolverSetupUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtArteryTechLinearSolverSetupUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtArteryTechLinearSolverSetupUI_t {
    QByteArrayData data[7];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtArteryTechLinearSolverSetupUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtArteryTechLinearSolverSetupUI_t qt_meta_stringdata_QtArteryTechLinearSolverSetupUI = {
    {
QT_MOC_LITERAL(0, 0, 31), // "QtArteryTechLinearSolverSetupUI"
QT_MOC_LITERAL(1, 32, 17), // "OkPushButtonSlots"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 21), // "CancelPushButtonSlots"
QT_MOC_LITERAL(4, 73, 25), // "RestartNumberLineEditSlot"
QT_MOC_LITERAL(5, 99, 30), // "MaxIterationNumberLineEditSlot"
QT_MOC_LITERAL(6, 130, 32) // "RatioOfThe1stStepTolLineEditSlot"

    },
    "QtArteryTechLinearSolverSetupUI\0"
    "OkPushButtonSlots\0\0CancelPushButtonSlots\0"
    "RestartNumberLineEditSlot\0"
    "MaxIterationNumberLineEditSlot\0"
    "RatioOfThe1stStepTolLineEditSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtArteryTechLinearSolverSetupUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtArteryTechLinearSolverSetupUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtArteryTechLinearSolverSetupUI *_t = static_cast<QtArteryTechLinearSolverSetupUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OkPushButtonSlots(); break;
        case 1: _t->CancelPushButtonSlots(); break;
        case 2: _t->RestartNumberLineEditSlot(); break;
        case 3: _t->MaxIterationNumberLineEditSlot(); break;
        case 4: _t->RatioOfThe1stStepTolLineEditSlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QtArteryTechLinearSolverSetupUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QtArteryTechLinearSolverSetupUI.data,
      qt_meta_data_QtArteryTechLinearSolverSetupUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtArteryTechLinearSolverSetupUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtArteryTechLinearSolverSetupUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtArteryTechLinearSolverSetupUI.stringdata0))
        return static_cast<void*>(const_cast< QtArteryTechLinearSolverSetupUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int QtArteryTechLinearSolverSetupUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE