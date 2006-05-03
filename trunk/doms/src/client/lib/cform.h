/***************************************************************************
 *   Copyright (C) 2006 by David Cuadrado                                  *
 *   krawek@gmail.com                                                      *
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

#ifndef CFORM_H
#define CFORM_H

#include <qwidget.h>
#include "formwidgetiface.h"

/**
 * @author David Cuadrado <krawek@gmail.com>
*/
class CForm : public QWidget
{
	Q_OBJECT;
	public:
		CForm();
		~CForm();
		
		void addInput(FormWidgetIface *input);
		
		void debug();
		
	private:
		/**
		 * La llave es el nombre de la tabla, el valor es una lista de widgets de donde se pueden sacar la tabla a la que pertenece, el campo en la tabla y el valor actual.
		 */
		QMap<QString, QList<FormWidgetIface*> > m_inputMap;
};

#endif


