/* Clase:	SBFormato
 * Autor:	daniel valencia
 * Version:	0.1
 * Fecha de creacion:	18/06/2004
 * Fecha de modificacion:18/06/2004
 * Relacion con objetos: se relaciona con el SBCore
 * Descripcion: la clase SBFormato hace parte del SBCore (sistema base core)
 * y sirve para pasar de un tipo de dato primitivo a otro tipo de dato primitivo
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
#ifndef SBFORMATO_H
#define SBFORMATO_H

#include <qstring.h>
/**
@author daniel valencia llehinad@linuxmail.org cetisoft staff
*/
class SBFormato
{	
	private:
		
		bool frmBool;
		int frmInt;
		double frmDouble;
		QString frmQstring ; 
		char * frmChar;
	public:
		
		SBFormato();
    		~SBFormato();
		int entero(QString tmp);// qstring a entero
		double real(QString);	//qstring a real	
		QString formatoString(char *); //char a qstring
		char * formatoChar(QString tmp); //qstring a char 
};

#endif
