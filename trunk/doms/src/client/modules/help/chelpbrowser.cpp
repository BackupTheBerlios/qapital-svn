/***************************************************************************
 *   Copyright (C) 2005 by David Cuadrado                                  *
 *   krawek@toonka.com                                                     *
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

#include "chelpbrowser.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

// CHelpBrowser

CHelpBrowser::CHelpBrowser( QWidget *parent)
	: QWidget(parent)
{
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->setMargin(15);
	m_separator = new QSplitter(this);
	layout->addWidget(m_separator);

	m_pageArea = new QTextBrowser(m_separator);
	
	m_document = new QTextDocument(m_pageArea);
	
	m_pageArea->setDocument(m_document);
}


CHelpBrowser::~CHelpBrowser()
{
}

void CHelpBrowser::setDocument(const QString &doc)
{
	m_document->setHtml(doc);
}

void CHelpBrowser::setSource( const QString &filePath)
{
	m_pageArea->setSource(filePath);
}

void CHelpBrowser::setDataDirs(const QStringList &dirs)
{
	m_pageArea->setSearchPaths (dirs);
}

