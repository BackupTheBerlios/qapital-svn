/****************************************************************************
** RedServer meta object code from reading C++ file 'redserver.h'
**
** Created: Tue Feb 22 16:25:01 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.2.3   edited Nov 10 11:18 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../redserver.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *RedServer::className() const
{
    return "RedServer";
}

QMetaObject *RedServer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_RedServer( "RedServer", &RedServer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString RedServer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RedServer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString RedServer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RedServer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* RedServer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QServerSocket::staticMetaObject();
    static const QUMethod slot_0 = {"removerBans", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "RedCliente", QUParameter::In }
    };
    static const QUMethod slot_1 = {"redServerQuitarCliente", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "removerBans()", &slot_0, QMetaData::Public },
	{ "redServerQuitarCliente(RedCliente*)", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"RedServer", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_RedServer.setMetaObject( metaObj );
    return metaObj;
}

void* RedServer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "RedServer" ) )
	return this;
    return QServerSocket::qt_cast( clname );
}

bool RedServer::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: removerBans(); break;
    case 1: redServerQuitarCliente((RedCliente*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QServerSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool RedServer::qt_emit( int _id, QUObject* _o )
{
    return QServerSocket::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool RedServer::qt_property( int id, int f, QVariant* v)
{
    return QServerSocket::qt_property( id, f, v);
}

bool RedServer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
