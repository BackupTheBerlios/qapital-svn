/* Clase: QPCApplication
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 13/02/2005
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Esta clase provee una interfaz para analizar los argumentos de la linea de comandos, y correr algunas rutinas al inicio.
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

#ifndef QPCAPPLICATION_H
#define QPCAPPLICATION_H

#include <qapplication.h>
#include "sbqapital.h"
#include "sbxml.h"

/**
* @short Esta clase provee una interfaz para analizar los argumentos de la linea de comandos, y correr algunas rutinas al inicio.
* @author CetiSoft
*/

class QPCApplication : public QApplication
{
	Q_OBJECT

	public:
    		QPCApplication(int argc, char *argv[] );
    		~QPCApplication();
		void verificarConfiguracion();
		void correrPrimerDialogo();
	private:
		QString qppath;
		QString configpath;
};

#endif
