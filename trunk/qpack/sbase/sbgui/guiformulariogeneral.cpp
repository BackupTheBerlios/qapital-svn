/* Clase: GUIFormularioGeneral
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 13/08/2004
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

#include "guiformulariogeneral.h"

sbgui::GUIFormularioGeneral::GUIFormularioGeneral(QWidget *parent, const char *name) : GUIFormularios(parent, name)
{
	qDebug("[Construyendo GUIFormularioGeneral]");
	encabezado << tr("Razon Social") << tr("Nit/CC") << tr("Administrador");
	//crearTabla(encabezado);
	crearFormulario(encabezado);
	//crearBotones();
	qDebug("[GUIFormularioGeneral Construido]");
}


sbgui::GUIFormularioGeneral::~GUIFormularioGeneral()
{
	qDebug("[Destruyendo GUIFormularioGeneral]");
}

void sbgui::GUIFormularioGeneral::crearFormulario(QStringList cabecera)
{
	formulario = new QFrame(this);
	gridFormulario = new QGridLayout(formulario,3,1);
	razonSocial = new QLabel( cabecera[0] , formulario);
	capturaNombre = new QLineEdit(formulario);
	gridFormulario->addWidget(razonSocial,0,0);
	gridFormulario->addWidget(capturaNombre,0,1);
	
	ident = new QLabel(cabecera[1], formulario);
	capturaIdent = new QLineEdit(formulario);
	gridFormulario->addWidget(ident,1,0);
	gridFormulario->addWidget(capturaIdent,1,1);
	
	admistrador = new QLabel(cabecera[2] , formulario);
	capturaAdministrador = new QLineEdit(formulario);
	gridFormulario->addWidget(admistrador,2,0);
	gridFormulario->addWidget(capturaAdministrador,2,1);
	
}

void sbgui::GUIFormularioGeneral::clickedInsertar()
{
	//falta: validar datos
	listaDeDatos.append(capturaNombre->text());
	listaDeDatos.append(capturaIdent->text());
	listaDeDatos.append(capturaAdministrador->text());
	tabla->llenarTabla(listaDeDatos);
	capturaNombre->setText("");
	capturaNombre->setText("");
	capturaIdent->setText("");
}
