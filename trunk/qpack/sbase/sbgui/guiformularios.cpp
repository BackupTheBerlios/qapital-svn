/* Clase: GUIFormularios
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

#include "guiformularios.h"

sbgui::GUIFormularios::GUIFormularios(QWidget *parent, const char *name)
 : QVGroupBox(parent, name)
{
}


sbgui::GUIFormularios::~GUIFormularios()
{
}

void sbgui::GUIFormularios::crearTabla(QStringList cabecera)
{
	tabla = new GUITabla(20, cabecera, this);
}

// Funcion: crearBotones
// Descripcion: Crea el panel de botones.
void sbgui::GUIFormularios::crearBotones()
{ 
	contenedorBotones = new QHButtonGroup(this);
	insertar = new QPushButton("insertar", contenedorBotones);
	connect( insertar, SIGNAL( clicked() ), this, SLOT( clickedInsertar()) );
	
	remover = new QPushButton("remover", contenedorBotones);
	connect( remover, SIGNAL( clicked() ), tabla, SLOT(removerFilaSeleccionada()));
}



