/* Clase: GADPanelDeHerramientas
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: /08/2004
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

#include "gadpaneldeherramientas.h"

GADPanelDeHerramientas::GADPanelDeHerramientas(QWidget *parent, const char *name) : QDockWindow(parent, name)
{
	box = new QVBox(this);
	setWidget(box);
	toolBox = new QToolBox (box);
	
	QTabWidget *tab = new QTabWidget;
	tab->addTab(new QWidget, "opcion1");
	tab->addTab(new QWidget, "opcion2");
	tab->addTab(new QWidget, "opcion2");
	toolBox->addItem(tab, "Opciones");
	
	QTextEdit *te = new QTextEdit(this);
	te->append("ESTE ES EL TEXTO1");
	toolBox->addItem(te, "Editor" );
	QTextEdit *te2 = new QTextEdit(this);
	te2->append("ESTE ES EL TEXTO2");
	toolBox->addItem(te2, "Editor2" );
}


GADPanelDeHerramientas::~GADPanelDeHerramientas()
{
}

void GADPanelDeHerramientas::addItem(QWidget *widget, const QString &texto)
{
	toolBox->addItem(widget, texto);
}
