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

#include "speller.h"
#include "aspelliface.h"

#include <QtDebug>

Speller::Speller(QObject *parent) : QObject(parent), m_speller(0)
{
#if defined(HAVE_ASPELL)
	m_speller = new AspellIface;
#elif defined(HAVE_ISPELL)
	m_speller = new ISpellIface;
#else
#warning NO ASPELL/ISPELL MACROS DEFINED!
#endif
}


Speller::~Speller()
{
	if (m_speller) delete m_speller;
}

bool Speller::checkWord(const QString &word)
{
	if( m_speller)
	{
		return m_speller->checkWord(removeExtraCharacters(word));
	}
	return false;
}

QStringList Speller::suggestions(const QString &word)
{
	if ( m_speller )
	{
		return m_speller->suggestions(removeExtraCharacters(word));
	}
	
	return QStringList();
}

QString Speller::removeExtraCharacters(const QString &str)
{
	QString result = str;
	
	if ( !result[0].isLetterOrNumber() )
	{
		result.remove(0,1);
	}
	
	if(!result[result.length()-1].isLetterOrNumber() )
	{
		result.remove(result.length()-1,1);
	}
	
	return result;
}


