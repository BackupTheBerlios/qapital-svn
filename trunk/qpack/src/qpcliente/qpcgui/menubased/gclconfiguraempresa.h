/* Clase: GCLConfiguraEmpresa
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 14/08/2004
 * Fecha de modificacion:15/08/2004
 * Relacion con objetos: es un QVGroupBox que contiene un QTabWidget
 * Descripcion: Esta clase sirve para configurar la empreza
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

#ifndef GCLCONFIGURAEMPRESA_H
#define GCLCONFIGURAEMPRESA_H

#include <qvgroupbox.h>
#include <qtabwidget.h> 
#include "guiformulariogeneral.h"
#include "guidirecciones.h"
#include "guitelefonos.h"
#include "guiemail.h"


namespace qpcgui
{
	/**
	@author CetiSoft
	*/
	
	class GCLConfiguraEmpresa : public QVGroupBox
	{
		Q_OBJECT
		private:
			sbgui::GUIFormularioGeneral *configGeneral;
			sbgui::GUIEMail *configEMails;
			sbgui::GUITelefonos *configTelefonos;
			sbgui::GUIDirecciones *configDirecciones;
			QTabWidget *contenedor;
			
		public:
			GCLConfiguraEmpresa(QWidget *parent = 0, const char *name = 0);
			~GCLConfiguraEmpresa();
			void init();
	};
}
#endif
