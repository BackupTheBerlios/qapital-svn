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

#include "cchatwindow.h"

#include <QLineEdit>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "cchatpackage.h"

#include "global.h"
#include <ddebug.h>


class TextWindow : public QTextBrowser
{
	public:
		TextWindow();
		~TextWindow();
		void addMessage(const QString &login, const QString &msg);
};

TextWindow::TextWindow()
{
}

TextWindow::~TextWindow()
{
}

void TextWindow::addMessage(const QString &login, const QString &msg)
{
	QString newText = Qt::escape(msg);
	
	newText = newText.replace(":)", QString("<img src=\"")+THEME_DIR+"/chat/smile.png" +"\" />");
	newText = newText.replace(":(", QString("<img src=\"")+THEME_DIR+"/chat/sad.png" +"\" />");
	newText = newText.replace("xD", QString("<img src=\"")+THEME_DIR+"/chat/laugh.png" +"\" />");
	newText.remove('\n');
	
	append("<"+login+"> ");
	insertHtml(newText+'\n');
}



CChatWindow::CChatWindow(QWidget *parent) : QDialog(parent)
{
	setModal(false);
	QVBoxLayout *layout = new QVBoxLayout(this);
	
	setWindowTitle(tr("Chat ;)"));
	
	m_messageArea = new TextWindow;
	layout->addWidget(m_messageArea);
	
	QHBoxLayout *lineLayout = new QHBoxLayout;
	m_prompt = new QLineEdit;
	lineLayout->addWidget(m_prompt);
	
	QPushButton *send = new QPushButton(tr("Send"));
	
	connect(send, SIGNAL(clicked()), this, SLOT(emitMessage()));
	lineLayout->addWidget(send);
	
	layout->addLayout(lineLayout);
	
	setWindowFlags(Qt::WindowStaysOnTopHint);
}


CChatWindow::~CChatWindow()
{
}


void CChatWindow::emitMessage()
{
	QString text = m_prompt->text();
	
	if ( text.isEmpty() ) return;
	
	emit textToSend( CChatPackage(text).toString() );
	
	m_prompt->clear();
}

void CChatWindow::setChatMessage(const QString &login, const QString &msg)
{
	m_messageArea->addMessage( login, msg);
}

