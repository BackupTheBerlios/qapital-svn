/* Clase: GUIEMail
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 14/08/2004
 * Fecha de modificacion: 15/08/2004
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

#include "guiemail.h"

GUIEMail::GUIEMail(QWidget *parent, const char *name)
 : GUIFormularios (parent, name)
{
	qDebug("[Construyendo GUIEMail]");
	QStringList encabezado;
	encabezado << tr("Descripcion") << tr("e-mail");
	crearTabla(encabezado);
	crearFormulario(encabezado);
	crearBotones();
	qDebug("[GUIEMail Construido]");
}


GUIEMail::~GUIEMail()
{
	qDebug("[Destruyendo GUIFormularioGeneral]");
}

void GUIEMail::crearFormulario(QStringList cabecera)
{
	formulario = new QFrame(this);
	gridFormulario = new QGridLayout(formulario,3,1);
	
	descripcion = new QLabel( cabecera[0], formulario);
	capturaDescripcion = new QLineEdit(formulario);
	gridFormulario->addWidget(descripcion,0,0);
	gridFormulario->addWidget(capturaDescripcion,0,1);
	
	eMail = new QLabel(cabecera[1], formulario);
	capturaEMail = new QLineEdit(formulario);
	gridFormulario->addWidget(eMail,1,0);
	gridFormulario->addWidget(capturaEMail,1,1);
}

void GUIEMail::clickedInsertar()
{
	//falta: validar datos
	listaDeDatos.append( capturaDescripcion->text() );
	listaDeDatos.append( capturaEMail->text() );
	tabla->llenarTabla( listaDeDatos );
	capturaDescripcion->setText("");
	capturaEMail->setText("");
}



