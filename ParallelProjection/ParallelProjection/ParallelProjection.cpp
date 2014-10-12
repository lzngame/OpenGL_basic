// ParallelProjection.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl\glut.h>

void render(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	//glRectf(0.25f,0.25f,0.75f,0.75f);
	glutSolidSphere(1.0,20,16);
	//glTranslated(0,0,-1.5);
	//默认单缓冲,不需要用户交互
	glFlush();
}

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	//initialize view values
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGB);
	glutInitWindowSize(400,400);
	glutCreateWindow("Parallel Projection");
	init();
	glutDisplayFunc(render);
	glutMainLoop();
	return 0;
	return 0;
}

