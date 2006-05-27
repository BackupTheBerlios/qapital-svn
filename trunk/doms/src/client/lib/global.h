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

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <QString>
#include <QHash>
#include <QMap>
#include <QList>
#include <QPair>

#include <dglobal.h>

typedef QPair<QString, QString> StringPair;

namespace Msg
{
	enum Type
	{
		Info,
		Warning,
		Error
	};
}

struct FormData
{
	int id;
	QString document;
};

struct ModuleInfo
{
	QString key;
	QString text;
	
	/**
	 * Contiene una lista de header-campo.
	 */
	QList< StringPair > listInfo;
};

struct DBField
{
	QString name;
	QString table;
};

#define TABLE_DOT_ATT(field) field.table+"."+field.name

inline bool operator==(const ModuleInfo &e1, const ModuleInfo &e2)
{
	return e1.key == e2.key/* && e1.text == e2.text*/;
}

inline uint qHash(const ModuleInfo &key)
{
	return qHash(key.key) ^ key.text.length();
}

typedef QList<FormData> FormDataList;
typedef QHash<ModuleInfo, FormDataList> ModuleForms;
typedef QHash<QString, QString> XMLResults;


#endif


