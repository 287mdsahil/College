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
    QByteArrayData data[31];
    char stringdata0[516];
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
QT_MOC_LITERAL(6, 75, 16), // "selectPoint1Slot"
QT_MOC_LITERAL(7, 92, 16), // "selectPoint2Slot"
QT_MOC_LITERAL(8, 109, 22), // "drawReflectionLineSlot"
QT_MOC_LITERAL(9, 132, 16), // "makePointRequest"
QT_MOC_LITERAL(10, 149, 3), // "ind"
QT_MOC_LITERAL(11, 153, 23), // "makePointRequestPolygon"
QT_MOC_LITERAL(12, 177, 37), // "makePointRequestPolygonTransf..."
QT_MOC_LITERAL(13, 215, 19), // "receiveClickedPoint"
QT_MOC_LITERAL(14, 235, 1), // "p"
QT_MOC_LITERAL(15, 237, 24), // "callLineDrawingAlgorithm"
QT_MOC_LITERAL(16, 262, 26), // "callCircleDrawingAlgorithm"
QT_MOC_LITERAL(17, 289, 27), // "callEllipseDrawingAlgorithm"
QT_MOC_LITERAL(18, 317, 20), // "callFillingAlgorithm"
QT_MOC_LITERAL(19, 338, 21), // "callClippingAlgorithm"
QT_MOC_LITERAL(20, 360, 16), // "setInternalPoint"
QT_MOC_LITERAL(21, 377, 14), // "connectPolygon"
QT_MOC_LITERAL(22, 392, 13), // "translateSlot"
QT_MOC_LITERAL(23, 406, 12), // "rotationSlot"
QT_MOC_LITERAL(24, 419, 11), // "scalingSlot"
QT_MOC_LITERAL(25, 431, 14), // "reflectionSlot"
QT_MOC_LITERAL(26, 446, 10), // "bezierSlot"
QT_MOC_LITERAL(27, 457, 28), // "connectPolygonTransformation"
QT_MOC_LITERAL(28, 486, 11), // "clearPoints"
QT_MOC_LITERAL(29, 498, 8), // "drawLine"
QT_MOC_LITERAL(30, 507, 8) // "drawRect"

    },
    "AlgoWidget\0pointRequest\0\0paintPointSignal\0"
    "pair<int,int>\0unPaintPointSignal\0"
    "selectPoint1Slot\0selectPoint2Slot\0"
    "drawReflectionLineSlot\0makePointRequest\0"
    "ind\0makePointRequestPolygon\0"
    "makePointRequestPolygonTransformation\0"
    "receiveClickedPoint\0p\0callLineDrawingAlgorithm\0"
    "callCircleDrawingAlgorithm\0"
    "callEllipseDrawingAlgorithm\0"
    "callFillingAlgorithm\0callClippingAlgorithm\0"
    "setInternalPoint\0connectPolygon\0"
    "translateSlot\0rotationSlot\0scalingSlot\0"
    "reflectionSlot\0bezierSlot\0"
    "connectPolygonTransformation\0clearPoints\0"
    "drawLine\0drawRect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AlgoWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  149,    2, 0x06 /* Public */,
       3,    1,  152,    2, 0x06 /* Public */,
       3,    2,  155,    2, 0x06 /* Public */,
       5,    1,  160,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  163,    2, 0x0a /* Public */,
       7,    0,  164,    2, 0x0a /* Public */,
       8,    0,  165,    2, 0x0a /* Public */,
       9,    1,  166,    2, 0x0a /* Public */,
      11,    0,  169,    2, 0x0a /* Public */,
      12,    0,  170,    2, 0x0a /* Public */,
      13,    1,  171,    2, 0x0a /* Public */,
      15,    0,  174,    2, 0x0a /* Public */,
      16,    0,  175,    2, 0x0a /* Public */,
      17,    0,  176,    2, 0x0a /* Public */,
      18,    0,  177,    2, 0x0a /* Public */,
      19,    0,  178,    2, 0x0a /* Public */,
      20,    0,  179,    2, 0x0a /* Public */,
      21,    0,  180,    2, 0x0a /* Public */,
      22,    0,  181,    2, 0x0a /* Public */,
      23,    0,  182,    2, 0x0a /* Public */,
      24,    0,  183,    2, 0x0a /* Public */,
      25,    0,  184,    2, 0x0a /* Public */,
      26,    0,  185,    2, 0x0a /* Public */,
      27,    0,  186,    2, 0x0a /* Public */,
      28,    0,  187,    2, 0x0a /* Public */,
      29,    0,  188,    2, 0x0a /* Public */,
      30,    0,  189,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QColor,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,   14,
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
        case 4: _t->selectPoint1Slot(); break;
        case 5: _t->selectPoint2Slot(); break;
        case 6: _t->drawReflectionLineSlot(); break;
        case 7: _t->makePointRequest((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->makePointRequestPolygon(); break;
        case 9: _t->makePointRequestPolygonTransformation(); break;
        case 10: _t->receiveClickedPoint((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 11: _t->callLineDrawingAlgorithm(); break;
        case 12: _t->callCircleDrawingAlgorithm(); break;
        case 13: _t->callEllipseDrawingAlgorithm(); break;
        case 14: _t->callFillingAlgorithm(); break;
        case 15: _t->callClippingAlgorithm(); break;
        case 16: _t->setInternalPoint(); break;
        case 17: _t->connectPolygon(); break;
        case 18: _t->translateSlot(); break;
        case 19: _t->rotationSlot(); break;
        case 20: _t->scalingSlot(); break;
        case 21: _t->reflectionSlot(); break;
        case 22: _t->bezierSlot(); break;
        case 23: _t->connectPolygonTransformation(); break;
        case 24: _t->clearPoints(); break;
        case 25: _t->drawLine(); break;
        case 26: _t->drawRect(); break;
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
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 27;
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
