// SimpleTextureMapping.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
#include <stdlib.h>
#include <stdio.h>

static GLfloat xequalzero[] ={1.0,1.0,1.0,1.0};
static GLfloat slanted[] = {1.0,1.0,1.0,0.0};
static GLfloat* currentCoeff;
static GLenum currentPlane;
static GLint currentGenMode;
static float roangles;
#define stripeImageWidth 32

GLubyte stripeImage[4*stripeImageWidth];

void makeStripeImage(void){
	int j;
	for(j=0;j<stripeImageWidth;j++){
		stripeImage[4*j+0] = (GLubyte)((j<=4)?255:0);
		stripeImage[4*j+1] = (GLubyte)((j>4)?255:0);
		stripeImage[4*j+2] = (GLubyte)0;
		stripeImage[4*j+3] = (GLubyte)255;
	}
}

void init(GLvoid){
	glClearColor(1.0,1.0,1.0,1.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	makeStripeImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glTexParameteri(GL_TEXTURE_1D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_1D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_1D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage1D(GL_TEXTURE_1D,0,4,stripeImageWidth,0,GL_RGBA,GL_UNSIGNED_BYTE,stripeImage);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	currentCoeff = xequalzero;
	currentGenMode = GL_OBJECT_LINEAR;
	currentPlane = GL_OBJECT_PLANE;
	glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,currentGenMode);
	glTexGenfv(GL_S,currentPlane,currentCoeff);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_1D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);
	glFrontFace(GL_CW);
	glMaterialf(GL_FRONT,GL_SHININESS,64.0);
	roangles = 45.0f;
}

void display(GLvoid){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotated(roangles,0.0,0.0,1.0);
	//glutSolidSphere(2.0,32,32);
	glutSolidTeapot(3);
	glPopMatrix();
	glFlush();
}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glOrtho(-3.5,3.5,-3.5*(GLfloat)h/(GLfloat)w,3.5*(GLfloat)h/(GLfloat)w,-3.5,3.5);
	else
		glOrtho(-3.5*(GLfloat)w/(GLfloat)h,3.5*(GLfloat)w/(GLfloat)h,-3.5,3.5,-3.5,3.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void idle(){
	roangles += 0.05f;
	glutPostRedisplay();
}


int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(256,256);
	glutCreateWindow("Texture Mapping");
	glutIdleFunc(idle);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

