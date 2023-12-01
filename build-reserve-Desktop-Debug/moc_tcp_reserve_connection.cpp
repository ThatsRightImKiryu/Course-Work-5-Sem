/****************************************************************************
** Meta object code from reading C++ file 'tcp_reserve_connection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../reserve/tcp_reserve_connection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_reserve_connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpReserveConnection_t {
    QByteArrayData data[13];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpReserveConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpReserveConnection_t qt_meta_stringdata_TcpReserveConnection = {
    {
QT_MOC_LITERAL(0, 0, 20), // "TcpReserveConnection"
QT_MOC_LITERAL(1, 21, 18), // "disconnectedSignal"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 18), // "clientChangeSignal"
QT_MOC_LITERAL(4, 60, 22), // "setReserveServerSignal"
QT_MOC_LITERAL(5, 83, 24), // "resetReserveServerSignal"
QT_MOC_LITERAL(6, 108, 15), // "keepAliveSignal"
QT_MOC_LITERAL(7, 124, 10), // "readServer"
QT_MOC_LITERAL(8, 135, 16), // "disconnectedSlot"
QT_MOC_LITERAL(9, 152, 15), // "crashServerSlot"
QT_MOC_LITERAL(10, 168, 13), // "setConnection"
QT_MOC_LITERAL(11, 182, 10), // "readClient"
QT_MOC_LITERAL(12, 193, 12) // "disconnected"

    },
    "TcpReserveConnection\0disconnectedSignal\0"
    "\0clientChangeSignal\0setReserveServerSignal\0"
    "resetReserveServerSignal\0keepAliveSignal\0"
    "readServer\0disconnectedSlot\0crashServerSlot\0"
    "setConnection\0readClient\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpReserveConnection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    2,   70,    2, 0x06 /* Public */,
       4,    0,   75,    2, 0x06 /* Public */,
       5,    0,   76,    2, 0x06 /* Public */,
       6,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   78,    2, 0x0a /* Public */,
       8,    0,   79,    2, 0x0a /* Public */,
       9,    0,   80,    2, 0x0a /* Public */,
      10,    0,   81,    2, 0x0a /* Public */,
      11,    0,   82,    2, 0x0a /* Public */,
      12,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpReserveConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpReserveConnection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->disconnectedSignal(); break;
        case 1: _t->clientChangeSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->setReserveServerSignal(); break;
        case 3: _t->resetReserveServerSignal(); break;
        case 4: _t->keepAliveSignal(); break;
        case 5: _t->readServer(); break;
        case 6: _t->disconnectedSlot(); break;
        case 7: _t->crashServerSlot(); break;
        case 8: _t->setConnection(); break;
        case 9: _t->readClient(); break;
        case 10: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpReserveConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpReserveConnection::disconnectedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpReserveConnection::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpReserveConnection::clientChangeSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpReserveConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpReserveConnection::setReserveServerSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpReserveConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpReserveConnection::resetReserveServerSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpReserveConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpReserveConnection::keepAliveSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpReserveConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpReserveConnection.data,
    qt_meta_data_TcpReserveConnection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpReserveConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpReserveConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpReserveConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpReserveConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TcpReserveConnection::disconnectedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TcpReserveConnection::clientChangeSignal(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpReserveConnection::setReserveServerSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TcpReserveConnection::resetReserveServerSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TcpReserveConnection::keepAliveSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
