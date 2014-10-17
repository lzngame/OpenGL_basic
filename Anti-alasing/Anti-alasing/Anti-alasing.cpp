// Anti-alasing.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <math.h>
#include <gl/glut.h>
#define x_Screen 800
#define y_Screen 600
#define little 50
#define middle 20
#define large 8

void myBackground(){
	glClearColor(0.0,0.0,0.0,1.0);
	glColor3f(1.0,1.0,1.0);
}

void myDisplay(){
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_POINT_SMOOTH);
//	glEnable(GL_LINE_SMOOTH);
	
//	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);
//	glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	int i;
	glBegin(GL_POINTS);
	for(i=0;i<little;i++){
		glVertex2f(50.0+rand()%x_Screen,50.0+rand()%y_Screen);
	}
	glEnd();

	glPointSize(8);
	glBegin(GL_POINTS);
	for(i=0;i<large;i++)
		glVertex2f(50.0+rand()%x_Screen,50.0+rand()%y_Screen);
	glEnd();

	glBegin(GL_POLYGON);
	for(i=0;i<64;i++)
		glVertex2f(600+50.0*cos((float)i/10),500+50.0*sin((float)i/10));
	glEnd();

	glLineWidth(3);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);

	glBegin(GL_LINE_STRIP);
	for(i=0;i<19;i++)
		glVertex2f(rand()%10+i*70,rand()%50+50.0+(i%2)*80);
	glEnd();

	glutSwapBuffers();
}

void myChange(int w,int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,x_Screen,0.0,y_Screen);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(x_Screen,y_Screen);
	glutCreateWindow("反走样 OpenGL");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myChange);
	myBackground();
	glutMainLoop();
	return 0;
}

