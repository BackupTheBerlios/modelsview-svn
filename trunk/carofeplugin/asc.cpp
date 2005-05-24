#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "asc.h"

void LoadObject(FILE *fin, Object3D& object)
{
 int count, vertexnum, tempA, tempB, tempC;
 float tempX, tempY, tempZ;
 char *tempString = new char [80];
 

	
 while(strncmp(tempString, "Vertices",8))
	{
	fscanf(fin, "%s", tempString);
	if (feof(fin))
		{
		printf("String \"Vertices\" not found in file.Exitting...\n");
		exit(1);
		}
	}//while
 fgetc(fin);

 fscanf(fin,"%d", &object.nVertices);
 object.pVertices = new Point3f[object.nVertices];

 while(strncmp(tempString, "Faces", 5))
	{
	fscanf(fin, "%s", tempString);
	if (feof(fin))
		{
		printf("String \"Faces\" not found in file.Exitting...\n");
		exit(1);
		}
	}
 fgetc(fin);

 fscanf(fin, "%d", &object.nFaces);
 object.pFaces = new Face[object.nFaces];

 while(strncmp(tempString, "Vertex",6))
	{
	fscanf(fin, "%s", tempString);
	if (feof(fin))
		{
		printf("String \"Vertex\" not found in file.Exitting...\n");
		exit(1);
		}
	}
 while(strncmp(tempString,"list:",5))
	{
	fscanf(fin, "%s", tempString);
	if (feof(fin))
		{
		printf("String \"list\" not found in file.Exitting...\n");
		exit(1);
		}
	}
 for (count = 0; count<object.nVertices; count++)
	{
	while(strncmp(tempString,"Vertex",6))
		{
		fscanf(fin, "%s", tempString);
		if(feof(fin))
			{
			printf("String \"Vertex\" not found in file.Exitting...\n");
			exit(1);
			}
		}
	fscanf(fin, "%d", &vertexnum);
	fscanf(fin, "%s", tempString);
	fscanf(fin, "%[^:]", tempString);
	fgetc(fin);
	fscanf(fin, "%f", &tempX);
	fscanf(fin, "%[^:]", tempString);
	fgetc(fin);
	fscanf(fin, "%f", &tempY);
	fscanf(fin, "%[^:]", tempString);
	fgetc(fin);
	fscanf(fin, "%f", &tempZ);
	object.pVertices[count].x=tempX;
	object.pVertices[count].y=tempY;
    object.pVertices[count].z=tempZ;
	}
 while(strncmp(tempString,"Face",4))
	{
	fscanf(fin, "%s", tempString);
	if (feof(fin))
		{
		printf("String \"Face\" not found in file.Exitting...\n");
		exit(1);
		}
	}
 while(strncmp(tempString,"list",4))
	{
	fscanf(fin, "%s", tempString);
	if (feof(fin))
		{
		printf("String \"list\" not found in file.Exitting...\n");
		exit(1);
		}
	}
 for (count = 0; count<object.nFaces; count++)
	{
	while(strncmp(tempString,"Face",4))
		{
		fscanf(fin, "%s", tempString);
		if (feof(fin))
			{
			printf("String \"Face\" not found in file.Exitting...\n");
			exit(1);
			}
		}
	fscanf(fin, "%d", &vertexnum);
	fscanf(fin, "%s", tempString);
	while (fgetc(fin) != 'A');
		fgetc(fin);
	fscanf(fin, "%d", &tempA);
	while (fgetc(fin) != 'B');
		fgetc(fin);
	fscanf(fin, "%d", &tempB);
	while (fgetc(fin) != 'C');
		fgetc(fin);
	fscanf(fin, "%d", &tempC);
	object.pFaces[count].vertexIndices[0]=tempA;
	object.pFaces[count].vertexIndices[1]=tempB;
	object.pFaces[count].vertexIndices[2]=tempC;
	}
}

void LoadScene(const char *filename, Object3DGroup& group)
{
 FILE *file_asc;
 char *tempString = new char[80];

 if((file_asc = fopen(filename, "rt"))==NULL)
	{
	printf("Error al abrir el archivo!! %s\n", filename);
	exit(1);
	}

 group.nObject3D=0;
 while(!feof(file_asc))
 {
        fscanf(file_asc,"%s",tempString);
        Object3D object;
	if(strcmp("Tri-mesh,",tempString)==0){
		LoadObject(file_asc,group.object3D[group.nObject3D]);
                group.nObject3D++;
        }//if

 }//while
  fclose(file_asc);
}



 