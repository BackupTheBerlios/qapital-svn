/* Clase: QPCApplication
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 02/13/2004
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

#include "qpcapplication.h"
#include "guiprimerdialogo.h"

/**
* Constructor
*/
QPCApplication::QPCApplication(int argc, char *argv[]) : QApplication(argc, argv,true), qppath(qapital::CONFIGRC), configpath(qapital::CONFIGRC+QString("QPCConfig.xml"))
{
	// TODO: Si no hay configuracion, cree la instancia de PrimerDialogo
	verificarConfiguracion();
}

/**
* Destructor
*/
QPCApplication::~QPCApplication()
{
}

/**
* Esta funcion verifica si existe el archivo de configuracion, en caso contrario crea uno por defecto.
*/
void QPCApplication::verificarConfiguracion()
{
	if ( ! QFile::exists (configpath ) )
	{
		qWarning(QObject::tr("El archivo de configuracion del cliente no existe!") );

		QDir qpdir(qppath);
		if ( ! qpdir.exists() )
		{
			if ( ! qpdir.mkdir( qppath ) )
			{
				std::cerr << QObject::tr("Error creando el directorio ") << qppath << std::endl;
				QApplication::exit(-1);
			}
		}

		this->correrPrimerDialogo();
	}
}

void QPCApplication::correrPrimerDialogo()
{
	GUIPrimerDialogo primerDialogo;
	if ( primerDialogo.exec() != QDialog::Rejected )
	{
		std::cout << QObject::tr("Creando archivo por defecto...") << std::endl;
		
		QPDocumentoXML clientConfig = SbXmlConfig::crearConfigCliente(primerDialogo.obtenerHost(), primerDialogo.obtenerPuerto(), primerDialogo.interfazElegida() );
		QFile configFile(configpath);
		if ( configFile.open( IO_WriteOnly ) )
		{
			QTextStream fs( &configFile );
			fs << clientConfig.toString();
			std::cout << QObject::tr("Archivo creado!") << std::endl;
			configFile.close();
		}
		else
		{
			std::cout << QObject::tr("No se pudo crear el archivo de configuracion...") << std::endl;
		}
	}
}
