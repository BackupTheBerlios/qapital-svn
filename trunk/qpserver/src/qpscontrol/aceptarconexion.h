/***************************************************************************
 *   Copyright (C) 2005 by CetiSoft                                        *
 *   cetis@univalle.edu.co                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef QPSLOGICAACEPTARCONEXION_H
#define QPSLOGICAACEPTARCONEXION_H

#include "sbxmlacp.h"
#include <iostream>
#include <qobject.h>
#include "bdinstrucciones.h"

namespace qpscontrol
{
	/**
	 * Esta clase pretende constrir el paquete SbXmlACP, con las transacciones y drivers y enviarlo a los clientes.
	 * @author CetiSoft
	 */
	class AceptarConexion
	{
		private:
			sbxml::SbXmlACP *paquete;
		public:
			AceptarConexion(qpsbd::BDInstrucciones *insSQL, QString empresa, QString login);
			~AceptarConexion();
			sbxml::SbXmlACP *obtenerPaquete();
	};
}

#endif
