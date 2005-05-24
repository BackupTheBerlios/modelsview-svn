/****************************************************************************
** Form interface generated from reading ui file 'plugindialog.ui'
**
** Created: vie may 13 23:40:01 2005
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.1   edited Nov 24 13:47 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PLUGINDIALOG_H
#define PLUGINDIALOG_H

#include <qvariant.h>
#include <qdialog.h>
#include <qfiledialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QPushButton;
class QLineEdit;

class PluginDialog : public QDialog
{
    Q_OBJECT

public:
    PluginDialog( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~PluginDialog();

    QLabel* textLabel2;
    QLabel* textLabel1;
    QPushButton* browserButton;
    QLineEdit* lineEdit1;
    QPushButton* okButton;

    QString getPDir();

public slots:
    virtual void browserButton_clicked();

protected:

protected slots:
    virtual void languageChange();

private:
    QString _pdir;

    void init();

};

#endif // PLUGINDIALOG_H
