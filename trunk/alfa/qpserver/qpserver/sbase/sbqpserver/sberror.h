#ifndef SBERROR_H
#define SBEERROR_H

#include <qstring.h>
#include <qdir.h>
#include <qprocess.h>
#include <qtextstream.h>
#include <qdatetime.h>
#include <qvaluelist.h>
#include <unistd.h>
#include <iostream>
#include <qdict.h>

typedef QDict<QString> StringHash;

class SBError
{
	private:
		StringHash cacheErrores;
		
	public :	
	  	SBError();
		/*void logError( QString , Q_UINT16 , Q_UINT16, Q_UINT16 );*/
		~SBError();
		void agregarError( QString, QString );
		QString  buscar( QString );
		static QString obtenerError( QString );	
};

#endif
