/* Clase: SBLogger
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 25/08/2004
 * Fecha de modificacion:
 * Descripcion: Clase encargada de gestionar las salidas y el formateo de el sistema de logger
 *             
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
 
/**
  @TODO : Generar un lector de logs, el cual identifique cuales son de X tipo , dependiendo de el nivel 
         con el cual fueron loggueados
	 
	 - Genear un fichero de log backup , el cual despues de xx, numero de dias o ( X Kb ) genere un .tar.gz u
	   otro 
	   archivo comprimido el cual se ira almacenando en /var/log/qapital/backup-[ano]-[mes]-[dia].tar.gz
	   para asi aligerar la gestion de lecto-escritura sobre los ficheros.
*/

/********************************************************************************
 *   Copyright (C) 2004 by CetiSoft                                             *
 *   cetisoft@linuxmail.org                                                     *
 *                                                                              *
 *   This program is free software; you can redistribute it and/or modify       *
 *   it under the terms of the GNU General Public License as published by       *
 *   the Free Software Foundation; either version 2 of the License, or          *
 *   (at your option) any later version.                                        *
 *                                                                              *
 *   This program is distributed in the hope that it will be useful,            *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 *   GNU General Public License for more details.                               *
 *                                                                              *
 *   You should have received a copy of the GNU General Public License          *
 *   along with this program; if not, write to the                              *
 *   Free Software Foundation, Inc.,                                            *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                  *
 *******************************************************************************/

/**
@author CetiSoft
*/


/**
    este metodo es opcional, se puede hacer manualmente o ejecutando el script de instalacion , 
    pero este puede ser usado a la hora de generar un instalador para la apliacion 
    asi que hay queda opcional 
*/

/**
 Prioridades del Sistema de loggs:
   
  PRIORIDAD   /   Identificador / Descripcion 
    0              QP_INFO          mensajes de informacion 
    1              QP_WARNING       mensajes de advertencia pueden poner en peligro la aplicacion o la seguridad
    2              QP_ERROR         mensajes de error, graves o errores que se pueden solucinar facilmente
*/

/**
 Niveles de loggeo:
   
  NIVEL   /   Identificador / Descripcion 
    
   0          LOGFILE        Solo Logguea en archivo plano 
   1 	      VERBOSEFILE    Genera salida en pantalla y logguea en archivo
   2          VERBOSE        Solo genera salida en pantalla.
*/

/** 
 Metodo constructor 
*/

#include "sblogger.h"

SBLogger::SBLogger(int nivel, Entidades entidad, QString ruta, QString archivo) : QObject(),
LOGSDIR(ruta),
RUTA_LOG(ruta+QDir::separator()+archivo),
FORMATEO_DEFECTO_HORA  ( "hh:mm:ss-AP" ),
FORMATEO_DEFECTO_FECHA ( "dd:MMMM:yyyy"),
nivel(nivel)
{
	//qDebug("[Construyendo SBLogger]");
	iniciarLogger();
	asignarNivel(nivel);
	this->ponerEntidad(entidad);
}

/**
  Destructor 
*/
SBLogger::~SBLogger()
{
   	//qDebug("[Destruyendo logger]");
}

void SBLogger::iniciarLogger()
{
	QDir logs(LOGSDIR);
	if (! logs.exists())
	{
		if ( ! logs.mkdir( LOGSDIR ) )
		{
			std::cerr << QObject::tr("Error creando directorio para logs ") << LOGSDIR << std::endl;
		}
	}
}

void SBLogger::ponerEntidad(int donde)
{
	entidad = donde;
}

QString SBLogger:: fechaLog()
{
    QDate fechaTmp = QDate::currentDate();
    salvarFechaLog = fechaTmp.toString(FORMATEO_DEFECTO_FECHA);
    return salvarFechaLog;
}


QString SBLogger:: horaLog()
{
     QDateTime horaTmp = QDateTime::currentDateTime();
     salvarHoraLog = horaTmp.toString(FORMATEO_DEFECTO_HORA);
     return salvarHoraLog;
}


/**
@param ponerNivel:  setea una prioridad predeterminada
*/

void  SBLogger:: asignarPrioridad( int ponerPrioridad )
{
	prioridad = ponerPrioridad;
	switch( ponerPrioridad )
    	{
     		case 0:
		{ 
			PRIORIDAD = "QP_INFO";  
			break;
		}
		case 1: 
		{ 
			PRIORIDAD = "QP_WARNING"; 
			break;
		}
		case 2: 
		{ 
			PRIORIDAD = "QP_ERROR";
			break;
		}
		default: 
		{ 
			PRIORIDAD = "QP_DEFAULT";  
		}
    	}
}

/**
@param ponerNivel:  setea un nivel predeterminado
*/

void  SBLogger::asignarNivel( int ponerNivel )
{
	switch ( ponerNivel)
	{
	 	case 0 : { NIVEL = "LOGFILE";}
		case 1 : { NIVEL = "VERBOSEFILE";}
		case 2 : { NIVEL = "VERBOSE";}
	}
}

QString SBLogger::obtenerNivel()
{
   return NIVEL;
}

void SBLogger::salvarLog(int prioridad, QString texto)
{
	iniciarLogger();
	asignarPrioridad(prioridad);
// 	ponerEntidad(entidad);
	
	textoAloguear =  QString( PRIORIDAD+"::"+fechaLog()+"::"+horaLog()+"::"+texto );
	switch ( nivel )
	{
	  	case 0:
		{
			guardarEnArchivo();
			break;
		}
		case 1:
		{
			guardarEnArchivo();
			mostrarEnPantalla(texto);			
			break;
		}
		case 2:
		{
			mostrarEnPantalla(texto);
			break;
	  	}	
		default: 
	  	{
			mostrarEnPantalla(texto);
			break;
		}
	}	
}

void SBLogger::guardarEnArchivo()
{
	QFile *fc;
	
	fc = new QFile(RUTA_LOG);
	
	if(fc->open( IO_WriteOnly | IO_Append ))
     	{
		QTextStream tc(fc);
		tc<< textoAloguear << endl;
		fc->close();
		delete fc;
	}		
}

void SBLogger::mostrarEnPantalla(QString mensaje)
{
	switch(prioridad)
	{		
		case 0: 
		{ 
			QPINFO(mensaje);
			break;
		}
     		case 1: 
		{ 
			QPWARN(mensaje); 
			break;
		}
     		case 2: 
		{ 
			QPERROR(mensaje); 
			break;
		}
     		default:
		{ 
			std::cout << "SBLogger/mostrarEnPantalla: Nivel incorrecto" << std::endl; 
		}
	}
}
