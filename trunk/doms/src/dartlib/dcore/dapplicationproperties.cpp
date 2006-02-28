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

#include "dapplicationproperties.h"

#include <QDir>
#include <QLocale>

#include <QApplication>

DApplicationProperties *DApplicationProperties::s_instance = 0;


DApplicationProperties::DApplicationProperties()
{
}


DApplicationProperties::~DApplicationProperties()
{
}

void DApplicationProperties::setDataDir(const QString &v)
{
	m_dataDir = v;
}

void DApplicationProperties::setHomeDir(const QString &v)
{
	m_homeDir = v;
}

void DApplicationProperties::setThemeDir(const QString &v)
{
	m_themeDir = v;
}

QString DApplicationProperties::dataDir() const
{
	if ( m_dataDir.isEmpty() )
	{
		QString locale = QString(QLocale::system().name()).left(2);
	
		if ( locale.length() < 2 )
		{
			locale = "en";
		}
		
		return m_homeDir+"/data/"+locale+"/";
	}
	
	return m_dataDir;
}

QString DApplicationProperties::homeDir() const
{
	return m_homeDir;
}

QString DApplicationProperties::themeDir() const
{
	return m_themeDir;
}

QString DApplicationProperties::configDir() const
{
	return QDir::homePath()+"/."+qApp->applicationName();
}

DApplicationProperties *DApplicationProperties::instance()
{
	if (s_instance == 0 )
	{
		s_instance = new DApplicationProperties;
	}
	
	return s_instance;
}


