/****************************************************************************
** Form meta object code from reading C++ file 'form.h'
**
** Created: Fri May 13 23:40:17 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.1   edited Feb 18 14:21 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "form.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Form::className() const
{
    return "Form";
}

QMetaObject *Form::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Form( "Form", &Form::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Form::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Form", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Form::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Form", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Form::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotPropertiesChanged", 1, param_slot_0 };
    static const QUMethod slot_1 = {"slotOpenFile", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotPropertiesChanged(int)", &slot_0, QMetaData::Public },
	{ "slotOpenFile()", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"Form", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Form.setMetaObject( metaObj );
    return metaObj;
}

void* Form::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Form" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool Form::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotPropertiesChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: slotOpenFile(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Form::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Form::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool Form::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
