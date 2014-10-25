// PickPoint.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

int posx1 = 150;
int posy1 = 200;

int posx2 = 250;
int posy2 = 200;

int select_point = 0;
int screenWidth = 400;
int screenHeight = 400;

void init(){
	glClearColor(1,1,1,1);
}

void draw(GLenum mode){
	glPointSize(10.0f);
	const static GLfloat color_selected[] = {1.0f,0.0f,0.0f};
	const static GLfloat color_unselected[] ={0.0f,0.0f,1.0f};
	for(int i=0;i<5;i++){
		if(mode == GL_SELECT)
			glLoadName(i);
		glColor3fv((select_point==i)?color_selected:color_unselected);
		glBegin(GL_POINTS);
			glVertex2f(i*70+20,200);
		glEnd();
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	draw(GL_RENDER);
	glFlush();
}

void reshape(int w,int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,screenWidth,0,screenHeight);
	glMatrixMode(GL_MODELVIEW);
}

void processHits(GLint hits,GLuint buffer[]){
	unsigned int i;
	GLuint name;
	for(i = 0;i<hits;i++){
		name = buffer[3+i*4];
		select_point = name;
		cout<<"NO." <<name << " point"<<endl;
	}
}

#define SIZE 500
#define N 10

void mouse(int button,int state,int x ,int y){
	GLuint selectBuffer[SIZE];
	GLint hits;
	GLint viewport[4];
	if(state==GLUT_DOWN && button==GLUT_LEFT_BUTTON){
		glGetIntegerv(GL_VIEWPORT,viewport);
		glSelectBuffer(SIZE,selectBuffer);
		glRenderMode(GL_SELECT);
		glInitNames();
		glPushName(0);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluPickMatrix(x,viewport[3]-y,N,N,viewport);
		gluOrtho2D(0,screenWidth,0,screenHeight);
		draw(GL_SELECT);
		glPopMatrix();
		glFlush();
		hits=glRenderMode(GL_RENDER);
		glMatrixMode(GL_MODELVIEW);
		if(hits >0)
			processHits(hits,selectBuffer);
		glutPostRedisplay();
	}
	if(state==GLUT_UP&&button==GLUT_LEFT_BUTTON){
		select_point  = 0;
		glRenderMode(GL_RENDER);
		draw(GL_RENDER);
		glutPostRedisplay();
	}
}



int main(int argc,char * argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowPosition(500,0);
	glutInitWindowSize(screenWidth,screenHeight);
	glutCreateWindow("Pickup Point");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 1;
	
}

