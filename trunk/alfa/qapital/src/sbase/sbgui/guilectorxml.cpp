/* Clase: GUILectorXml
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 18/6/2004
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

#include "guilectorxml.h"

GUILectorXml::GUILectorXml() : QXmlDefaultHandler(), qName(""), leer(false), numeroDeBotones(0), numeroDeMenus(0), filas(0), columnas(0), mnid(0)
{
}

// Esta funcion lee los elementos de apertura: <apertura>
bool GUILectorXml::startElement (const QString& ns, const QString& localname, const QString& qname, const QXmlAttributes& atts)
{
	qName = qname;
	
	if (qname == "GMNS")
	{
		leer = false;
		if (raiz.isEmpty() )
			raiz = qname;
	}
	else if (qname == "QPUSERS")
	{
		leer = false;
		if (raiz.isEmpty() )
			raiz = qname;
	}
		
	if (raiz == "GMNS")
	{
		if (qname == "Menu")
		{
			leer = false;
			numeroDeMenus++;
			mnid = (int) atoi( atts.value("mnid"));
			filas = (int) atoi( atts.value("filas") );
			columnas = (int) atoi( atts.value("columnas") );
			
			listaDeFilas.append(filas);
			listaDeColumnas.append(columnas);
	
		} else
		if (qname == "Boton" )
		{
			leer = true;
			numeroDeBotones++;
		} else
			leer = true;
	}
	else if (raiz == "QPUSERS")
	{
		if (qname == "user")
		{
			leer = false;
			numeroDeMenus++;
		}
		else
			leer = true;
	}

	return true;
}

// Esta funcion lee los elementos de cierre: </cierre>
bool GUILectorXml::endElement( const QString& ns, const QString& localname, const QString& qname)
{
/*	if (qname == "Menu" && mnid != numeroDeMenus)
	{
		std::cout << "mnid != numeroDeMenus" << std::endl;
		if (numeroDeBotones == (filas * columnas))
			return false;
	}
*/
	qName = "";
	leer = false;
	return true;
}

bool GUILectorXml::characters ( const QString & ch )
{
	if (leer)
	{
		if (raiz == "GMNS" )
		{
			if (qName == "bid")
			{
				listaDeBid.append(ch);
			}
			else if (qName == "texto")
			{
				listaDeTexto.append(ch);
			}
			else if (qName == "funcion")
			{
				listaDeFunciones.append(ch);
			}
		}
		else if ( raiz == "QPUSERS")
		{
			if (qName == "login")
			{
				listaDeTexto.append(ch);
			}
			else if (qName == "face")
			{
				listaDeTexto.append(ch);
			}
		}
	}
	return true;
}

// Esta funcion no es necesaria.
bool GUILectorXml::parseContinue ()
{
	numeroDeBotones = 0;
	numeroDeMenus = 0;
	filas = 0;
	columnas = 0;
	listaDeTexto.clear();
	listaDeBid.clear();
	listaDeFunciones.clear();
	return true;
}

QStringList GUILectorXml::obtenerListaDeTexto() const 
{
	return listaDeTexto;
}

QStringList GUILectorXml::obtenerListaDeTexto(int mnid)
{
	QStringList listaTemporal;
	int inicio = 0, final = 0;
	
	for (int i = 0; i <= mnid; i++)
	{
		inicio += obtenerNumeroDeBotones( i - 1);
		final += obtenerNumeroDeBotones( i );
	}
	for (int i = inicio; i < final; i++)
	{
		listaTemporal.append( listaDeTexto[i] );
	}
	return listaTemporal;
}

int GUILectorXml::obtenerNumeroDeBotones(int mnid) const
{
	//listaDeFilas listaDeColumnas
	if (mnid < 0)
		return 0;
	
	return listaDeFilas[mnid] * listaDeColumnas[mnid];
}

int GUILectorXml::obtenerNumeroDeMenus() const
{
	return numeroDeMenus;
}

int GUILectorXml::obtenerFilas(int mnid) const
{
	return listaDeFilas[mnid];
}

int GUILectorXml::obtenerColumnas(int mnid) const
{
	return listaDeColumnas[mnid];
}

QStringList GUILectorXml::obtenerListaDeFunciones(int mnid)
{
	QStringList listaTemporal;
	int inicio = 0, final = 0;
	
	for (int i = 0; i <= mnid; i++)
	{
		inicio += obtenerNumeroDeBotones( i - 1);
		final += obtenerNumeroDeBotones( i );
	}
	for (int i = inicio; i < final; i++)
	{
		listaTemporal.append( listaDeTexto[i] );
	}
	return listaTemporal;
}
