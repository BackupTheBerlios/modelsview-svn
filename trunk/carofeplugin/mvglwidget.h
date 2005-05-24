
#ifndef MVGLWIDGET_H
#define MVGLWIDGET_H
#include <qgl.h>
#include <qevent.h>


// Interface 3DMVGLWidget
// 
// 
enum Modes{Lines,Points,Fill};
class MVGLWidget : public QGLWidget{

public:
  MVGLWidget(QWidget *p);
  virtual ~MVGLWidget();
   
 virtual bool  loadFile (QString ) = 0;
  //At the end you must put "updateGL();" instruction
  
  Modes  mode ();
 
  void  mode (Modes m);
    
  

protected:
  void mousePressEvent ( QMouseEvent * e )=0;
  void mouseReleaseEvent ( QMouseEvent * e )=0;
  void mouseMoveEvent ( QMouseEvent * e )=0;
private:
  Modes _mode;
  
};
#endif //MVGLWIDGET_H



