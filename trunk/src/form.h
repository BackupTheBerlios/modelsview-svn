#ifndef FORM_H_
#define FORM_H_ 
#include <qwidget.h>
#include <qgl.h>
#include "mvglwidget.h"
#include <qhbuttongroup.h>
#include <qhbox.h>
#include <qvbox.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include "pluginloader.h"


class Form : public QWidget{
	Q_OBJECT
	public:
		Form();
		~Form();
		
	public slots:
		void slotPropertiesChanged(int);
		void slotOpenFile();
	protected:
		void resizeEvent(QResizeEvent*);
	private:
		MVGLWidget *_oglwidget;
		QHButtonGroup * _buttongroup;
		QRadioButton *_fill,*_lines,*_points;
		QPushButton * _openfile;
		QHBox * _buttonbox;
		QVBox * _box;
		PluginLoader * _plugins;

};
#endif
