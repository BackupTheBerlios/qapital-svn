/* Clase: SBRed
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: En esta clase estaran las variables y definiciones globales necesarias para todo el sistema de red
 *
*/

/**************************************************************************************
 *   Copyright (C) 2004 by CetiSoft                                        			*
 *   cetisoft@linuxmail.org                                                				*
 *                                                                         				*
 *   This program is free software; you can redistribute it and/or modify  		*
 *   it under the terms of the GNU General Public License as published by  		*
 *   the Free Software Foundation; either version 2 of the License, or     		*
 *   (at your option) any later version.                                   			*
 *                                                                         				*
 *   This program is distributed in the hope that it will be useful,       			*
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        	*
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        	*
 *   GNU General Public License for more details.                          			*
 *                                                                         				*
 *   You should have received a copy of the GNU General Public License     	*
 *   along with this program; if not, write to the                         			*
 *   Free Software Foundation, Inc.,                                       			*
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             		*
 ************************************************************************************/
 
 #ifndef SBRED_H
#define SBRED_H

#include <qserversocket.h>
#include <qsocket.h>
#include <qtextstream.h>
#include <iostream>
#include <qapplication.h>
#include <qobject.h>
#include <qstring.h>

namespace sbred
{
	// Definiciones de constantes globales.
	
	// Puerto por defecto entre Programa Administrador (PA) y Servidor de Transacciones (ST).
	const int redPuertoPAST = 1178;
	
	// Puerto por defecto entre Programa Cliente (PC)  y Servidor de Transacciones (ST).
	const int redPuertoPCST = 9117;
	
	// Numero Maximo de clientes
	
	const int MAXIMO_DE_CLIENTES = 10;
	
	/**
	 * Clase guia para la red
	 * @author CetiSoft
	 * TODO: Encripcion
	 * 	Modulo XML +
	 * 	Archivo de consultas XML -
	 * 	Interpretar y armar paquetes XML +-
	 * 	Generar cache -
	*/
	class SBRed 
	{	
		public:
			SBRed();
			~SBRed();
			QString redIPCliente;
			QString redIPServidor;
			QString redCodigo;
			QString redUltimoCodigo;
			
	};
}
#endif
