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

#include "postgreserrorhandler.h"

#include <QObject>

PostgresErrorHandler::PostgresErrorHandler()
{
}

PostgresErrorHandler::~PostgresErrorHandler()
{
}

SErrorPackage PostgresErrorHandler::handle(const QSqlError &error)
{
// 	new row for relation "doms_persons" violates check constraint doms_persons_email_check
// 	insert or update on table "doms_pacients" violates foreign key constraint "doms_pacients_iddocument_fkey"
	
	QString text = error.databaseText().toLower();
	
	if ( text.contains("duplicate key") )
	{
		SErrorPackage package(error.number(), QObject::tr("Seems like pacients already exists"));
		
		return package;
	}
	else if ( text.contains("syntax error") )
	{
		SErrorPackage package(error.number(), QObject::tr("You're trying to do an invalid action"));
		
		return package;
	}
	
	SErrorPackage package(error.number(), QObject::tr("PostgresErrorHandler %1").arg(error.databaseText()));
	
	// TODO: Analizar los textos!
	return package;
}


