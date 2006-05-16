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
	
	m_formsPath = dAppProp->cacheDir()+"/forms";
	
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

void CFormManager::setForms(const ModuleForms &moduleForms)
{
	D_FUNCINFO;
	
	foreach(ModuleInfo module, moduleForms.keys() )
	{
		FormDataList forms = moduleForms.value(module);
		
		foreach(const FormData data, forms)
		{
			QFile file(m_formsPath+"/"+module.key+"-"+QString::number(data.id));
			
			if ( file.open(QIODevice::WriteOnly | QIODevice::Text))
			{
				QTextStream out(&file);
				
				out << data.document;
				file.close();
			}
		}
	}
}


CForm *CFormManager::loadForm(const QString &module, int id)
{
	dDebug() << "Loading form from " << module << " with id: " << id;
	
	QString moduleKey = module.toLower();
	QFile file(m_formsPath+"/"+moduleKey+"-"+QString::number(id));
	
	if ( file.exists() )
	{
		if ( file.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QString document = file.readAll();
			
			CForm *form = m_builder->form( document );
			return form;
		}
	}
	else
	{
		dError() << "Form from module " << moduleKey << " with id = " << id << " doesn't exists";
	}
	
	return 0;
}



