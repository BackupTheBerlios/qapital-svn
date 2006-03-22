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
#ifndef KTHELPBROWSER_H
#define KTHELPBROWSER_H

#include <QWidget>
#include <QSplitter>
#include <QTextBrowser>
#include <QTextDocument>

/**
 * @author David Cuadrado <krawek@toonka.com>
*/
class CHelpBrowser : public QWidget
{
	Q_OBJECT
	public:
		CHelpBrowser(QWidget *parent = 0);
		~CHelpBrowser();
		
	public slots:
		void setDocument(const QString &doc);
		void setSource( const QString &filePath);
		void setDataDirs(const QStringList &dirs);
		
	private:
		QSplitter *m_separator;
		QTextBrowser *m_pageArea;
		QTextDocument *m_document;
};

#endif
