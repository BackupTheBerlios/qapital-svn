/***************************************************************************
 *   Copyright (C) 2004 by David Cuadrado - Juliana Davila                 *
 *   krawek@linuxmail.org - gobolindo@gmail.com                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "gadconsola.h"

//using namespace qapital;

/**
Este constructor es el encargado de crear una consola en la interfaz grafica del usuario
 */
qpagui::GADConsola::GADConsola(QWidget *parent, const char *name) : QDockWindow(QDockWindow::InDock,parent,name)
{
	INIQPC;
	tab = new QTabWidget(this);
	this->setWidget(tab);
	this->setMovingEnabled(false);
	setResizeEnabled(true);
	setCloseMode(QDockWindow::Always);

	vbox = new QVGroupBox(tab);
	vbox->show();
	
	contenido = new QTextView(vbox);
	tab->addTab(vbox, "GADConsola");
	show();
}

/**
 * Destructor de GADConsola
 */
qpagui::GADConsola::~GADConsola()
{
	FINQPC;
}

/**
 * Funcion encargado de generar una serie de logs (info, warning o error) en la consola de la interfaz referentes a las diferentes situaciones que se presenten en el proceso.
 * @param texto: Texto que se muestra en la consola referente a los logs.
 */
void qpagui::GADConsola::addText(QString texto)
{
	contenido->append(QString("-> ") + texto);
}
