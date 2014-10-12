// CallbackHandle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
void  render(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex3f(0.25,0.25,0.0);
		glVertex3f(0.75,0.25,0.0);
		glVertex3f(0.75,0.75,0.0);
		glVertex3f(0.25,0.75,0.0);
	glEnd();

	glFlush();
}

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
	gluOrtho2D(0,1,0,1);
}

void reshape(int w,int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1,0,1);
	glViewport(0,0,400,200);
//	glViewport(0,0,400,400);
//	glViewport(0,0,w,h);
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(250,250);
	glutInitWindowPosition(400,400);
	glutCreateWindow("glutDisplayFunc()");
	init();
	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
	return 0;
}
 
