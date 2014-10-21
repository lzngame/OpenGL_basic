// Observation2D.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
typedef GLfloat point2d[2];

void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0,2.0,-2.0,2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0,1.0,1.0,1.0);
}

void t(point2d a,point2d b,point2d c){
	glBegin(GL_TRIANGLES);
		glVertex2fv(a);
		glVertex2fv(b);
		glVertex2fv(c);
	glEnd();
}
void display(void){
	point2d v[3] = {{-1.0,-0.58},{1.0,-0.58},{0.0,1.15}};
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	glViewport(0,0,300,400);
		t(v[0],v[1],v[2]);
	glColor3f(1.0,0.0,0.0);
	glViewport(300,0,300,400);
	glRotated(90.0,0.0,0.0,1.0);
		t(v[0],v[1],v[2]);
	glFlush();
}


int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,400);
	glutCreateWindow("二维观察");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}

