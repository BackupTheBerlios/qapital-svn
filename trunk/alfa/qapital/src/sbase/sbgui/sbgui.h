/* Clase: SBGui
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion:
 *	Esta archivo contiene todo el sistema base de la GUI.
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
 
#ifndef SBGUI_H
#define SBGUI_H

#include <qstring.h>
#include <qpixmapcache.h> 
#include <qaction.h>
#include "guibotonicono.h"
#include "guibarraiconos.h"
#include "guimenus.h"
#include "guilectorxml.h"
#include "guititulo.h"
#include "guihelp.h"

/**
@author cetiSoft
*/

class SBGui
{
	private:
		const int SBGTipo_ui;
	public:
		SBGui();
		~SBGui();
		enum TipoDeIntefaz { MenuBased, MDIBased };
		const int sbgObtenerTipo();
		void insertarPixmap(QString clave,  const QPixmap & pixmap);
};

#endif
