/* Clase: GUIHelp
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 10/08/2004
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

#include "guihelp.h"

sbgui::GUIHelp::GUIHelp(QWidget *parent, const char *name)
 : QMainWindow(parent, name)
{
	contenedor = new QTabWidget(this, "GUIHelp:contenedor");
	browser = new QTextBrowser(contenedor);
	QString home;
	home = QDir( "../../../html/index.html" ).absPath();
	browser->setSource( home );
	browser->mimeSourceFactory()->setFilePath(".");
	contenedor->addTab(browser,"index");
	setCentralWidget(contenedor );

	setCaption(tr("Ayuda de Qapital"));
	barraDeHerramientas = new QToolBar(this);
	QIconSet flechaAtras(QPixmap( sbqpack::GUIDATADIR + "iconos/1leftarrow.png"));
	QIconSet flechaAdelante(QPixmap(sbqpack::GUIDATADIR + "iconos/1rightarrow.png"));
	QIconSet iconoCasa(QPixmap(sbqpack::GUIDATADIR + "iconos/parlante.png"));
	
	QAction *atras = new QAction( flechaAtras, tr("atras"), Qt::Key_A, barraDeHerramientas);
	connect (atras, SIGNAL(activated() ),browser, SLOT(backward()));
	atras->addTo(barraDeHerramientas);
	
	QAction *adelante = new QAction( flechaAdelante, tr( "adelante"), Qt::Key_D, barraDeHerramientas);
	connect (adelante, SIGNAL(activated() ),browser, SLOT(forward() ));
	adelante->addTo(barraDeHerramientas);
	
	QAction *goHome = new QAction( iconoCasa, tr("Principal"), Qt::Key_H, barraDeHerramientas);
	connect (goHome, SIGNAL(activated() ),browser, SLOT(home()));
	goHome->addTo(barraDeHerramientas);
	
	contenedor->setMinimumSize( QSize(400,300)  );
	
	hide();
}


sbgui::GUIHelp::~GUIHelp()
{
}


