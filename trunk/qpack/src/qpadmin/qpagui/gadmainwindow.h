/***************************************************************************
 *   Copyright (C) 2004 by David Cuadrado - Juliana Davila                 *
 *   krawek@gmail.com gobolindo@gmail.com                                  *
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

#ifndef GADMAINWINDOW_H
#define GADMAINWINDOW_H

#include <qmainwindow.h>
#include <qworkspace.h>
#include <qimage.h>
#include <qpixmap.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qlabel.h>
#include <qstatusbar.h>
#include <qmessagebox.h>
#include <qprinter.h>
#include <qapplication.h>
#include <qpushbutton.h>
#include <qaccel.h>
#include <qtextstream.h>
#include <qtextedit.h>
#include <qpainter.h>
#include <qpaintdevicemetrics.h>
#include <qwhatsthis.h>
#include <qvbox.h>
#include <qsimplerichtext.h>
#include <iostream>
#include <qtoolbar.h>
#include <qaction.h>
#include <qlistview.h>

#include "guimdimainwindow.h"
#include "gadconsola.h"
#include "gadpaneldeherramientas.h"


/**
 * @short Esta es la ventana principal del MDI
 * @author CetiSoft
*/
class GADMainWindow : public GUIMdiMainWindow
{
	Q_OBJECT

	private:
		QWorkspace* ws;
		QVBox *vbox;
    		QPrinter *printer;
    		QPopupMenu *ventanas;
		GADConsola *consola;
		GADPanelDeHerramientas *herramientas;
		
	public:
    		GADMainWindow();
    		~GADMainWindow();
		
	public slots:
		void aboutQt();
		void about();
		void ordenarVentanas();
		void ventanaActivada(int id);
		void slotPrincipal();
};

#endif
