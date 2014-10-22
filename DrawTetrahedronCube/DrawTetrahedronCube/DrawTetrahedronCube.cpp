// DrawTetrahedronCube.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <gl/glut.h>
using namespace std;
float rtri;
float rquad;
GLfloat points0[5][3] = {{0,1,0},{-1,-1,-1},{1,-1,1},{1,-1,-1},{-1,-1,-1}};
GLfloat Colors0[4][3] = {{1,0,0},{0,1,0},{0,0,1},{1,1,0}};
int vertice0[4][3] ={{0,1,2},{0,2,3},{0,3,4},{0,4,1}};

void InitGL(GLvoid){
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void CreatePyramid(){
	glBegin(GL_TRIANGLES);
	for(int i=0;i<4;i++){
		glColor3fv(Colors0[i]);
		for(int j=0;j<3;j++){
			int Vtxid = vertice0[i][j];
			glVertex3fv(points0[Vtxid]);
		}
	}
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0f,1.0f,1.0f);
	for(int i=0;i<4;i++)
		glVertex3fv(points0[i]);
	glEnd();
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-1.5,0.0f,-6.0f);
	CreatePyramid();

	glutSwapBuffers();
}

void reshape(int w,int h){
	if(0 == h)
		h = 1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(600,400);
	glutCreateWindow("Pyramid and cube");
	InitGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}

