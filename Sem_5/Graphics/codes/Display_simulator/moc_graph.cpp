/****************************************************************************
** Meta object code from reading C++ file 'graph.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sources/graph.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Graph_t {
    QByteArrayData data[12];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Graph_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Graph_t qt_meta_stringdata_Graph = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Graph"
QT_MOC_LITERAL(1, 6, 11), // "pointSelect"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "pair<int,int>"
QT_MOC_LITERAL(4, 33, 10), // "pointHover"
QT_MOC_LITERAL(5, 44, 14), // "GraphResetSlot"
QT_MOC_LITERAL(6, 59, 1), // "p"
QT_MOC_LITERAL(7, 61, 1), // "n"
QT_MOC_LITERAL(8, 63, 19), // "GraphPaintPointSlot"
QT_MOC_LITERAL(9, 83, 5), // "point"
QT_MOC_LITERAL(10, 89, 9), // "fillColor"
QT_MOC_LITERAL(11, 99, 21) // "GraphUnPaintPointSlot"

    },
    "Graph\0pointSelect\0\0pair<int,int>\0"
    "pointHover\0GraphResetSlot\0p\0n\0"
    "GraphPaintPointSlot\0point\0fillColor\0"
    "GraphUnPaintPointSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Graph[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   50,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,
       8,    2,   58,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QColor,    9,   10,
    QMetaType::Void, 0x80000000 | 3,    9,

       0        // eod
};

void Graph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Graph *_t = static_cast<Graph *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pointSelect((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 1: _t->pointHover((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 2: _t->GraphResetSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->GraphPaintPointSlot((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        case 4: _t->GraphPaintPointSlot((*reinterpret_cast< pair<int,int>(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 5: _t->GraphUnPaintPointSlot((*reinterpret_cast< pair<int,int>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Graph::*)(pair<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph::pointSelect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Graph::*)(pair<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Graph::pointHover)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Graph::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Graph.data,
      qt_meta_data_Graph,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Graph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Graph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Graph.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Graph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
void Graph::pointSelect(pair<int,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Graph::pointHover(pair<int,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
