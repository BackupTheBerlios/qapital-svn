/* Clase: SbXmlConfig
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 12/08/2004
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

#include "sbxmlconfig.h"

using sbxml::QPDocumentoXML;

/**
Constructor
*/
sbxml::SbXmlConfig::SbXmlConfig()
{
}

/**
Destructor
*/
sbxml::SbXmlConfig::~SbXmlConfig()
{
}

/**
Funcion encargada de construir el archivo de configuracion del cliente.
@param host: Host del servidor de transacciones.
@param puerto: Puerto del servidor de transacciones.
*/
QPDocumentoXML sbxml::SbXmlConfig::crearConfigCliente(QString host, QString puerto, int tipoDeInterfaz)
{
	QPDocumentoXML conf;
	QDomElement raiz = conf.createElement( "QPCConfig" );
	conf.appendChild( raiz );
	
	QDomElement qpgui = conf.createElement("qpcgui");
	QDomText qpguiTxt = conf.createTextNode(QString::number(tipoDeInterfaz));
	qpgui.appendChild(qpguiTxt);
	raiz.appendChild(qpgui);
	
	QDomElement qpshost = conf.createElement("qpshost");
	QDomText hostTxt = conf.createTextNode(host);
	qpshost.appendChild(hostTxt);
	raiz.appendChild(qpshost);
	
	QDomElement qpspuerto = conf.createElement("qpspuerto");
	QDomText puertoTxt = conf.createTextNode(puerto);
	qpspuerto.appendChild(puertoTxt);
	raiz.appendChild(qpspuerto);
	
	return conf;
}

/**
crearConfigServer
@param past: Puerto Programa Administrador - Servidor de Transacciones.
@param pcst: Puerto Programa Cliente - Servidor de Transacciones.
@param maxClients: Numero maximo de clientes.
@param bdNombre: Nombre de la base de datos.
@param bdDriver: Nombre del driver.
@param bdHost: Nombre del host.
@param bdPuerto: Nombre del puerto.
@param usuario: Nombre de usuario.
@param password: Password de usuario.
*/
QPDocumentoXML sbxml::SbXmlConfig::crearConfigServer(StringHash argumentos)
{
	QPDocumentoXML conf;
	QDomElement raiz = conf.createElement( "QPSConfig" );
	conf.appendChild( raiz );
	
	QDomElement puertoAST = conf.createElement("PuertoAST");
	QDomText pastTxt = conf.createTextNode( *argumentos.find("PuertoAST") );
	puertoAST.appendChild(pastTxt);
	raiz.appendChild(puertoAST);
	
	QDomElement puertoCST = conf.createElement("PuertoCST");
	QDomText pcstTxt = conf.createTextNode(*argumentos.find("PuertoCST") );
	puertoCST.appendChild(pcstTxt);
	raiz.appendChild(puertoCST);

	QDomElement clientes = conf.createElement("MaxClients");
	QDomText mcTxt = conf.createTextNode(*argumentos.find("MaxClients"));
	clientes.appendChild(mcTxt);
	raiz.appendChild(clientes);
	
	QDomElement conexion = conf.createElement("QPConexion");
	raiz.appendChild(conexion);
	
	QDomElement bd = conf.createElement("QPBD");
	conexion.appendChild(bd);
	
	QDomElement bdname = conf.createElement("bdnombre");
	QDomText bdnameTxt = conf.createTextNode(*argumentos.find("bdnombre"));
	bdname.appendChild(bdnameTxt);
	bd.appendChild(bdname);
			
	QDomElement bddriver = conf.createElement("bddriver");
	QDomText bddriverTxt = conf.createTextNode(*argumentos.find("bddriver"));
	bddriver.appendChild(bddriverTxt);
	bd.appendChild(bddriver);

	QDomElement bdhost = conf.createElement("bdhost");
	QDomText bdhostTxt = conf.createTextNode(*argumentos.find("bdhost"));
	bdhost.appendChild(bdhostTxt);
	bd.appendChild(bdhost);
	
	QDomElement bdpuerto = conf.createElement("bdpuerto");
	QDomText bdpuertoTxt = conf.createTextNode(*argumentos.find("bdpuerto"));
	bdpuerto.appendChild(bdpuertoTxt);
	bd.appendChild(bdpuerto);	
		
	QDomElement user = conf.createElement("usuario");
	QDomText usuarioTxt = conf.createTextNode(*argumentos.find("usuario"));
	user.appendChild(usuarioTxt);
	bd.appendChild(user);
	
	QDomElement pass = conf.createElement("password");
	QDomText passTxt = conf.createTextNode(*argumentos.find("password"));
	pass.appendChild(passTxt);
	bd.appendChild(pass);
		
	return conf;
}

