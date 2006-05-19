/***************************************************************************
 *   Copyright (C) 2006 by David Cuadrado                                  *
 *   krawek@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include <QCoreApplication>
#include <QHostInfo>

#include "dtserver.h"
#include "sdatabase.h"

#include <dconfig.h>
#include <ddebug.h>

#include "dapplicationproperties.h"


void write_test_config();

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);
	app.setApplicationName("dtserver");

	// Uncomment if you want initial config
// 	write_test_config();
	
	DCONFIG->beginGroup("General");
	
	DApplicationProperties::instance()->setHomeDir( DCONFIG->value("Home", 0).toString() );
	DApplicationProperties::instance()->setDataDir( DApplicationProperties::instance()->homeDir()+"/data/en/" ); // ###: por ahora solo funciona en ingles... pero esta escrito en español... debe traducirse cuando sea posible, esto lo hago para no editar ambos archivos en tiempo de desarrollo.
	
	// Cargar configuracion del servidor
	DCONFIG->beginGroup("Database");
	QString login = DCONFIG->value("Login").toString();
	QString passwd = DCONFIG->value("Password").toString();
	QString dbhost = DCONFIG->value("Host").toString();
	QString dbname = DCONFIG->value("Name").toString();
	
	// Conectar a la base de datos
	SDBM->setupConnection(dbname, login, passwd, dbhost );
	
	if ( !SDBM->open() )
	{
		dDebug() << "Error while trying open database" ;
		return 255;
	}
	
	// Clientes
	DCONFIG->beginGroup("Connection");
	
	QString host = DCONFIG->value("Host", "localhost").toString();
	
	// Cliente
	DTServer clientServer;
	
	if ( !clientServer.openConnection( DTS::Client, host ) )
	{
		dFatal() << QObject::tr("Can't open client server on %1").arg(host);
		return 255;
	}
	else
	{
		dDebug() << QObject::tr("Open client server on %1:%2").arg(host).arg(clientServer.serverPort());
	}
	
	// Administrador
	
	DTServer adminServer;
	
	if ( !adminServer.openConnection( DTS::Admin, host ) )
	{
		dFatal() << QObject::tr("Can't open admin server on %1").arg(host);
		
		return 255;
	}
	else
	{
		dDebug() << QObject::tr("Open admin server on %1:%2").arg(host).arg(adminServer.serverPort());
	}
	
	return app.exec();
}

void write_test_config()
{
	DCONFIG->beginGroup("General");
	DCONFIG->setValue("Home", "/path/to/home");
	DCONFIG->beginGroup("Connection");
	DCONFIG->setValue("Host", "localhost");
	
	DCONFIG->beginGroup("Database");
	DCONFIG->setValue("Name", "doms");
	DCONFIG->setValue("Host", "localhost");
	DCONFIG->setValue("Login", "domsadmin");
	DCONFIG->setValue("Password", "domsadmin");
	
	DCONFIG->sync();
	exit(0);
}

