/* Archivo: qpcliente.cpp
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
 * Descripcion:
 *	Contiene el metodo principal del QPCliente
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

#include <qsplashscreen.h> 
#include <iostream>
#include <qtranslator.h>
#include <qdom.h>
#include <qxml.h>

#include "gclprincipal.h"
#include "gclmdimainwindow.h"
#include "qpcconfighandler.h"
#include "qpcapplication.h"

#include <qfile.h>
#include "sbxml.h"
#include "clnred.h"

int main( int argc, char **argv )
{
	QPCApplication app(argc, argv);

	QApplication::setStyle("plastik");
	
	sbqpcliente::QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::CLIENTE, QObject::tr("Iniciando QPCliente"));
	
	QString splash = sbqpcliente::GUIDATADIR + QString("qapital-splash-2004-08-31.png");
	
	QPixmap pixmap( splash );
    	QSplashScreen *pantalla = new QSplashScreen( pixmap );
      	pantalla->show();
	pantalla->message(QObject::tr("Iniciando aplicacion..."));

	QFile configFile( sbqpcliente::CONFIGRC +  QString("QPCConfig.xml"));

	QXmlInputSource sourceXML(configFile);
	configFile.close();
	
	QPCConfigHandler *handler = new QPCConfigHandler;
	QXmlSimpleReader reader;
    	reader.setContentHandler( handler );
		
	if ( ! reader.parse( sourceXML ) )
	{
		std::cout << QObject::tr("Error en la configuracion del cliente") << std::endl;
	}		
	
	ClnRed cliente ( handler->obtenerQPSHost(), handler->obtenerQPSPuerto() );

	pantalla->message(QObject::tr("creando interfaz..."));

	//GCLMdiMainWindow *qpCliente;
	QMainWindow *qpCliente = 0;

	switch ( int opt = handler->obtenerTipoDeInterfaz() )
	{
		case SBGui::MenuBased:
		{
			std::cout << "Iniciando MenuBased" << std::endl;
			qpCliente = new GCLPrincipal(&cliente);
		}
		break;
		case SBGui::MDIBased:
		{
			std::cout << "Iniciando MDIBased" << std::endl;
			qpCliente = new GCLMdiMainWindow();
		}
		break;
		default:
		{
			std::cout << "Tipo de interfaz desconocido " << opt << std::endl;
			qpCliente = new GCLMdiMainWindow();
		}
		break;
	}
	
	app.setMainWidget( qpCliente );
	
	
	QObject::connect( qApp, SIGNAL( lastWindowClosed() ), &cliente, SLOT( clnCerrarConexion() ) );
	
	pantalla->finish( qpCliente );

    	delete pantalla;
	
	return app.exec();
}
