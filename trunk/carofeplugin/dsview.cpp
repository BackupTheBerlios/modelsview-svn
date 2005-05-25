//
// C++ Implementation: 3dsview
//
// Description: 
//
//
// Author: Carlos Rodriguez Fernandez <carlosrf82@yahoo.es>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "dsview.h"
#include <qapplication.h>



DsView::DsView(QWidget *p)
 : MVGLWidget(p)
{
	mode(Lines);
	_ortho=5.0;
	_rotX=0;
	_rotY=0;
}


DsView::~DsView()
{
}
bool DsView::loadFile(QString name){
  if(_scene.LoadFile(name.latin1())){
   
   mx=my=mz=0.0;
   int nVerticeTotal = 0;
   _max=0;
   
   for(int i=0;i<_scene.GetMeshCount();i++){
    LMesh * mesh = _scene.GetMesh(i);
    nVerticeTotal =+ mesh->GetVertexCount();
    for(int j=0;j<mesh->GetVertexCount();j++){
     LVector3 v = mesh->GetVertex(j);
     mx =+ v.x;
     my =+ v.y;
     mz =+ v.z;
    }
    
   }
   
   mx = mx/nVerticeTotal;
   #ifdef MYDEBUG
   qDebug(QString::number(mx).latin1());
   qDebug(QString::number(nVerticeTotal).latin1());
   #endif
   my = my/nVerticeTotal;
   #ifdef MYDEBUG
   qDebug(QString::number(my).latin1());
   #endif
   mz = mz/nVerticeTotal;
   #ifdef MYDEBUG
   qDebug(QString::number(mz).latin1());
   #endif
   for(int i=0;i<_scene.GetMeshCount();i++){
    LMesh * mesh = _scene.GetMesh(i);
    for(int j=0;j<mesh->GetVertexCount();j++){
     LVector3 v = mesh->GetVertex(j);
     _max = max(max(max(abs(v.x-mx),abs(v.y-my)),abs(v.z-mz)),_max);
    }
   }
   
   _ortho = _max;
   updateGL();
   
   return true;
  }else{ 
   
   return false;
  }
  
}
void DsView::initializeGL(){
	glViewport(0,0,size().width(), size().height());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-_ortho,_ortho,-_ortho,_ortho,_ortho,-_ortho);
}
void DsView::resizeGL( int x, int y){
	glViewport(0,0,size().width(), size().height());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-_ortho,_ortho,-_ortho,_ortho,_ortho,-_ortho);
}
void DsView::paintGL(){
glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-_ortho,_ortho,-_ortho,_ortho,_ortho,-_ortho);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glEnable(GL_DEPTH_TEST);
   glClearColor(0.0f,0.0f,0.0f,0.0f);
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   /*glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);*/
   /*
   glColor3f(1.0f,1.0f,0.0f);
   */
   glBegin(GL_LINES);
      glVertex3f(1000.0f,0.0f,0.0f);
      glVertex3f(-1000.0f,0.0f,0.0f);
      glVertex3f(0.0f,1000.0f,0.0f);
      glVertex3f(0.0f,-1000.0f,0.0f);
      glVertex3f(0.0f,0.0f,1000.0f);
      glVertex3f(0.0f,0.0f,-1000.0f);
   glEnd();
   glEnable(GL_LIGHTING);
   float LuzAmb[4]={0.6,0.6,0.6,1.0};
   float LuzDif[4]={1.0,1.0,1.0,1.0};
   float PosLuz[4]={5*_max,5*_max,5*_max,1.0};
   float Material[4]={0.8,0.8,0.0,1.0};
   glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,Material);
   glLightfv(GL_LIGHT0,GL_AMBIENT,LuzAmb);
   glLightfv(GL_LIGHT0,GL_DIFFUSE,LuzDif);
   glLightfv(GL_LIGHT0,GL_POSITION,PosLuz);
   glEnable(GL_LIGHT0);
   glPushMatrix();
   glRotatef(_rotX,1,0,0);
   glRotatef(_rotY,0,0,1);
   //glRotatef(0,0,0,1);
   if(mode() == Lines)
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   else if(mode() == Points)
        glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
   else if(mode() == Fill)
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
   for(int i=0;i<_scene.GetMeshCount();i++){
    for(int j=0;j<_scene.GetMesh(i)->GetFaceCount();j++){
     LFace face = _scene.GetMesh(i)->GetFace(j);
     glBegin(GL_TRIANGLES);
      glNormal3f(face.normals[0].x,face.normals[0].y,face.normals[0].z);
      glVertex3f(face.vertices[0].x-mx,face.vertices[0].y-my,face.vertices[0].z-mz);
      glNormal3f(face.normals[1].x,face.normals[1].y,face.normals[1].z);
      glVertex3f(face.vertices[1].x-mx,face.vertices[1].y-my,face.vertices[1].z-mz);
      glNormal3f(face.normals[2].x,face.normals[2].y,face.normals[2].z);
      glVertex3f(face.vertices[2].x-mx,face.vertices[2].y-my,face.vertices[2].z-mz);
     glEnd();
    }
    glFlush();
   }
   glFlush();
   glPopMatrix();
}
void DsView::mousePressEvent ( QMouseEvent * e ){
	if(e->button()==Qt::RightButton){
		_y=e->y();

	}else if(e->button()==Qt::LeftButton){
		_y=e->y();
		_x=e->x();
	}
}
void DsView::mouseReleaseEvent ( QMouseEvent * e ){
	_y=0;
	_x=0;
}
void DsView::mouseMoveEvent ( QMouseEvent * e ){
	if(e->state()==Qt::RightButton){
		_ortho+=float(e->y()-_y)/10.0;
		_y=e->y();
		updateGL();
	}else if(e->state()==Qt::LeftButton){
		_rotY+=e->x()-_x;
		_rotX+=e->y()-_y;
		_x=e->x();
		_y=e->y();
		updateGL();
	}
}

