/* Archivo: qpserver.cpp
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
 * Descripcion:
 *	Este archivo contiene el metodo principal del servidor.
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

#include "sbred.h"
#include "qpsredserver.h"
#include "qpsconfighandler.h"
#include <qxml.h>
#include <qfile.h>
#include <qdir.h>
#include <unistd.h>
#include <signal.h>
#include <qtimer.h>
#include <sys/wait.h>
#include <qtranslator.h>
#include <qtextcodec.h>

#include "sbqpserver.h"
#include "sbxml.h"
#include "bdinstrucciones.h"

using sbqpserver::QPLOGGER;

static void terminar(int);

int main(int argc, char **argv)
{
// 	switch ((int) fork() )
// 	{
// 		case 0:
// 		{
// 			if ( setsid() < 0 )
// 			{
// 				perror("setsid");
// 				exit(0);
// 			}
			
			QApplication app( argc, argv, false);
			
			// TODO: añadir QPSAplicacion, y parsear argumentos
			bool cargarBD = true;
			std::cout << argc << std::endl;
			if ( argc > 1 )
			{
				if ( QString(argv[1]).contains("--nobd", true) )
				{
					cargarBD = false;
				}
			}
        
			QTranslator traductorGeneral( 0 );
			traductorGeneral.load( QString( "qt_" ) + QTextCodec::locale(),  sbqpserver::TRANSDATADIR);
        		app.installTranslator( &traductorGeneral );
			
			QTranslator traductorServer(0);
			traductorServer.load ( QString("qpserver_") + QTextCodec::locale(), sbqpserver::TRANSDATADIR);
			app.installTranslator( &traductorServer );

			QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, QObject::tr("Iniciando servidor"));
			
			QString qppath = sbqpserver::CONFIGRC;
			QString configpath = qppath + QString("QPSConfig.xml");
			
			if ( ! QFile::exists ( configpath ) )
			{
				//qWarning( QObject::tr("El archivo de configuracion del cliente no existe!") );
				QPERROR(QObject::tr("El archivo de configuracion del cliente no existe!"));
				QDir qpdir(qppath);
				if ( ! qpdir.exists() )
				{
					if ( ! qpdir.mkdir( qppath ) )
					{
						std::cerr << QObject::tr("Error creando el directorio ") << qppath << std::endl;
					}
				}

				QPINFO(QObject::tr("Creando archivo por defecto..."));
				// FALTA: crear un interfaz grafica para esto...
				StringHash configServerArgs;
				configServerArgs.insert("PuertoAST", new QString("9117"));
				configServerArgs.insert("PuertoCST", new QString("1178"));
				configServerArgs.insert("MaxClients", new QString("10"));
				configServerArgs.insert("bdnombre", new QString("DBMidas"));
				configServerArgs.insert("bddriver", new QString("QPSQL7"));
				configServerArgs.insert("bdhost", new QString("localhost"));
				configServerArgs.insert("bdpuerto", new QString("5432"));
				configServerArgs.insert("usuario", new QString("adminsis"));
				configServerArgs.insert("password", new QString("pass"));
				
				sbxml::QPDocumentoXML serverConfig = sbxml::SbXmlConfig::crearConfigServer(configServerArgs);
				
				QFile configFile(configpath);
				if ( configFile.open( IO_WriteOnly ) )
				{
					QTextStream fs( &configFile );
					fs << serverConfig.toString();
					std::cout << QObject::tr("Archivo creado!") << std::endl;
					configFile.close();
				}
				else
				{
						//QPERROR(QObject::tr("No se pudo crear el archivo de configuracion."));
					QPLOGGER.salvarLog(SBLogger::QP_ERROR, SBLogger::SERVIDOR, QObject::tr("No se pudo crear el archivo de configuracion."));
				}		
			}

			QFile configFile( configpath ); 
			std::cout << configpath << std::endl;
						
			QXmlInputSource sourceXML(configFile);
				
			QPSConfigHandler *handler = new QPSConfigHandler;
			QXmlSimpleReader reader;
			reader.setContentHandler( handler );
				
			if ( ! reader.parse( sourceXML ) )
			{
				std::cout << QObject::tr("Error en la configuracion del server") << std::endl;
			}
					
//			BDConexiones conexiones( handler->obtenerNumeroDeBDS() );
//			conexiones.insertar( handler->nombresBDS(), handler->dbs() );

 			if ( cargarBD )
 			{
				BDInstrucciones instrucciones;
       				if ( ! instrucciones.cargarInstrucciones( handler->conexiones(), handler->nombresBDS() ) )
				{
					QPERROR(QObject::tr("Error cargando las instrucciones! "));
					delete handler;
					return -1;
				}
 			}
			configFile.close();
			
			signal (SIGINT, terminar);
			signal (SIGTERM, terminar);
			signal( SIGSEGV, terminar);

			qpsred::QPSRedServer servidorPAST( handler->past(), handler->maximoDeClientes(), qApp);
			qpsred::QPSRedServer servidorPCST( handler->pcst(), handler->maximoDeClientes(), qApp);

			QObject::connect (&app, SIGNAL( lastWindowClosed ()), qApp, SLOT(quit()));			
			return app.exec();

// 			break;
// 		}
// 		
// 			case -1:
// 		{
// 			perror("fork");
// 			exit(-1);
// 		}
// 		default:
// 		{
// 			exit(0);
// 		}
// 		return 0;
//	}
}

void terminar(int s)
{
	qDebug(QObject::tr("Terminando aplicacion..."));
	
	switch (s)
	{
		case 11:
		{
			QPLOGGER.salvarLog(SBLogger::QP_ERROR, SBLogger::SERVIDOR, QObject::tr("Aplicacion terminada anormalmente.\n"));
			exit(-1);
			break;
		}
		default:
		{
			QPLOGGER.salvarLog(SBLogger::QP_INFO, SBLogger::SERVIDOR, QObject::tr("Aplicacion terminada.\n"));
			QApplication::exit(0);
			break;
		}
	}
	exit(0);
}
