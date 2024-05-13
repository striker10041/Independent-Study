/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../code/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "signalMousePress",
    "",
    "signalMouseRelease",
    "signalMouseMove",
    "signalWhell",
    "signalAddPoins",
    "signalColor",
    "slotMousePress",
    "slotMouseRelease",
    "slotMouseMove",
    "slotWhell",
    "slotAddPoints",
    "slotColor",
    "on_cb_nAuto_stateChanged",
    "arg1",
    "on_sb_n_valueChanged",
    "on_pb_clear_clicked",
    "on_pb_saveAs_clicked",
    "on_pb_update_clicked",
    "on_cb_choosePoint_stateChanged",
    "on_cb_fill_stateChanged",
    "on_cb_showGrid_stateChanged",
    "on_cb_setZ_stateChanged",
    "on_pb_default_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  146,    2, 0x06,    1 /* Public */,
       3,    0,  149,    2, 0x06,    3 /* Public */,
       4,    1,  150,    2, 0x06,    4 /* Public */,
       5,    1,  153,    2, 0x06,    6 /* Public */,
       6,    1,  156,    2, 0x06,    8 /* Public */,
       7,    0,  159,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  160,    2, 0x08,   11 /* Private */,
       9,    0,  163,    2, 0x08,   13 /* Private */,
      10,    1,  164,    2, 0x08,   14 /* Private */,
      11,    1,  167,    2, 0x08,   16 /* Private */,
      12,    1,  170,    2, 0x08,   18 /* Private */,
      13,    0,  173,    2, 0x08,   20 /* Private */,
      14,    1,  174,    2, 0x08,   21 /* Private */,
      16,    1,  177,    2, 0x08,   23 /* Private */,
      17,    0,  180,    2, 0x08,   25 /* Private */,
      18,    0,  181,    2, 0x08,   26 /* Private */,
      19,    0,  182,    2, 0x08,   27 /* Private */,
      20,    1,  183,    2, 0x08,   28 /* Private */,
      21,    1,  186,    2, 0x08,   30 /* Private */,
      22,    1,  189,    2, 0x08,   32 /* Private */,
      23,    1,  192,    2, 0x08,   34 /* Private */,
      24,    0,  195,    2, 0x08,   36 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'signalMousePress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'signalMouseRelease'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalMouseMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'signalWhell'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalAddPoins'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'signalColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotMousePress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'slotMouseRelease'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotMouseMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'slotWhell'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotAddPoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'slotColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cb_nAuto_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_sb_n_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pb_clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_saveAs_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pb_update_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cb_choosePoint_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_cb_fill_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_cb_showGrid_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_cb_setZ_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pb_default_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalMousePress((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 1: _t->signalMouseRelease(); break;
        case 2: _t->signalMouseMove((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->signalWhell((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->signalAddPoins((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 5: _t->signalColor(); break;
        case 6: _t->slotMousePress((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 7: _t->slotMouseRelease(); break;
        case 8: _t->slotMouseMove((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 9: _t->slotWhell((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->slotAddPoints((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 11: _t->slotColor(); break;
        case 12: _t->on_cb_nAuto_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_sb_n_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_pb_clear_clicked(); break;
        case 15: _t->on_pb_saveAs_clicked(); break;
        case 16: _t->on_pb_update_clicked(); break;
        case 17: _t->on_cb_choosePoint_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_cb_fill_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_cb_showGrid_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_cb_setZ_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_pb_default_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QPoint );
            if (_t _q_method = &MainWindow::signalMousePress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::signalMouseRelease; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (_t _q_method = &MainWindow::signalMouseMove; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (_t _q_method = &MainWindow::signalWhell; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QPoint );
            if (_t _q_method = &MainWindow::signalAddPoins; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::signalColor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalMousePress(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signalMouseRelease()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::signalMouseMove(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signalWhell(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::signalAddPoins(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::signalColor()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
