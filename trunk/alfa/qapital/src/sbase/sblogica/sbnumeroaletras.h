/* Clase: SbNumLetras
 * Autor: Cetisoft@linuxmail.org
 * Version: 0.0.1
 * Fecha de creacion: 13-Julio-2004
 * Fecha de modificacion: 13-Julio-2004
 * Relacion con objetos:
 * Descripcion: clase de conversion de numeros a letras
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
 
 /*
   Autor : Fabio Andres Herrera Rozo 
   E-mail: t763rm3n@linuxmail.org
 */
 
#ifndef NUMEROALETRAS_H
#define NUMEROALETRAS_H
#include "qstring.h"

class SbNumLetras 
{
    public:
              QString conversion;

              SbNumLetras();
	     ~SbNumLetras();
	      QString numeroAletrasES(char revisada[]);
	      QString numeroAletrasEspanol(int revisadaPar , int gp);
};              
#endif

