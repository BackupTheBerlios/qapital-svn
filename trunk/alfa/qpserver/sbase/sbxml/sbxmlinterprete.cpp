/* Clase: SbXmlInterprete
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 10/07/2004
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

#include "sbxmlinterprete.h"

/**
Constructor
@param strDoc: String que representa un documento XML.
@see SbXmlInterprete(QIODevice *dispositivo)
*/
SbXmlInterprete::SbXmlInterprete(QString strDoc )
{
	errorMsg = new QString;
	lineaError = new int;
	
	if( !xmlDocumento.setContent(strDoc, false, errorMsg, lineaError) )
	{
		// hubo un error!
		qDebug(QObject::tr("sbxmlinterprete.cpp: %1: %2").arg(*lineaError).arg(*errorMsg));
	}
}

/**
Constructor sobrecargado, su funcion es construir el objecto a partir de un dispositivo de entrada/salida, ej: un archivo.
@param dispositivo: Dispositivo de entrada/salida de donde se quiere leer el XML.
@see SbXmlInterprete(QString strDoc )
*/ 
SbXmlInterprete::SbXmlInterprete(QIODevice *dispositivo)
{
	if( !xmlDocumento.setContent(dispositivo, errorMsg, lineaError) )
	{
		// hubo un error!
		qDebug(QObject::tr("sbxmlinterprete: %1: %2").arg(*lineaError).arg(*errorMsg));
	}	
}

/**
Destructor
*/
SbXmlInterprete::~SbXmlInterprete()
{
	delete errorMsg;
	delete lineaError;
}

/** 
Esta funcion pone strDoc en xmlDocumento
@param strDoc: documento que se quiere meter en xmlDocumento.
*/
void SbXmlInterprete::ponerDocumento(QString strDoc)
{
	if( !xmlDocumento.setContent(strDoc, errorMsg, lineaError) )
	{
		// hubo un error!
		qDebug(QObject::tr("sbxmlinterprete: %1: %2").arg(*lineaError).arg(*errorMsg));
	}
}

/** 
Esta funcion se encarga de retornar el nombre de la raiz
*/
QString SbXmlInterprete::xmlRaiz()
{
	if (xmlDocumento.isDocument())
	{
		// Elemento raiz
		xmlElemento = xmlDocumento.documentElement();
		QDomNode nodo = xmlElemento.firstChild();
		xmlTagRaiz = xmlElemento.tagName();
		
//		qDebug(QObject::tr("Etiqueta: %1").arg(xmlTagRaiz));
		return xmlTagRaiz;
	}
	return "";
}


/*
Esta funcion busca en el xmlDocumento hasta que encuentra el tag y retorna el valor del string contenido por el
@param tag: Es la etiqueta que contiene el texto buscado.
*/
QString SbXmlInterprete::xmlObtenerTexto(QString tag)
{
 	xmlElemento = xmlDocumento.documentElement(); // retorna la raiz del documento
	QDomNode nodo = xmlElemento.firstChild(); // se obtiene el primer Hijo

//	std::cout << "tagName: " << xmlElemento.tagName() << std::endl;
	
	while( ! nodo.isNull())
	{
		QDomElement elemento = nodo.toElement();
		QDomNode hijo = elemento.firstChild();

		while (! hijo.isNull())
		{
			QDomElement elemento2 = hijo.toElement();
			if ( !elemento2.isNull() )
			{
				QString tmpTagName = elemento2.tagName();
//				std::cout << tmpTagName;
				QDomText textChild = hijo.firstChild().toText();
				
				QString tmpTextData = textChild.nodeValue();
//				std::cout << ": " << tmpTextData << std::endl;
				if (elemento2.tagName() == tag)
				{
					return tmpTextData;
				}
			}
			hijo = hijo.nextSibling();
		}
		nodo = nodo.nextSibling();
	}
	return "";
}

