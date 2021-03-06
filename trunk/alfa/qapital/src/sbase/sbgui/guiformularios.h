/* Clase: GUIFormularios
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 14/08/2004
 * Fecha de modificacion:15/08/2004
 * Relacion con objetos:
 * Descripcion: 
 *	Esta clase es la base para la construccion de formularios.
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

#ifndef GUIFORMULARIOS_H
#define GUIFORMULARIOS_H

#include <qvgroupbox.h>
#include <qpushbutton.h>
#include <qstringlist.h>
#include <qhbuttongroup.h> 
#include "guitabla.h"


/**
	Esta clase es la base para la construccion de formularios.

@author CetiSoft
*/

class GUIFormularios : public QVGroupBox
{
	Q_OBJECT
	private:
		QPushButton *insertar, *remover;
		QStringList listaDeDatos;
		QHButtonGroup *contenedorBotones;
	public:
    		GUIFormularios(QWidget *parent = 0, const char *name = 0);
		virtual ~GUIFormularios();
		void crearBotones();
		void crearTabla(QStringList);
		virtual void crearFormulario(QStringList) = 0;
		GUITabla *tabla;

	public slots:
		virtual void clickedInsertar() = 0;
		
	protected:
		QGridLayout * gridFormulario;

};

#endif
