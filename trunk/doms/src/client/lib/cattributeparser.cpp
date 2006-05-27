/***************************************************************************
 *   Copyright (C) 2006 by David Cuadrado                                  *
 *   krawek@gmail.com                                                       *
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

#include "cattributeparser.h"
#include <QStringList>

CAttributeParser::CAttributeParser()
{
}


CAttributeParser::~CAttributeParser()
{
}

DBField CAttributeParser::parseField(const QString &fieldStr)
{
	QStringList list = fieldStr.split(':');
	
	DBField field;
	
	if ( list.count() >= 2 )
	{
		field.table = list[0].toLower();
		
		if ( list[1].contains("->" ) )
		{
			field.name = list[1].split("->")[0].toLower();
		}
		else
		{
			field.name = list[1].toLower();
		}
	}
	
	return field;
}

QPair<DBField, DBField> CAttributeParser::parseFKField(const QString &fieldStr)
{
	QStringList list = fieldStr.split("->");
	
	DBField primary;
	DBField foreign;
	
	if ( list.count() == 2 )
	{
		primary = CAttributeParser::parseField(list[0]);
		foreign = CAttributeParser::parseField(list[1]);
	}
	
	return qMakePair(primary, foreign);
}

QStringList CAttributeParser::parseHeaders(const QString &headersStr)
{
	return headersStr.split(';');
}
