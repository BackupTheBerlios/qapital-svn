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
 
#include "aceptarconexion.h"

namespace qpscontrol 
{

	AceptarConexion::AceptarConexion(qpsbd::BDInstrucciones *insSQL, QString empresa, QString login)
	{
		qDebug("[Construyendo AceptarConexion]");
		if ( !insSQL)
			std::cout << "No existen las instrucciones" << std::endl;
		
		QSqlQuery query = insSQL->exec(empresa, "SEL0005", QStringList() << login );
		
// 		if ( query.exec() )
// 		{
			while ( query.next() )
			{
				// TODO: Construir los QStringList aqui para crear el paquete SbXmlACP
				std::cout << "Imprimiendo resultado de consulta" << std::endl;
				//std::cout << query.value(0).toString() << std::endl;
				//std::cout << query.value(1).toString() << std::endl;
			}
// 		}
	}
	
	
	AceptarConexion::~AceptarConexion()
	{
	}
	
	sbxml::SbXmlACP *AceptarConexion::obtenerPaquete()
	{
		return paquete;
	}
};
