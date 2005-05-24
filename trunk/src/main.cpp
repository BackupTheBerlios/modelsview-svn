#include "form.h" 
#include <qapplication.h>

int main(int argc,char **argv){
	QApplication a(argc,argv);
        
	Form * w = new Form();
	a.setMainWidget(w);
	w->show();
	return a.exec();
}
