/* Clase: SBGui
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion: 19/06/2004
 * Fecha de modificacion:
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
#include "sbgui.h"
/*
en esta clase tengo que me ter todas las cosas del sistema base


*/
SBGui::SBGui(): SBGTipo_ui(1) /// el SBGTipo si es 0 esterminal y si es 1 es Modo Grafico
{
}


SBGui::~SBGui()
{
}

const int SBGui::sbgObtenerTipo()
{
	return  SBGTipo_ui;
}

/*void SBGUI::insertarPixmap(QString clave,  const QPixmap & pixmap)
{
	QPixmapCache::insert(clave,pixmap);
}
*/


