/****************************************************************************
** Form implementation generated from reading ui file 'plugindialog.ui'
**
** Created: vie may 13 23:40:14 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.1   edited Nov 24 13:47 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "plugindialog.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include "plugindialog.ui.h"

/*
 *  Constructs a PluginDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
PluginDialog::PluginDialog( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "PluginDialog" );

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setGeometry( QRect( 80, 30, 400, 60 ) );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setGeometry( QRect( 20, 120, 100, 20 ) );

    browserButton = new QPushButton( this, "browserButton" );
    browserButton->setGeometry( QRect( 360, 170, 140, 27 ) );

    lineEdit1 = new QLineEdit( this, "lineEdit1" );
    lineEdit1->setGeometry( QRect( 150, 120, 400, 25 ) );

    okButton = new QPushButton( this, "okButton" );
    okButton->setGeometry( QRect( 210, 220, 117, 27 ) );
    languageChange();
    resize( QSize(613, 289).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( browserButton, SIGNAL( clicked() ), this, SLOT( browserButton_clicked() ) );
    connect( okButton, SIGNAL( clicked() ), this, SLOT( accept() ) );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
PluginDialog::~PluginDialog()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void PluginDialog::languageChange()
{
    setCaption( tr( "Plugin Dialog" ) );
    textLabel2->setText( tr( "Please, select the path where plugins are installed.\n"
"(maybe in $APP_INSTALLED/plugins). $APP_INSTALLED\n"
" is the dir where this app is installed." ) );
    textLabel1->setText( tr( "Plugins Path:" ) );
    browserButton->setText( tr( "&Browser" ) );
    browserButton->setAccel( QKeySequence( tr( "Alt+B" ) ) );
    okButton->setText( tr( "&Ok" ) );
    okButton->setAccel( QKeySequence( tr( "Alt+O" ) ) );
}

