/* Clase: GUITitulo
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 07/08/2004
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

#include "guititulo.h"

sbgui::GUITitulo::GUITitulo(QWidget *parent, const char *name, QString pixmapTitulo, QString version)
 : QVGroupBox(parent, name)
{	
	gttLogo = new QLabel(this);
	gttLogo->setPixmap(QPixmap(pixmapTitulo, 0,QPixmap::Auto));
	gttLogo->setFrameStyle(QFrame::Panel | QFrame::Raised);
	gttLogo->setLineWidth( 2 );
	gttLogo->setAlignment ( QLabel::AlignCenter );
	
	QFont font("Times", 16);
	
	gttTitulo = new QLabel(version,this);
	gttTitulo->setFont(font);
	gttTitulo->setAlignment ( QLabel::AlignRight );
	
	setMargin(-1);
}


sbgui::GUITitulo::~GUITitulo()
{
}


void sbgui::GUITitulo::gttPonerImagen(QString pixmapTitulo)
{
	gttLogo->setPixmap(QPixmap(pixmapTitulo, 0,QPixmap::Auto));
}
