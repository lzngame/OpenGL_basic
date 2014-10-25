// SolarAnimation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
#include <iostream>

float fEarth = 2.0f;
float fMoon = 24.0f;

void init(){
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f,0.0f,0.0f,0.8f);
}

void Reshape(int w,int h){
	if(0==h)
		h = 1;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,1.0f,1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f,0.0f,-500.0f);
	glColor3f(1.0f,0.0f,0.0f);
	glutSolidSphere(50.0f,20.0f,20.0f);

	glColor3f(0.0f,0.0f,1.0f);
	glRotatef(23.27,0.0,0.0,1.0);
	glRotatef(fEarth,0.0f,1.0f,0.0f);
	glTranslatef(200.0f,0.0f,0.0f);
	glutSolidSphere(20.0f,20.0f,20.0f);

	glPopMatrix();
	glPopMatrix();
	glRotatef(6.0f,1.0f,1.0f,1.0f);
	glRotatef(fMoon,0.0f,1.0f,0.0f);
	glColor3f(1.0f,1.0f,0.0f);
	glTranslatef(30.0f,0.0f,0.0f);
	glutSolidSphere(5.0f,20,20);
	
	glLoadIdentity();
	glFlush();
	glutSwapBuffers();

}

void myIdle(void){
	fEarth += 0.03f;
	if(fEarth > 360.0f)
		fEarth = 2.0f;
	fMoon += 0.24f;
	if(fMoon > 360.0f)
		fMoon = 24.0f;
	display();
	std::cout<<"Earth:"<<fEarth<<"\tMoon:"<<fMoon<<std::endl;
}


int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,400);
	glutCreateWindow("太阳系动画");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(display);
	glutIdleFunc(&myIdle);
	init();
	glutMainLoop();
	return 0;
}

