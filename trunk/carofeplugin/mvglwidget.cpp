#include "mvglwidget.h"

MVGLWidget::MVGLWidget(QWidget *p):QGLWidget(QGLFormat(QGL::DoubleBuffer|QGL::DepthBuffer|QGL::Rgba|QGL::AlphaChannel),p){
	setAutoBufferSwap(true);

}

MVGLWidget::~MVGLWidget(){}



void MVGLWidget::mode(Modes m){
	_mode=m;
}

Modes MVGLWidget::mode(){
	return _mode;
}
