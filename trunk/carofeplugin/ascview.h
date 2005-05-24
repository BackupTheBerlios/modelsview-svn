#ifndef MYGLWIDGET_H_
#define MYGLWIDGET_H_

#include <qgl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "asc.h"
#include "mvglwidget.h"


class AscView: public MVGLWidget{
	public:
		AscView(QWidget *);
		virtual ~AscView();
		bool loadFile(QString);
		
	protected:
		void initializeGL();
		void resizeGL( int , int );
		void paintGL();
		void mousePressEvent ( QMouseEvent * e );
		void mouseReleaseEvent ( QMouseEvent * e );
		void mouseMoveEvent ( QMouseEvent * e );
	private:
		Object3DGroup escena;
		double mx,my,mz;
		
		int _x,_y,_rotX,_rotY;
		float _ortho;
};

#endif
