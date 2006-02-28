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

#include "domserver.h"

#include <dconfig.h>
#include <ddebug.h>

#include "dapplicationproperties.h"


void write_test_config();

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);
	app.setApplicationName("domserver");

	// Uncomment if you want initial config
	//write_test_config();
	
	DCONFIG->beginGroup("General");
	
	DApplicationProperties::instance()->setHomeDir( DCONFIG->value("Home", 0).toString() );
	
	DomServer server;
	
	DCONFIG->beginGroup("Connection");
	QString host = DCONFIG->value("Host", "localhost").toString();
	int port = DCONFIG->value("Port", 0).toInt();
	
	dDebug() << "Opening server on " << host << ":" << port;
	
	QList<QHostAddress> addrs = QHostInfo::fromName(host).addresses();
	
	if ( !addrs.isEmpty() )
	{
		if(! server.listen(QHostAddress(addrs[0]), port) )
		{
			dError() << "Can't connecto to " << host<<":"<<port<< " error was: " <<  server.errorString();
			return 255;
		}
	}
	else
	{
		dError() << "Error while try to resolve " << host;
		return 255;
	}
	
	return app.exec();
}

void write_test_config()
{
	DCONFIG->beginGroup("General");
	DCONFIG->setValue("Home", "/path/to/home");
	DCONFIG->beginGroup("Connection");
	DCONFIG->setValue("Host", "localhost");
	DCONFIG->setValue("Port", 31337);
	DCONFIG->sync();
	exit(0);
}

