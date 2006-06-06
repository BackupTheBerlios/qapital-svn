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

#ifndef CFORMMANAGER_H
#define CFORMMANAGER_H

#include <QObject>

#include "cformbuilder.h"
#include "global.h"

/**
 * Gestiona los documentos de formulario que el servidor envia al cliente, tiene funciones utiles para cargar los diferentes documentos.
 * @author David Cuadrado \<krawek@gmail.com\>
*/
class CFormManager : public QObject
{
	Q_OBJECT;
	public:
		CFormManager(QObject *parent = 0);
		~CFormManager();
		
	public slots:
		void setForms(const ModuleForms &forms);
		CForm *loadForm(const QString &module, int id);
		
	private:
		CFormBuilder *m_builder;
		QString m_formsPath;

};

#endif
