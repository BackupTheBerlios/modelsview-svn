#include "form.h"
#include <qsizepolicy.h>
#include <qfiledialog.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qsettings.h>
#include "plugindialog.h"
#include <qdialog.h>

Form::Form(): QWidget(0){
	_box = new QVBox(this);
	//_box->resize(600,600);
	
	_buttonbox = new QHBox(_box);
	_buttonbox->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
	QSettings setting;
        //setting.setPath("qtlinuxoff.org","QTLinuxOff");
	bool *found = new bool;
	//*found = false;
	QString from = setting.readEntry("/carofe/3dmodelsview/plugins","none",found);
	if(!(*found)){
		PluginDialog *pd = new PluginDialog();
		int res = pd->exec();
		if(res==QDialog::Accepted){
			from = pd->getPDir();
 			if(from==QString::null) qApp->exit(1);
			setting.writeEntry("/carofe/3dmodelsview/plugins",from);					
		}else qApp->exit(1);
		
	}
        
	_plugins = new PluginLoader();
        _plugins->loadAll(from);
	_oglwidget = _plugins->create("ASC",_box);
      #ifdef MYDEBUG
        if(!_oglwidget) qDebug("No se cargo nada");
      #endif
	_buttongroup = new QHButtonGroup(_buttonbox);
	_buttongroup->setTitle(tr("View Model"));
	
	_openfile = new QPushButton(tr("Open"),_buttonbox);
	
	_fill = new QRadioButton(tr("Fill"),_buttongroup);
	_lines = new QRadioButton(tr("Lines"),_buttongroup);
	_points = new QRadioButton(tr("Points"),_buttongroup);
	_lines->setChecked(true);
	
	
	connect(_openfile,SIGNAL(clicked()),this,SLOT(slotOpenFile()));
	connect(_buttongroup,SIGNAL(clicked(int)),SLOT(slotPropertiesChanged(int)));
	resize(600,500);
	
}

Form::~Form(){
}

void Form::resizeEvent(QResizeEvent* e){
	_box->resize(size());
	QWidget::resizeEvent(e);
}

void Form::slotPropertiesChanged(int id){
	if(_lines->isChecked()){
		_oglwidget->mode(Lines);
	}else if(_fill->isChecked()){
		_oglwidget->mode(Fill);
	}else if(_points->isChecked()){
		_oglwidget->mode(Points);
	}
	_oglwidget->updateGL();
}

void Form::slotOpenFile(){
	QString filename = QFileDialog::getOpenFileName();
	QString ext = filename.mid(filename.findRev("."));
#ifdef MYDEBUG
        qDebug(ext.latin1());
#endif
        ext = ext.upper().remove(0,1);
#ifdef MYDEBUG
        qDebug(ext.latin1());
#endif
        if(_plugins->keys().findIndex(ext)==-1){
		QMessageBox::critical(this,tr("No Plugin Found"),tr("No Plugin Found for this format"),
			QMessageBox::Ok,QMessageBox::NoButton);
        }else{
		removeChild(_oglwidget);
		delete _oglwidget;
		_oglwidget = NULL;
		_oglwidget = _plugins->create(ext,_box);
                _oglwidget->show();
		if(!_oglwidget){
			QMessageBox::critical(this,tr("Internal Error"),tr("An internal error has occured"),
				QMessageBox::Ok,QMessageBox::NoButton);
			qApp->exit(1);
		}	
		_oglwidget->loadFile(filename);
	}
	
}
