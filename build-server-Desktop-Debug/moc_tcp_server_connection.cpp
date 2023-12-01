/****************************************************************************
** Meta object code from reading C++ file 'tcp_server_connection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../server/tcp_server_connection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_server_connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpServerConnection_t {
    QByteArrayData data[9];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpServerConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpServerConnection_t qt_meta_stringdata_TcpServerConnection = {
    {
QT_MOC_LITERAL(0, 0, 19), // "TcpServerConnection"
QT_MOC_LITERAL(1, 20, 18), // "clientChangeSignal"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 22), // "setReserveServerSignal"
QT_MOC_LITERAL(4, 63, 24), // "resetReserveServerSignal"
QT_MOC_LITERAL(5, 88, 15), // "keepAliveSignal"
QT_MOC_LITERAL(6, 104, 13), // "setConnection"
QT_MOC_LITERAL(7, 118, 10), // "readClient"
QT_MOC_LITERAL(8, 129, 12) // "disconnected"

    },
    "TcpServerConnection\0clientChangeSignal\0"
    "\0setReserveServerSignal\0"
    "resetReserveServerSignal\0keepAliveSignal\0"
    "setConnection\0readClient\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServerConnection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       3,    0,   54,    2, 0x06 /* Public */,
       4,    0,   55,    2, 0x06 /* Public */,
       5,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   57,    2, 0x0a /* Public */,
       7,    0,   58,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpServerConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpServerConnection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clientChangeSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->setReserveServerSignal(); break;
        case 2: _t->resetReserveServerSignal(); break;
        case 3: _t->keepAliveSignal(); break;
        case 4: _t->setConnection(); break;
        case 5: _t->readClient(); break;
        case 6: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpServerConnection::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerConnection::clientChangeSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpServerConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerConnection::setReserveServerSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpServerConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerConnection::resetReserveServerSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpServerConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpServerConnection::keepAliveSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpServerConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TcpServerConnection.data,
    qt_meta_data_TcpServerConnection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpServerConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServerConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServerConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpServerConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void TcpServerConnection::clientChangeSignal(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpServerConnection::setReserveServerSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TcpServerConnection::resetReserveServerSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TcpServerConnection::keepAliveSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
