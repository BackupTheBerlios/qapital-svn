/* Clase: SBLogger
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 12/08/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
 *	Loguea
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

#ifndef SBLOGGER_H
#define SBLOGGER_H

#include <qdir.h>
#include <qprocess.h>
#include <qtextstream.h>
#include <qdatetime.h>
#include <qvaluelist.h>
#include <qobject.h>
#include <unistd.h>
#include <iostream>

#define QPINFO(s) std::cout << "\033[1;32m * \033[0;0m" << s << std::endl;
#define QPWARN(s) std::cout << "\033[1;33m" << " * " << "\033[0;0m" << s << std::endl;
#define QPERROR(s) std::cout << "\033[1;31m" << " * " << "\033[0;0m" << s << std::endl;

class SBLogger : public QObject
{        
	private:
		int entidad;
			
		QString salvarFechaLog;
		QString salvarHoraLog;

		QString LOGSDIR;
		QString RUTA_LOG;
		
		QString FORMATEO_DEFECTO_HORA;
		QString FORMATEO_DEFECTO_FECHA;
		
		QString textoAloguear;
		QString UBICACION;
		QString PRIORIDAD;
		QString NIVEL;
		int nivel;
		int prioridad;
						
	public:
		enum Prioridad { QP_INFO = 0 , QP_WARNING,  QP_ERROR };
		enum Nivel { LOGFILE = 0 , VERBOSEFILE, VERBOSE  };
		enum Entidades { CLIENTE = 0 , ADMIN, SERVIDOR , NONE  };
		
		SBLogger(int nivel, Entidades entidad, QString ruta, QString archivo );
		~SBLogger();
		
		QString fechaLog();
		QString horaLog();
		QString obtenerNivel();
			
		void salvarLog(int nivel, QString texto);
		
	protected:
		void asignarPrioridad( int );
		void asignarNivel( int );
		void ponerEntidad(int donde);
		void guardarEnArchivo();
		void mostrarEnPantalla(QString mensaje);
		void iniciarLogger();
};

#endif
