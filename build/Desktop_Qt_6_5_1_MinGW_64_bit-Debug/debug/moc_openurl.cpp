/****************************************************************************
** Meta object code from reading C++ file 'openurl.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../openurl.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openurl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
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
struct qt_meta_stringdata_CLASSopenURLENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSopenURLENDCLASS = QtMocHelpers::stringData(
    "openURL",
    "urlSet",
    "",
    "url",
    "on_openURLbuttonBox_accepted",
    "on_selectFileButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSopenURLENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[8];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[29];
    char stringdata5[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSopenURLENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSopenURLENDCLASS_t qt_meta_stringdata_CLASSopenURLENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "openURL"
        QT_MOC_LITERAL(8, 6),  // "urlSet"
        QT_MOC_LITERAL(15, 0),  // ""
        QT_MOC_LITERAL(16, 3),  // "url"
        QT_MOC_LITERAL(20, 28),  // "on_openURLbuttonBox_accepted"
        QT_MOC_LITERAL(49, 27)   // "on_selectFileButton_clicked"
    },
    "openURL",
    "urlSet",
    "",
    "url",
    "on_openURLbuttonBox_accepted",
    "on_selectFileButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSopenURLENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   35,    2, 0x08,    3 /* Private */,
       5,    0,   36,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject openURL::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSopenURLENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSopenURLENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSopenURLENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<openURL, std::true_type>,
        // method 'urlSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_openURLbuttonBox_accepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_selectFileButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void openURL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<openURL *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->urlSet((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_openURLbuttonBox_accepted(); break;
        case 2: _t->on_selectFileButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (openURL::*)(QString );
            if (_t _q_method = &openURL::urlSet; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *openURL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *openURL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSopenURLENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int openURL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void openURL::urlSet(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
