/* Clase: SBNegocio
 * Autor: CetiSoft
 * Version: 0.0.1
 * Fecha de creacion:
 * Fecha de modificacion:
 * Relacion con objetos:
 * Descripcion:
 *	Esta clase contiene todas las definiciones globales necesarias para construir para la capa de logica de negocio
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
 
#ifndef SBNEGOCIO_H
#define SBNEGOCIO_H

/**
@author CetiSoft
*/
#include <qstring.h>

class SBNegocio
{
	private: 
		QString ngcNombreEmpresa;
		QString ngcMoneda;
		QString ngcSimboloDecimal;
		QString ngcActividad;
		QString ngcTamano;
		QString ngcTipoCapital;
		QString	ngcTipoSociedad;
		QString ngcCampoContabilidad;
		
	public:
		SBNegocio();
		~SBNegocio();

};

#endif
