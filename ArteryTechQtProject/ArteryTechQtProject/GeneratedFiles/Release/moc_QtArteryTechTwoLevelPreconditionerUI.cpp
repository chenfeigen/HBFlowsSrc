/****************************************************************************
** Meta object code from reading C++ file 'QtArteryTechTwoLevelPreconditionerUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtArteryTechTwoLevelPreconditionerUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtArteryTechTwoLevelPreconditionerUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtArteryTechTwoLevelPreconditionerUI_t {
    QByteArrayData data[5];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtArteryTechTwoLevelPreconditionerUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtArteryTechTwoLevelPreconditionerUI_t qt_meta_stringdata_QtArteryTechTwoLevelPreconditionerUI = {
    {
QT_MOC_LITERAL(0, 0, 36), // "QtArteryTechTwoLevelPrecondit..."
QT_MOC_LITERAL(1, 37, 35), // "TwoLevelPreconditionerCheckBo..."
QT_MOC_LITERAL(2, 73, 0), // ""
QT_MOC_LITERAL(3, 74, 17), // "OkPushButtonSlots"
QT_MOC_LITERAL(4, 92, 21) // "CancelPushButtonSlots"

    },
    "QtArteryTechTwoLevelPreconditionerUI\0"
    "TwoLevelPreconditionerCheckBoxSlots\0"
    "\0OkPushButtonSlots\0CancelPushButtonSlots"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtArteryTechTwoLevelPreconditionerUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtArteryTechTwoLevelPreconditionerUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtArteryTechTwoLevelPreconditionerUI *_t = static_cast<QtArteryTechTwoLevelPreconditionerUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TwoLevelPreconditionerCheckBoxSlots(); break;
        case 1: _t->OkPushButtonSlots(); break;
        case 2: _t->CancelPushButtonSlots(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QtArteryTechTwoLevelPreconditionerUI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QtArteryTechTwoLevelPreconditionerUI.data,
      qt_meta_data_QtArteryTechTwoLevelPreconditionerUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtArteryTechTwoLevelPreconditionerUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtArteryTechTwoLevelPreconditionerUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtArteryTechTwoLevelPreconditionerUI.stringdata0))
        return static_cast<void*>(const_cast< QtArteryTechTwoLevelPreconditionerUI*>(this));
    return QDialog::qt_metacast(_clname);
}

int QtArteryTechTwoLevelPreconditionerUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
