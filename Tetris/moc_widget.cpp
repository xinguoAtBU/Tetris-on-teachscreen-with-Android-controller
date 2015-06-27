/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Thu Dec 11 22:23:29 2014
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      23,    7,    7,    7, 0x08,
      39,    7,    7,    7, 0x08,
      63,    7,    7,    7, 0x08,
      89,    7,    7,    7, 0x08,
     115,    7,    7,    7, 0x08,
     141,    7,    7,    7, 0x08,
     167,    7,    7,    7, 0x08,
     193,    7,    7,    7, 0x08,
     220,    7,    7,    7, 0x08,
     247,    7,    7,    7, 0x08,
     276,  274,    7,    7, 0x08,
     318,  301,    7,    7, 0x08,
     367,  361,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0timer_upDate()\0timer2_upDate()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_3_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushButton_6_clicked()\0"
    "on_pushButton_8_clicked()\0"
    "on_pushButton_11_clicked()\0"
    "on_pushButton_10_clicked()\0"
    "on_pushButton_12_clicked()\0e\0"
    "paintEvent(QPaintEvent*)\0painter,x,y,text\0"
    "drawRotatedText(QPainter*,int,int,QString)\0"
    "value\0on_horizontalSlider_valueChanged(int)\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

const QMetaObject *Widget::metaObject() const
{
    return &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: timer_upDate(); break;
        case 1: timer2_upDate(); break;
        case 2: on_pushButton_clicked(); break;
        case 3: on_pushButton_2_clicked(); break;
        case 4: on_pushButton_3_clicked(); break;
        case 5: on_pushButton_4_clicked(); break;
        case 6: on_pushButton_6_clicked(); break;
        case 7: on_pushButton_8_clicked(); break;
        case 8: on_pushButton_11_clicked(); break;
        case 9: on_pushButton_10_clicked(); break;
        case 10: on_pushButton_12_clicked(); break;
        case 11: paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 12: drawRotatedText((*reinterpret_cast< QPainter*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 13: on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
