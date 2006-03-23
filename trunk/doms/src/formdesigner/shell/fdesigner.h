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

#ifndef FDESIGNER_H
#define FDESIGNER_H

#include <qmainwindow.h>


#include <cformbuilder.h>

#include <QXmlSimpleReader>

#include <QScrollArea>

class QTextEdit;
class QWorkspace;
class QBoxLayout;

/**
 * @author David Cuadrado <krawek@gmail.com>
*/
class FDesigner : public QMainWindow
{
	Q_OBJECT
	public:
		FDesigner();
		~FDesigner();
		
	private:
		void setupMenu();
		
	private slots:
		void analize();
		void openFile(const QString &file);
		void openFile();
		
	private:
		QTextEdit *m_editor;
		QWorkspace *m_workspace;
		
		QXmlSimpleReader m_reader;
		CFormBuilder *m_builder;
		
		QBoxLayout *m_mainLayout;
		
		QMainWindow *m_currentForm;
};

#endif
