/* Clase: BDInstrucciones
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 15/08/2004
 * Fecha de modificacion:
*/

/********************************************************************************
 *   Copyright (C) 2004 by CetiSoft                                        	*
 *   cetisoft@linuxmail.org                                                	*
 *                                                                         	*
 *   This program is free software; you can redistribute it and/or modify  	*
 *   it under the terms of the GNU General Public License as published by  	*
 *   the Free Software Foundation; either version 2 of the License, or     	*
 *   (at your option) any later version.                                   	*
 *                                                                         	*
 *   This program is distributed in the hope that it will be useful,       	*
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        	*
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        	*
 *   GNU General Public License for more details.                          	*
 *                                                                         	*
 *   You should have received a copy of the GNU General Public License     	*
 *   along with this program; if not, write to the                         	*
 *   Free Software Foundation, Inc.,                                       	*
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             	*
 *******************************************************************************/

#include "bdinstrucciones.h"

/**
Constructor
*/
qpsbd::BDInstrucciones::BDInstrucciones()
{
	qDebug("[Construyendo BDInstrucciones]");
}

/**
Destructor
*/
qpsbd::BDInstrucciones::~BDInstrucciones()
{
	qDebug("[Destruyendo BDInstrucciones]");
}

/**
Esta funcion se encarga de hacer un cache de instrucciones midas
@param conexiones: es la conexion con la base de datos.
@param dbnames: lista de los nombres de las bases de datos que van a ser afectadas en la operacion.
*/

bool qpsbd::BDInstrucciones::cargarInstrucciones(SbBDConexion conexiones, QStringList dbnames)
{
	basesDeDatos = conexiones;
	for (uint i = 0; i < dbnames.count(); i++)
	{
		QSqlDatabase *dbTmp = conexiones.obtenerBD( dbnames[i] );

		if (dbTmp->open() )
		{
			//QPINFO(QObject::tr("Se logro abrir la base de datos %1!").arg(dbTmp->databaseName()) );
			QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, QObject::tr("Se logro abrir la base de datos %1!").arg(dbTmp->databaseName()));
		}
		else
		{
			//QPERROR(QObject::tr("No se logro abrir la base de datos %1!").arg(dbTmp->databaseName()) );
			QPLOGGER.salvarLog(SBLogger::QP_ERROR, SBLogger::SERVIDOR, QObject::tr("No se logro abrir la base de datos %1!").arg(dbTmp->databaseName()));
			return false;
		}
		
		if ( i == 0)
		{
			QSqlQuery query = dbTmp->exec( "SELECT codigo, sentencia FROM sentencia_sql ORDER BY oid desc");
				
			if ( query.isActive() )
			{
				while ( query.next() )
				{
					// Almacenar en un QDict para mantener un cache de las instrucciones.
//					std::cout << (QString) query.value(0).toString() << " " << (QString) 	query.value(1).toString() << std::endl;
					QString strcodigo = query.value(0).toString();
					QString *strsentencia = new QString(query.value(1).toString());

					cacheInstrucciones.insert(strcodigo, strsentencia);
				}
			}
			else
			{
				QString errmsg = dbTmp->lastError().text();
				std::cout << errmsg << std::endl;
				return false;
			}
		}
		
//		std::cout << "Instruccion: " << obtenerInstruccion("SEL0001") << std::endl;
		QSqlQuery query = dbTmp->exec( QString(obtenerInstruccion("SEL0001")) );
		
		if ( query.isActive() )
		{
			while ( query.next() )
			{
				QString strperms = "K-" + dbnames[i] + "-" + query.value(1).toString().stripWhiteSpace() +"-"+ query.value(0).toString().stripWhiteSpace();
#ifdef DEBUG
				std::cout << strperms << std::endl;
#endif
				permisos.insert(strperms, new bool(true) );
			}
//			std::cout << "[OK]\n";
		}
		else
		{
			QString errmsg = dbTmp->lastError().text();
			std::cout << errmsg << std::endl;
//			return false;
		}
		
		dbTmp->close();
	}
	return true;
}

/**
* Esta funcion se encarga de devolver la instruccion perteneciente al Hash de instrucciones.
* @param codigo: Codigo de la instruccion requerida
* @see obtenerInstruccion(const QString &codigo, const QStringList &argumentos) const
*/
QString qpsbd::BDInstrucciones::obtenerInstruccion(const QString &codigo) const
{
	QString strTmp = (QString) *cacheInstrucciones.find(codigo);
	
	if (strTmp.isNull() )
	{
		// La consulta no existe!!
		qDebug(QObject::tr("BDInstrucciones/obtenerInstruccion: La consulta no existe"));
	}
	return strTmp;
}

/**
* Funcion sobrecargada, retorna la instruccion sql con los tokens modificados.
* @param codigo: codigo de la instruccion requerida.
* @param argumentos: argumentos a ser reemplazados por los tokens en la instruccion
* @see obtenerInstruccion(const QString &codigo) const
*/
QString qpsbd::BDInstrucciones::obtenerInstruccion(const QString &codigo, const QStringList &argumentos) const
{
	QString instruccionTmp = obtenerInstruccion(codigo);
	uint tokens = instruccionTmp.contains('?');
	if (tokens == argumentos.count())
	{
		for (uint i = 0; i < tokens; i++ )
		{
			int pos = instruccionTmp.find('?');
			instruccionTmp = instruccionTmp.replace(pos, 1, "%1" );
			instruccionTmp = instruccionTmp.arg( argumentos[i] );
		}
	}
	else
	{
		qDebug( QObject::tr("BDInstruccion/obtenerInstruccion: Numero de argumentos incorrecto.") );
	}
	return instruccionTmp;
}

/**
* Esta funcion ejecuta una consulta en la base de datos
* @param dbname: Nombre de la base de datos
* @param sqlkey: Llave de la instruccion SQL
 */
QSqlQuery qpsbd::BDInstrucciones::exec(QString dbname, QString sqlkey)
{
	QSqlDatabase *dbTmp = basesDeDatos.obtenerBD(dbname);
	if (dbTmp->open())
	{
		QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, QObject::tr("Obteniendo permisos sobre instrucciones."));
	}
	QString sqlTmp = this->obtenerInstruccion(sqlkey);
	QSqlQuery query = dbTmp->exec(sqlTmp);
	return query;
}

/**
* Esta funcion ejecuta una instruccion en la base de datos, esta instruccion recibe una lista de argumentos para la consulta
* @param dbname: nombre de la base de datos
* @param sqlkey: Codigo de la instruccion
* @param args: Lista de argumentos
 */
QSqlQuery qpsbd::BDInstrucciones::exec(QString dbname, QString sqlkey, QStringList args)
{
	QSqlDatabase *dbTmp = basesDeDatos.obtenerBD(dbname);
	if (dbTmp->open())
	{
		QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, QObject::tr("Obteniendo permisos sobre instrucciones."));
	}
	QString sqlTmp = this->obtenerInstruccion(sqlkey, args);
	QSqlQuery query = dbTmp->exec(sqlTmp);
	return query;
}

