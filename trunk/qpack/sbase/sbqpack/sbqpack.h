/* Archivo: sbqack.h
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 12/08/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Contiene definiciones globales de la aplicacion.
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

#ifndef SBQAPITAL_H
#define SBQAPITAL_H

#include <qobject.h>
#include <iostream>
#include <qstring.h>
#include <qdict.h>
#include "sberror.h"
#include "sblogger.h"

/**
@author CetiSoft
*/

#ifdef DEBUG
	#ifndef INIQPC
 		#define INIQPC if ( this->inherits("QObject") ) qDebug(QString("[Construyendo %1]").arg( className()) );
	#endif
#else
	#ifndef INIQPC
		#define INIQPC
	#endif
#endif

#ifdef DEBUG
	#ifndef FINQPC
		#define FINQPC if ( this->inherits("QObject") ) qDebug(QString("[Destruyendo %1]").arg( className()) );
	#endif
#else
	#ifndef FINQPC
		#define FINQPC
	#endif
#endif

typedef QDict<int> HashInt;
typedef QDict<QString> StringHash;

// FIXME: Eliminar elementos innecesarios

namespace sbqpack
{
	// TODO: analizar la posiblidad de mover todos estos strings a macros, por cuestion de velocidad.
	const QString APPNAME = "QPack";
	const QString VERSION = "0.0.2a";
	const QString QAPITAL_HOME = "";
	
	const QString HOME = QDir::homeDirPath();
	const QString CONFIGRC = HOME + "/.qapital/";
	
#ifdef INSTALLPATH
	const QString QPDATADIR = INSTALLPATH;
#else
	const QString QPDATADIR = "../../data/"; // FIXME: hacerlo relatativo a la ruta de instalacion del programa!
#endif	
	const QString GUIDATADIR = QPDATADIR + "/gui/";
	const QString XMLDATADIR = QPDATADIR + "/xml";
	
	const QString TRANSDATADIR = QPDATADIR + "/traducciones/";
	const QString PATHLOG = CONFIGRC + "/logs/";
	
	const QString AUTORES= "CetiSoft";
	const QString EMAIL = "cetisoft@linuxmail.org";
	
	const QString TMPDIR = "/tmp/";
}

namespace sbqpadmin
{
	// TODO: analizar la posiblidad de mover todos estos strings a macros, por cuestion de velocidad.
	const QString APPNAME = "QPAdmin";
	const QString VERSION = "0.0.2a";
	
	const QString GUIADMINDATADIR = sbqpack::QPDATADIR + "/qpadmin/gui/";
	const QString XMLADMINDATADIR = sbqpack::QPDATADIR + "/qpadmin/xml/";
	
	const QString CONFIGRC = sbqpack::CONFIGRC + "/QPAConfig.xml";
	
	// Objeto global logger.
	static SBLogger QPLOGGER(SBLogger::VERBOSEFILE, SBLogger::ADMIN, sbqpack::PATHLOG+"QPAdmin.log");
}

namespace sbqpcliente
{
	// TODO: analizar la posiblidad de mover todos estos strings a macros, por cuestion de velocidad.
	const QString APPNAME = "QPCliente";
	const QString VERSION = "0.0.2a";
	
	const QString GUICLIENTDATADIR = sbqpack::QPDATADIR + "/qpclient/gui/";
	const QString XMLCLIENTDATADIR = sbqpack::QPDATADIR + "/qpclient/xml/";
	
	const QString CONFIGRC = sbqpack::CONFIGRC + "/QPCConfig.xml";
	
	// Objeto global logger.
	static SBLogger QPLOGGER(SBLogger::VERBOSEFILE, SBLogger::CLIENTE, sbqpack::PATHLOG+"QPCliente.log");
}

#endif

