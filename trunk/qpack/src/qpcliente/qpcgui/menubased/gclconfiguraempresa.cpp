/* Clase: GCLConfiguraEmpresa
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

#include "gclconfiguraempresa.h"

qpcgui::GCLConfiguraEmpresa::GCLConfiguraEmpresa(QWidget *parent, const char *name) : QVGroupBox(parent, name)
{
	qDebug("[Construyendo GCLConfiguraEmpresa]");
	
	contenedor = new  QTabWidget(this);
	init();
	
	qDebug("[GCLConfiguraEmpresa construido]");
}


qpcgui::GCLConfiguraEmpresa::~GCLConfiguraEmpresa()
{
	qDebug("[GCLConfiguraEmpresa destruido]");
}

void qpcgui::GCLConfiguraEmpresa::init()
{
	configGeneral = new sbgui::GUIFormularioGeneral(contenedor);	
	configDirecciones = new sbgui::GUIDirecciones(contenedor);
	configTelefonos = new sbgui::GUITelefonos(contenedor);
	configEMails = new sbgui::GUIEMail(contenedor);
	
	contenedor->insertTab(configGeneral , tr("General"));
	contenedor->insertTab(configDirecciones , tr("Direcciones"));
	contenedor->insertTab(configTelefonos , tr("Telefono"));
	contenedor->insertTab(configEMails , tr("E-Mail"));
}
