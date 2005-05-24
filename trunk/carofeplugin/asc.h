#include <stdlib.h>
#include <stdio.h>

struct Point3f
{
	float x, y, z;
};

struct Face
{
	int vertexIndices[3];
	Point3f normals;
};

struct Object3D
{
	int nVertices;
	Point3f *pVertices;			
	int nFaces;
	Face *pFaces;
        char * name;
};

struct Object3DGroup
{
        int nObject3D;
        Object3D object3D[10000];
};

void LoadObject(FILE *fin, Object3D& object);
void LoadScene(const char *filename, Object3DGroup& group);
/*
Para acceder a un objeto:
group.pObject3D[indice]
luego hago para que se carculen las normales automaticamente
al cargase el vector. por el momento ya puedes dibujar.

*/
