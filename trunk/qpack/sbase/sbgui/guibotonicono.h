/* Clase: GUIBotonIcono
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 15/7/2004
 * Fecha de modificacion: 
 * Relacion con objetos: 
 * Descripcion: Representa los botones de una barra de herramientas.
 *
*/

/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
#ifndef GUIBOTONICONO_H
#define GUIBOTONICONO_H

#include <qtoolbutton.h>
#include <qaction.h>

namespace sbgui
{
/**
	@author CetiSoft
 */

	class GUIBotonIcono : public QAction
	{
		Q_OBJECT
		private:
			int id;
		
		public:
			GUIBotonIcono(int id  = 0,QWidget *parent = 0, const char *name = 0);
			~GUIBotonIcono();
			int gbiId();
	
		signals:
			int gbiBotonClikeado(int);
	
		public slots:
			void gbiClickeado();
	
	};
}
#endif
