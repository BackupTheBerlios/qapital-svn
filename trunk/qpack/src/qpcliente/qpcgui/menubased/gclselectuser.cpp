/* Clase: GCLSelectUser
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 09/08/2004
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

#include "gclselectuser.h"

//using namespace qapital;

GCLSelectUser::GCLSelectUser(QWidget *padre) : QIconView(padre)
{
	qDebug("[construyendo GCLSelectUser]");
	setItemsMovable ( false );
	setSelectionMode(QIconView::Single);
	setMinimumSize ( 80,100);
}


GCLSelectUser::~GCLSelectUser()
{
	qDebug("[Destruyendo GCLSelectUser]");
}

/**
 * Sirve para leer los usuarios que se van a mostrar (falta leer desde un XML).
 */
void GCLSelectUser::leerUsuarios()
{
	QFile *archivoXML = new QFile(XMLCLIENTDATADIR + "qpusuarios.xml"); // FIXME: Este archivo debe estar localizado en .qapital !
	QXmlInputSource *source = new QXmlInputSource( archivoXML );
	QXmlSimpleReader reader;
	GUILectorXml *handler = new GUILectorXml();
	reader.setContentHandler( handler );
	
	if ( reader.parse( source, true ) )
	{
		qDebug(tr("GCLPrincipal/GCLPrincipal: Lectura XML exitosa"));
	}
	
	QStringList nombres = handler->obtenerListaDeTexto();

	for (uint i = 0; i < nombres.count(); i+=2)
	{
		QIconViewItem *unUsuario = new QIconViewItem (this, nombres[i], QPixmap( nombres[i+1] ));
		unUsuario->setDragEnabled (false);
		unUsuario->setDropEnabled (false);
	}
}


