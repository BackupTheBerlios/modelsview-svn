/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/
void PluginDialog::init(){
    _pdir = QString::null;
}

void PluginDialog::browserButton_clicked()
{
    _pdir = QFileDialog::getExistingDirectory(QString::null,this,0,"Plugins Dir",true);
    lineEdit1->setText(_pdir);
}


QString PluginDialog::getPDir()
{
    return _pdir;
}
