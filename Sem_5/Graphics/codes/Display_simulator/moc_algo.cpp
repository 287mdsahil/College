/****************************************************************************
** Meta object code from reading C++ file 'algo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sources/algo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'algo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AlgoWidget_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AlgoWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AlgoWidget_t qt_meta_stringdata_AlgoWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AlgoWidget"
QT_MOC_LITERAL(1, 11, 12), // "pointRequest"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "paintPointSignal"
QT_MOC_LITERAL(4, 42, 13), // "pair<int,int>"
QT_MOC_LITERAL(5, 56, 16), // "makePointRequest"
QT_MOC_LITERAL(6, 73, 3), // "ind"
QT_MOC_LITERAL(7, 77, 19), // "receiveClickedPoint"
QT_MOC_LITERAL(8, 97, 1), // "p"
QT_MOC_LITERAL(9, 99, 13) // "callAlgorithm"

    },
    "AlgoWidget\0pointRequest\0\0paintPointSignal\0"
    "pair<int,int>\0makePointRequest\0ind\0"
    "receiveClickedPoint\0p\0callAlgorithm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlgoWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   45,    2, 0x0a /* Public */,
       7,    1,   48,    2, 0x0a /* Public */,
       9,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 4,    8,
    QMetaType::Void,

       0        // eod
};

void AlgoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AlgoWidget *_t = static_cast<AlgoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pointRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->paintPointSignal((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 2: _t->makePointRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->receiveClickedPoint((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 4: _t->callAlgorithm(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AlgoWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlgoWidget::pointRequest)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AlgoWidget::*_t)(pair<int,int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AlgoWidget::paintPointSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AlgoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AlgoWidget.data,
      qt_meta_data_AlgoWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AlgoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlgoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AlgoWidget.stringdata0))
        return static_cast<void*>(const_cast< AlgoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AlgoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void AlgoWidget::pointRequest(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AlgoWidget::paintPointSignal(pair<int,int> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
