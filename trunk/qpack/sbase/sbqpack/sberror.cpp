/* Clase: SBError
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 28/08/2004
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


#include "sberror.h"


/**
Constructor
Esta funcion se encarga de construir el objeto 
@param busca: indicar el codigo del error que deseemos mostrar
@param prioridadE: indicar la prioridad del error
@param nivelE : indicar el nivel del error
@param logE:  indicar a donde va el mensaje
*/
/**
  @param prioridadE: indicar la prioridad del error
   
  PRIORIDAD   /   Identificador / Descripcion 
    0              QP_INFO          mensajes de informacion 
    1              QP_WARNING       mensajes de advertencia pueden poner en peligro la aplicacion o la seguridad
    2              QP_ERROR         mensajes de error, graves o errores que se pueden solucinar facilmente
*/

/**
 @param nivelE : indicar el nivel del error
   
  NIVEL   /   Identificador / Descripcion 
    
   0          LOGFILE        Solo Logguea en archivo plano 
   1 	      VERBOSEFILE    Genera salida en pantalla y logguea en archivo 
   2          VERBOSE        Solo genera salida en pantalla.
*/

/**
 @param logE:  indicar a donde va el mensaje
   
  LOGE   /   Identificador / Descripcion 
    
   0          CLIENTE       Loguea en el lado del cliente
   1 	      SERVIDOR      Loguea en el lado del servidor
   2          NONE          No loguea en ninguna parte
*/

/**
  TODO :  a medida que qapital se desarrolle, agregra nuevos elementos, con sus respectivas traducciones.
*/

SBError::SBError()
{
   agregarError( "0001" , "No se pudo convertir el tipo de dato" );
   agregarError( "0002" , "No se pudo crear el objeto" );
   agregarError( "0003" , "No se pudo eliminar el objeto" );
   agregarError( "0004" , "Falta de memoria" );
   agregarError( "0005" , "Divicion por 0 " );
   agregarError( "0006" , "Encriptacion Fallida" );
   agregarError( "0007" , "No se pudo crear la gui" );
   agregarError( "0008" , "No se pudo crear el widget" );
   agregarError( "0009" , "No se pudo cambiar el formato" );
   agregarError( "0010" , "No se pudo escribir en el archivo" );
   agregarError( "0011" , "No se pudo abrir el archivo" );
   agregarError( "0012" , "No se pudo crear el directorio" );
   agregarError( "0013" , "No se pudo borrar el archivo" );
   agregarError( "0014" , "No se pudo borrar el directorio" );
   agregarError( "0015" , "Archivo corrupto" );
   agregarError( "0016" , "El proceso no pudo ser completado" );
   agregarError( "0017" , "El Archivo de imagen no pudo ser cargada" );
   agregarError( "0018" , "La Conexion se encuentra caida" );
   agregarError( "0019" , "Numero de paquetes recividos es incorrecto" );
   agregarError( "0020" , "No pudo ser leido el archivo XML" );
   agregarError( "0021" , "No se pudo escribir el archivo XML" );
   agregarError( "0022" , "Conexion Rota" );
   agregarError( "0023" , "El Servidor lo ha desconectado" );
   agregarError( "0024" , "Ip Invalida" );
   agregarError( "0025" , "El cliente hizo una peticion invalida" );
   agregarError( "0026" , "El cliente cancelo la conexion" );
   agregarError( "0027" , "Driver no encontrado" );
   agregarError( "0028" , "El estado de la conexion es demasiado lento" );
   agregarError( "0029" , "Permisos insuficientes para completar la operacion" );
   agregarError( "0030" , "Usuario con perfil invalido" );
   agregarError( "0031" , "La conexion con la base de datos no se pudo realizar" );
   agregarError( "0032" , "Acceso denegado" );
   agregarError( "0033" , "No se pudo iniciar el fichero de configuraciones" );
   agregarError( "0034" , "Usuario o clave incorrecta" );
   agregarError( "0035" , "Solo se puede conectar a una empresa por sesion" );
   agregarError( "0036" , "No se encuentra el fichero de ayuda" );
   agregarError( "0037" , "Debe ingresar el numero correcto de caracteres" );
   agregarError( "0038" , "Espacios en balnco no son permitidos" );
   agregarError( "0039" , "Arroba requerida, para validar el e-mail" );
   agregarError( "0040" , "Solo se aceptan letras" );
   agregarError( "0041" , "Solo se aceptan numeros" );
   agregarError( "0042" , "Solo se aceptan mayusculas" );
   agregarError( "0043" , "Solo se aceptan minusculas" );
}

/*void SBError::logError( QString busca , Q_UINT16 prioridadE, Q_UINT16 nivelE , Q_UINT16 logE )
{
   SBLogger::SBLogger( logE, SBError::obtenerError( busca ), "SBError", prioridadE, nivelE );     
}*/

/**
Destructor
*/
SBError::~SBError()
{
}

/**
Esta funcion se encarga de devolver el mensaje de error
@param id: Codigo de error
@param cosa: Mensaje de error
*/
void SBError::agregarError( QString id , QString cosa )
{
	SBError::cacheErrores.insert( id , new QString( cosa ) );
}

/**
Esta funcion se encarga de devolver el mensaje de error
@param codigo: Codigo de error
@see agregarError(QString id , QString cosa)
*/
QString SBError::obtenerError( QString codigo )//&codigo )
{     
  	SBError busq;
  	QString strTmp = ( QString ) busq.buscar( codigo );
	return QObject::tr( strTmp );
}

QString SBError::buscar( QString buscaCd )
{
   return ( ( QString )*cacheErrores.find( buscaCd  ) );
}

