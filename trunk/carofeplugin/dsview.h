//
// C++ Interface: 3dsview
//
// Description: 
//
//
// Author: Carlos Rodriguez Fernandez <carlosrf82@yahoo.es>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef DSVIEW_H
#define DSVIEW_H
#include <qgl.h>
#include "mvglwidget.h"
#include "3ds.hpp"
#include <cmath>

/**
@author Carlos Rodriguez Fernandez
*/
class DsView : public MVGLWidget
{
public:
    DsView(QWidget *);

    virtual ~DsView();
    bool loadFile(QString);
		
protected:
	void initializeGL();
	void resizeGL( int , int );
	void paintGL();
	void mousePressEvent ( QMouseEvent * e );
	void mouseReleaseEvent ( QMouseEvent * e );
	void mouseMoveEvent ( QMouseEvent * e );
private:
	L3DS _scene;
	double mx,my,mz,_max;
	
	int _x,_y,_rotX,_rotY;
	float _ortho;
	double max(double a,double b){
          return a>b?a:b;
        }

};


#endif
