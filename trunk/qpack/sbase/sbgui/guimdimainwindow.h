/* Clase: GUIMdiMainWindow
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: /08/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion: 
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

#ifndef GUIMDIMAINWINDOW_H
#define GUIMDIMAINWINDOW_H

#include <qapplication.h>
#include <qmainwindow.h>
#include <qaction.h>

#include "guimdixmlparser.h"
#include "sbqpack.h"


namespace sbgui
{
/**
 *	Esta es la clase base para crear MDI's
 *	@author CetiSoft
 */

	class GUIMdiMainWindow : public QMainWindow
	{
		Q_OBJECT
		private:
			GUIMdiXMLParser *parser;
		public:
	    		GUIMdiMainWindow();
			virtual ~GUIMdiMainWindow();
			void ponerXML(const QString &file); 
			void crearGUI();
			
		public slots:
			virtual void slotPrincipal() = 0;	
	};
}
#endif
