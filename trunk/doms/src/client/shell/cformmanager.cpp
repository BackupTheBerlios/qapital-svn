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

#include "cformmanager.h"

#include <QFile>
#include <QTextStream>
#include <QDir>

#include <dapplicationproperties.h>
#include <ddebug.h>

CFormManager::CFormManager(QObject *parent) : QObject(parent)
{
	m_builder = new CFormBuilder;
	
	m_formsPath = dAppProp->configDir()+"/cache/forms";
	
	QDir dir(m_formsPath);
	if ( !dir.exists() )
	{
		dir.mkpath(m_formsPath);
	}
}

CFormManager::~CFormManager()
{
	delete m_builder;
}

void CFormManager::setForms(const QList<FormData> &forms)
{
	D_FUNCINFO;
	foreach(FormData data, forms)
	{
		QFile file(m_formsPath+"/"+QString::number(data.id));
		
		if ( file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QTextStream out(&file);
			
			out << data.document;
			file.close();
		}
	}
}


void CFormManager::loadForm(int id)
{
	QFile file(m_formsPath+"/"+QString::number(id));
	
	if ( file.exists() )
	{
		if ( file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QString document = file.readAll();
			
			emit formLoaded(m_builder->form( document ), tr("TITLE"));
		}
	}
	else
	{
		dError() << "Form with id = " << id << " doesn't exists";
	}
}



