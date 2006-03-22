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

#include <QApplication>
#include <QMessageBox>

#include "cmainwindow.h"
#include "capplication.h"

#include <dconfig.h>
#include <dapplicationproperties.h> // dAppProp

int main(int argc, char **argv)
{
	CApplication app(argc, argv);
	app.setApplicationName("domsclient");
	
	DCONFIG->beginGroup("General");
	
	dAppProp->setHomeDir( DCONFIG->value("Home", "/").toString() );
	
	QString home = dAppProp->homeDir();
	if ( home == "/" || home.isEmpty() )
	{
		if (! app.firstRun() )
		{
			QMessageBox::critical(0, app.applicationName(), QObject::tr("Please configure the application first!"));
			
			return 0;
		}
		else
		{
			dAppProp->setHomeDir( DCONFIG->value("Home", "/").toString() );
			dAppProp->setCacheDir( DCONFIG->value("Repository", "/").toString() );
		}
	}
	
	CMainWindow mainWindow;
	
	mainWindow.showMaximized();
	
	return app.exec();
}



