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

#include "dtquery.h"
#include <ddebug.h>

// DTQuery

DTQuery::DTQuery(Type t) : m_cwhere(""), m_type(t)
{
}


DTQuery::~DTQuery()
{
}

QString DTQuery::toString() const
{
	return m_query + " " + m_cwhere;
}

int DTQuery::type()
{
	return m_type;
}

void DTQuery::setWhere(const QString &w)
{
	m_cwhere = " where " + w;
}

void DTQuery::setCondition(const QString &condition)
{
	if ( m_cwhere.isNull() )
		setWhere("'t'");
	m_cwhere += " " + condition + " ";
}


// DTSelect
DTSelect::DTSelect(QStringList fields, QStringList tables, bool dist) : DTQuery(DTQuery::Select), m_fields(fields), m_filter("")
{
	if ( dist )
		m_query = "select distinct ";
	else
		m_query = "select ";
	
	if ( fields.count() == 0 )
	{
		dDebug() << (tr("You need specify the fields"));
	}
	for(int i = 0; i < fields.count(); i++)
	{
		if ( i == fields.count() - 1)
			m_query += fields[i];
		else
			m_query += fields[i] + ",";
	}
	m_query += " from ";
	for(int i = 0; i < tables.count(); i++)
	{
		if ( i == tables.count() - 1)
			m_query += tables[i];
		else
			m_query += tables[i] + ",";
	}

}

DTSelect::DTSelect(QStringList fields, const QString &table, bool dist) : DTQuery(DTQuery::Select), m_fields(fields), m_filter("")
{
	if ( dist )
		m_query = "select distinct ";
	else
		m_query = "select ";
	
	if ( fields.count() == 0 )
	{
		dDebug() << (tr("You need specify the fields"));
	}
	for(int i = 0; i < fields.count(); i++)
	{
		if ( i == fields.count() - 1)
			m_query += fields[i];
		else
			m_query += fields[i] + ",";
	}
	m_from = " from " + table;
}

DTSelect::~ DTSelect()
{
}

QString DTSelect::toString() const
{
	return m_query + m_from + m_join + m_cwhere + m_subquery + m_filter + m_orderby;
}

QStringList DTSelect::fields()
{
	return m_fields;
}

void DTSelect::addSubConsult(QString connector, const DTSelect &subconsult)
{
	m_subquery += " " + connector + " ( " + subconsult.toString() + " ) ";
}

void DTSelect::addFilter( const QString& filter, QStringList fields )
{
	if ( !filter.isEmpty() )
	{
		if ( m_cwhere.isEmpty() )
			m_cwhere = " where 't'";
		m_filter = " and 'f' ";
		
		QStringList filters = filter.split( ' ');
		
		
		for ( int f = 0; f < filters.count(); f++)
		{
			if ( fields.count() > 0)
			{
				for (int i = 0; i < fields.count(); i++)
				{
					m_filter += " OR " + fields[i]  + " ~* "+ SQLSTR(filters[f]);
				}
			}
			else
			{
				for (int i = 0; i < m_fields.count(); i++)
				{
					m_filter += " OR " + m_fields[i]  + " ~* "+ SQLSTR(filters[f]);
				}
			}
		}
	}
}

void DTSelect::setOrderBy(const QString &field, Order o)
{
	m_orderby = " order by "+field+" ";
	switch(o)
	{
		case Asc:
		{
			m_orderby += "asc";
		}
		break;
		case Desc:
		{
			m_orderby += "desc";
		}
		break;
		case NoOrder:
		{
			m_orderby = "";
		}
		break;
	}
}

void DTSelect::setOrderBy(int field, Order o)
{
	if ( field < m_fields.count() )
		setOrderBy(m_fields[field], o);
}

void DTSelect::setJoin(const QString &link, JoinConnector jc, const QStringList &rest)
{
	m_join = " join " + link + " ";
	switch(jc)
	{
		case On:
		{
			if ( rest.count() > 1 )
				m_join += "on "+rest[0]+"="+rest[1];
			else
			{
				dDebug() << (tr("For a join clause you need two fields"));
				m_join = "";
			}
		}
		break;
		
		case Using:
		{
			m_join += "using (";
			for(int i = 0; i < rest.count(); i++)
			{
				if ( i == rest.count() - 1)
					m_join += rest[i];
				else
					m_join += rest[i] + ",";
			}
			
			m_join += ")";
		}
		break;
		
		default:
		{
			m_join ="";
		}
		break;
	}
}

// DTUpdate

DTUpdate::DTUpdate(QString table, QStringList fields, QStringList values) : DTQuery(DTQuery::Update)
{
	Q_ASSERT(fields.count() == values.count());
	
	m_query = " UPDATE " + table + " set ";
	for (int i = 0; i < fields.count(); i++)
	{
		if ( i == values.count() - 1)
			m_query += fields[i] + " = " + values[i];
		else
			m_query += fields[i] + " = " + values[i] + ",";
	}
}

DTUpdate::~DTUpdate()
{
}

DTInsert::DTInsert(QString table, QStringList values) : DTQuery(DTQuery::Insert)
{
	m_query = "insert into " + table + " values ( ";
	
	for (int i = 0; i < values.count(); i++)
	{
		if ( i == values.count() - 1)
			m_query += values[i];
		else
			m_query += values[i] + ",";
	}
	
	m_query += " )";
}

DTInsert::~DTInsert()
{
}

// DTDelete
DTDelete::DTDelete(QString table) : DTQuery(DTQuery::Delete)
{
	m_query = "delete from " + table + " ";
}

DTDelete::~DTDelete()
{
}
