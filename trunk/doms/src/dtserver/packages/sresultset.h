/***************************************************************************
 *   Copyright (C) 2005 by David Cuadrado                                  *
 *   krawek@gmail.com                                           	   *
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

#ifndef SRESULTSET_H
#define SRESULTSET_H

#include <qdom.h>
#include <qstring.h>
#include <qstringlist.h>

#include <QVariant>

/**
Esta clase es creada cuando se hace una consulta a la base de datos, el formato de la misma es el siguiente:

<results>
 <record>
  <columna1>valor</columna1>
  <columna2>valor</columna2>
 </record>
 <record>
  <columna11>valor</columna11>
  <columna12>valor</columna12>
  <columna13>valor</columna13>
 </record>
</results>

En caso de error retornara:

<error>
 <last>last query</last>
 <errormsg>error message</errormsg>
</error>


@author David Cuadrado \<krawek@gmail.com\>
*/

class SResultSet : public QDomDocument
{
	public:
    		/**
    		 * Constructor
    		 * @return 
    		 */
    		SResultSet();
    		/**
    		 * Destructor
    		 * @return 
    		 */
    		~SResultSet();
		/**
		 * Pone los records
		 * @param fields 
		 * @param results 
		 */
		void setRecord(const QStringList &fields, const QStringList &results);
		
		/**
		 * Pone los records
		 * @param fields 
		 * @param results 
		 */
		void setRecord(const QStringList &fields, const QList<QVariant> &results);
		
		QMap<QString, QStringList> map() const;
		
		bool isValid() const;
		
	private:
		QMap<QString, QStringList> m_map;

};

#endif
