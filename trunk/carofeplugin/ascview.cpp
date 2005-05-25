
#include "ascview.h"
#include <qfile.h>
#include <cmath>

using namespace std;



AscView::AscView(QWidget *p):MVGLWidget(p){
	escena.nObject3D =0;
	mode(Lines);
	_ortho=5.0;
	_rotX=0;
	_rotY=0;
}

AscView::~AscView(){}

bool AscView::loadFile(QString filename){
      if(!QFile::exists(filename)) return false;
      QFile f(filename);
      if(!f.open(IO_ReadOnly)) return false;
      f.close();
      LoadScene(filename.latin1(),escena);
      mx=my=mz=0;
      int nVertTotal=0;
      for(int i=0;i<escena.nObject3D;i++){
         for(int j=0;j<escena.object3D[i].nVertices;j++){
            mx += escena.object3D[i].pVertices[j].x;
            my += escena.object3D[i].pVertices[j].y;
            mz += escena.object3D[i].pVertices[j].z;
         }//for j
         nVertTotal+=escena.object3D[i].nVertices;
      }//for i

      mx = mx/nVertTotal;
      my = my/nVertTotal;
      mz = mz/nVertTotal;
      //normales
      for(int i = 0; i < escena.nObject3D ; i++){
        for(int j = 0 ; j < escena.object3D[i].nFaces; j++){
            double x[3],y[3],z[3];
            x[0]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[0]].x;
            y[0]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[0]].y;
            z[0]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[0]].z;
            x[1]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[1]].x;
            y[1]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[1]].y;
            z[1]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[1]].z;
            x[2]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[2]].x;
            y[2]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[2]].y;
            z[2]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[2]].z;
	    //Comparar todos los vertices y quedarse con el maximo para ajustar el ortho.
	    _max = max(max(max(abs(x[0]-mx),abs(x[1]-mx)),abs(x[2]-mx)),_max);
	    _max = max(max(max(abs(y[0]-my),abs(y[1]-my)),abs(y[2]-my)),_max);
            _max = max(max(max(abs(z[0]-mz),abs(z[1]-mz)),abs(z[2]-mz)),_max);
            double qx = x[1]-x[0];
            double qy = y[1]-y[0];
            double qz = z[1]-z[0];
            double px = x[2]-x[1];
            double py = y[2]-y[1];
            double pz = z[2]-z[1];
            double normal[3];
            normal[0] = qy*pz-qz*py;
            normal[1] = qz*px-qx*pz;
            normal[2] = qx*py-qy*px;
            double modulo=sqrt(normal[0]*normal[0]+normal[1]*normal[1]+normal[2]*normal[2]);
            double unidad[]={normal[0]/modulo,normal[1]/modulo,normal[2]/modulo};
            escena.object3D[i].pFaces[j].normals.x=unidad[0];
            escena.object3D[i].pFaces[j].normals.y=unidad[1];
            escena.object3D[i].pFaces[j].normals.z=unidad[2];
        }//for j
   }//for i	
      _ortho = _max;
      updateGL();
      return true;
}

void AscView::initializeGL(){
	glViewport(0,0,size().width(), size().height());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-_ortho,_ortho,-_ortho,_ortho,_ortho,-_ortho);
}

void AscView::resizeGL( int , int ){
	glViewport(0,0,size().width(), size().height());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-_ortho,_ortho,-_ortho,_ortho,_ortho,-_ortho);
}

void AscView::paintGL(){
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
   float PosLuz[4]={3*_max,3*_max,3*_max,1.0};
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

   for(int i = 0; i < escena.nObject3D ; i++){
        for(int j = 0 ; j < escena.object3D[i].nFaces; j++){
                glColor3f(1.0f,1.0f,1.0f);
                glBegin(GL_TRIANGLES);
                        double x[3],y[3],z[3];
                        x[0]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[0]].x;
                        y[0]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[0]].y;
                        z[0]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[0]].z;
                        x[1]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[1]].x;
                        y[1]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[1]].y;
                        z[1]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[1]].z;
                        x[2]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[2]].x;
                        y[2]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[2]].y;
                        z[2]=escena.object3D[i].pVertices[escena.object3D[i].pFaces[j].vertexIndices[2]].z;
                        glNormal3f(escena.object3D[i].pFaces[j].normals.x,escena.object3D[i].pFaces[j].normals.y,escena.object3D[i].pFaces[j].normals.z);
                        glVertex3f(x[0]-mx,y[0]-my,z[0]-mz);
                        glNormal3f(escena.object3D[i].pFaces[j].normals.x,escena.object3D[i].pFaces[j].normals.y,escena.object3D[i].pFaces[j].normals.z);
                        glVertex3f(x[1]-mx,y[1]-my,z[1]-mz);
                        glNormal3f(escena.object3D[i].pFaces[j].normals.x,escena.object3D[i].pFaces[j].normals.y,escena.object3D[i].pFaces[j].normals.z);
                        glVertex3f(x[2]-mx,y[2]-my,z[2]-mz);
                glEnd();
                
                glFlush();
        }//for j
   }//for i
   glFlush();
   glPopMatrix();
}

void AscView::mousePressEvent ( QMouseEvent * e ){
	if(e->button()==Qt::RightButton){
		_y=e->y();

	}else if(e->button()==Qt::LeftButton){
		_y=e->y();
		_x=e->x();
	}
}

void AscView::mouseReleaseEvent ( QMouseEvent * e ){
	_y=0;
	_x=0;
}

void AscView::mouseMoveEvent ( QMouseEvent * e ){
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

