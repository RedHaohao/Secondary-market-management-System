/****************************************************************************
** Meta object code from reading C++ file 'tab1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tab1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tab1_t {
    QByteArrayData data[10];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tab1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tab1_t qt_meta_stringdata_Tab1 = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Tab1"
QT_MOC_LITERAL(1, 5, 14), // "getProductInfo"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "buyProduct"
QT_MOC_LITERAL(4, 32, 13), // "deleteProduct"
QT_MOC_LITERAL(5, 46, 7), // "message"
QT_MOC_LITERAL(6, 54, 6), // "search"
QT_MOC_LITERAL(7, 61, 9), // "showTable"
QT_MOC_LITERAL(8, 71, 11), // "selectQuery"
QT_MOC_LITERAL(9, 83, 11) // "refreshDate"

    },
    "Tab1\0getProductInfo\0\0buyProduct\0"
    "deleteProduct\0message\0search\0showTable\0"
    "selectQuery\0refreshDate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tab1[] = {

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
       1,    1,   49,    2, 0x08 /* Private */,
       3,    0,   52,    2, 0x08 /* Private */,
       4,    0,   53,    2, 0x08 /* Private */,
       5,    0,   54,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void Tab1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tab1 *_t = static_cast<Tab1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getProductInfo((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->buyProduct(); break;
        case 2: _t->deleteProduct(); break;
        case 3: _t->message(); break;
        case 4: _t->search(); break;
        case 5: _t->showTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->refreshDate(); break;
        default: ;
        }
    }
}

const QMetaObject Tab1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tab1.data,
      qt_meta_data_Tab1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Tab1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tab1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Tab1.stringdata0))
        return static_cast<void*>(const_cast< Tab1*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tab1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
