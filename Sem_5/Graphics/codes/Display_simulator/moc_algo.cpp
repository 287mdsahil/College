/****************************************************************************
** Meta object code from reading C++ file 'algo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "sources/algo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'algo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AlgoWidget_t {
    QByteArrayData data[26];
    char stringdata0[433];
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
QT_MOC_LITERAL(5, 56, 18), // "unPaintPointSignal"
QT_MOC_LITERAL(6, 75, 16), // "makePointRequest"
QT_MOC_LITERAL(7, 92, 3), // "ind"
QT_MOC_LITERAL(8, 96, 23), // "makePointRequestPolygon"
QT_MOC_LITERAL(9, 120, 37), // "makePointRequestPolygonTransf..."
QT_MOC_LITERAL(10, 158, 19), // "receiveClickedPoint"
QT_MOC_LITERAL(11, 178, 1), // "p"
QT_MOC_LITERAL(12, 180, 24), // "callLineDrawingAlgorithm"
QT_MOC_LITERAL(13, 205, 26), // "callCircleDrawingAlgorithm"
QT_MOC_LITERAL(14, 232, 27), // "callEllipseDrawingAlgorithm"
QT_MOC_LITERAL(15, 260, 20), // "callFillingAlgorithm"
QT_MOC_LITERAL(16, 281, 21), // "callClippingAlgorithm"
QT_MOC_LITERAL(17, 303, 16), // "setInternalPoint"
QT_MOC_LITERAL(18, 320, 14), // "connectPolygon"
QT_MOC_LITERAL(19, 335, 13), // "translateSlot"
QT_MOC_LITERAL(20, 349, 12), // "rotationSlot"
QT_MOC_LITERAL(21, 362, 11), // "scalingSlot"
QT_MOC_LITERAL(22, 374, 28), // "connectPolygonTransformation"
QT_MOC_LITERAL(23, 403, 11), // "clearPoints"
QT_MOC_LITERAL(24, 415, 8), // "drawLine"
QT_MOC_LITERAL(25, 424, 8) // "drawRect"

    },
    "AlgoWidget\0pointRequest\0\0paintPointSignal\0"
    "pair<int,int>\0unPaintPointSignal\0"
    "makePointRequest\0ind\0makePointRequestPolygon\0"
    "makePointRequestPolygonTransformation\0"
    "receiveClickedPoint\0p\0callLineDrawingAlgorithm\0"
    "callCircleDrawingAlgorithm\0"
    "callEllipseDrawingAlgorithm\0"
    "callFillingAlgorithm\0callClippingAlgorithm\0"
    "setInternalPoint\0connectPolygon\0"
    "translateSlot\0rotationSlot\0scalingSlot\0"
    "connectPolygonTransformation\0clearPoints\0"
    "drawLine\0drawRect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlgoWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       3,    1,  127,    2, 0x06 /* Public */,
       3,    2,  130,    2, 0x06 /* Public */,
       5,    1,  135,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  138,    2, 0x0a /* Public */,
       8,    0,  141,    2, 0x0a /* Public */,
       9,    0,  142,    2, 0x0a /* Public */,
      10,    1,  143,    2, 0x0a /* Public */,
      12,    0,  146,    2, 0x0a /* Public */,
      13,    0,  147,    2, 0x0a /* Public */,
      14,    0,  148,    2, 0x0a /* Public */,
      15,    0,  149,    2, 0x0a /* Public */,
      16,    0,  150,    2, 0x0a /* Public */,
      17,    0,  151,    2, 0x0a /* Public */,
      18,    0,  152,    2, 0x0a /* Public */,
      19,    0,  153,    2, 0x0a /* Public */,
      20,    0,  154,    2, 0x0a /* Public */,
      21,    0,  155,    2, 0x0a /* Public */,
      22,    0,  156,    2, 0x0a /* Public */,
      23,    0,  157,    2, 0x0a /* Public */,
      24,    0,  158,    2, 0x0a /* Public */,
      25,    0,  159,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QColor,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void AlgoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AlgoWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pointRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->paintPointSignal((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 2: _t->paintPointSignal((*reinterpret_cast< pair<int,int>(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 3: _t->unPaintPointSignal((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 4: _t->makePointRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->makePointRequestPolygon(); break;
        case 6: _t->makePointRequestPolygonTransformation(); break;
        case 7: _t->receiveClickedPoint((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 8: _t->callLineDrawingAlgorithm(); break;
        case 9: _t->callCircleDrawingAlgorithm(); break;
        case 10: _t->callEllipseDrawingAlgorithm(); break;
        case 11: _t->callFillingAlgorithm(); break;
        case 12: _t->callClippingAlgorithm(); break;
        case 13: _t->setInternalPoint(); break;
        case 14: _t->connectPolygon(); break;
        case 15: _t->translateSlot(); break;
        case 16: _t->rotationSlot(); break;
        case 17: _t->scalingSlot(); break;
        case 18: _t->connectPolygonTransformation(); break;
        case 19: _t->clearPoints(); break;
        case 20: _t->drawLine(); break;
        case 21: _t->drawRect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AlgoWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlgoWidget::pointRequest)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AlgoWidget::*)(pair<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlgoWidget::paintPointSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AlgoWidget::*)(pair<int,int> , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlgoWidget::paintPointSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AlgoWidget::*)(pair<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AlgoWidget::unPaintPointSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AlgoWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_AlgoWidget.data,
    qt_meta_data_AlgoWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AlgoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AlgoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AlgoWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AlgoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void AlgoWidget::pointRequest(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AlgoWidget::paintPointSignal(pair<int,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AlgoWidget::paintPointSignal(pair<int,int> _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AlgoWidget::unPaintPointSignal(pair<int,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
