/****************************************************************************
** RedCliente meta object code from reading C++ file 'redcliente.h'
**
** Created: Tue Feb 22 16:12:16 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.2.3   edited Nov 10 11:18 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../redcliente.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *RedCliente::className() const
{
    return "RedCliente";
}

QMetaObject *RedCliente::metaObj = 0;
static QMetaObjectCleanUp cleanUp_RedCliente( "RedCliente", &RedCliente::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString RedCliente::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RedCliente", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString RedCliente::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RedCliente", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* RedCliente::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QSocket::staticMetaObject();
    static const QUMethod slot_0 = {"redClienteLeer", 0, 0 };
    static const QUMethod slot_1 = {"redClienteCerrarConexion", 0, 0 };
    static const QUMethod slot_2 = {"redClienteConexionCerrada", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "redClienteLeer()", &slot_0, QMetaData::Public },
	{ "redClienteCerrarConexion()", &slot_1, QMetaData::Public },
	{ "redClienteConexionCerrada()", &slot_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"RedCliente", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_RedCliente.setMetaObject( metaObj );
    return metaObj;
}

void* RedCliente::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "RedCliente" ) )
	return this;
    return QSocket::qt_cast( clname );
}

bool RedCliente::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: redClienteLeer(); break;
    case 1: redClienteCerrarConexion(); break;
    case 2: redClienteConexionCerrada(); break;
    default:
	return QSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool RedCliente::qt_emit( int _id, QUObject* _o )
{
    return QSocket::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool RedCliente::qt_property( int id, int f, QVariant* v)
{
    return QSocket::qt_property( id, f, v);
}

bool RedCliente::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
