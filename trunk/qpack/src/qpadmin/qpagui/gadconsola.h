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
#ifndef GADCONSOLA_H
#define GADCONSOLA_H

#include <qdockwindow.h>
#include <qtextview.h>
#include <qvgroupbox.h>
#include <qlabel.h>
#include <qtabwidget.h>
#include "sbqpack.h"

/**
 * @short Esta clase es utilizada para colocar una consola de errores y logs, visible para el usuario
 * @author CetiSoft
*/

class GADConsola : public QDockWindow
{
	Q_OBJECT
	private:
		QTabWidget *tab;
		QVGroupBox *vbox;
		QTextView *contenido;
		
	public:
    		GADConsola(QWidget *parent = 0, const char *name = 0);
		~GADConsola();
		void addText(QString texto);
};

#endif
