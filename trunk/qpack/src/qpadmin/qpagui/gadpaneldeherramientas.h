/* Clase: GADPanelDeHerramientas
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

#ifndef GADPANELDEHERRAMIENTAS_H
#define GADPANELDEHERRAMIENTAS_H

#include <qdockwindow.h>
#include <qtoolbox.h>
#include <qvbox.h>

// FIXME: borrar esto
#include <qlabel.h>
#include <qtabwidget.h>
#include <qtextedit.h>

/**
@author CetiSoft
*/
class GADPanelDeHerramientas : public QDockWindow
{
	Q_OBJECT
	private:
		QVBox *box;
		QToolBox *toolBox;
	public:
    		GADPanelDeHerramientas(QWidget *parent = 0, const char *name = 0);
    		~GADPanelDeHerramientas();
		void addItem(QWidget *, const QString &);
};

#endif
