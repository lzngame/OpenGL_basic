// DrawSphere.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
#include <math.h>
#define PI 3.14159
#define M_PI 3.14159
void drawColorSphere(float r,int segs){
	int i,j;
	float x,y,z,z1,z2,R,R1,R2;
	glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0,0,1);
		glColor3f(0.5,0.5,1);
		glVertex3f(0,0,r);
		z = cos(PI/segs);
		R = sin(PI/segs);
		for(i=0;i<=2*segs;i++){
			x = R*cos(i*2.0*PI/(2*segs));
			y = R*sin(i*2.0*PI/(2*segs));
			glNormal3f(x,y,z);
			glColor3f(0.5*(x+1),0.5*(y+1),0.5*(z+1));
			glVertex3f(r*x,r*y,r*z);
		}
	glEnd();

	for(j=1;j<segs-1;j++){
		z1=cos(j*PI/segs);
		R1=sin(j*PI/segs);
		z2=cos((j+1)*PI/segs);
		R2=sin((j+1)*PI/segs);
		glBegin(GL_TRIANGLE_STRIP);
			for(i=0;i<2*segs;i++){
				x=R1*cos(i*2.0*PI/(2*segs));
				y=R1*sin(i*2.0*PI/(2*segs));
				glNormal3f(x,y,z1);
				glColor3f(0.5*(x+1),0.5*(y+1),0.5*(z1+1));
				glVertex3f(r*x,r*y,r*z1);
			}
		glEnd();
	}

	glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0,0,-1);
			glColor3f(0.5,0.5,0);
			glVertex3f(0,0,-r);
			z=-cos(PI/segs);
			R=sin(PI/segs);
			for(i=2*segs;i>=0;i--){
				x = R*cos(i*2.0*PI/(2*segs));
				y = R*sin(i*2.0*PI/(2*segs));
				glNormal3f(x,y,z);
				glColor3f(0.5*(x+1),0.5*(y+1),0.5*(z+1));
				glVertex3f(r*x,r*y,r*z);
			}
	glEnd();
}

void drawColorSphere2(float r, int segs) {
 int i, j;
 float x, y, z, z1, z2, R, R1, R2;
 
 // Top cap: a triangle fan
 glBegin(GL_TRIANGLE_FAN);
 glNormal3f(0,0,1);
 glColor3f(0.5,0.5,1);
 glVertex3f(0,0,r);
 z = cos(M_PI/segs);
 R = sin(M_PI/segs);
    for(i = 0; i <= 2*segs; i++) {
  x = R*cos(i*2.0*M_PI/(2*segs));
  y = R*sin(i*2.0*M_PI/(2*segs));
  glNormal3f(x, y, z);
  glColor3f(0.5*(x+1), 0.5*(y+1), 0.5*(z+1));
  glVertex3f(r*x, r*y, r*z);
    }
 glEnd();  
 
 // Height segments: each a triangle strip
 for(j = 1; j < segs-1; j++) {
  z1 = cos(j*M_PI/segs);
  R1 = sin(j*M_PI/segs);
  z2 = cos((j+1)*M_PI/segs);
  R2 = sin((j+1)*M_PI/segs);
  glBegin(GL_TRIANGLE_STRIP);
  for(i = 0; i <= 2*segs; i++) {
   x = R1*cos(i*2.0*M_PI/(2*segs));
   y = R1*sin(i*2.0*M_PI/(2*segs));
   glNormal3f(x, y, z1);
   glColor3f(0.5*(x+1), 0.5*(y+1), 0.5*(z1+1));
   glVertex3f(r*x, r*y, r*z1);
   x = R2*cos(i*2.0*M_PI/(2*segs));
   y = R2*sin(i*2.0*M_PI/(2*segs));
   glNormal3f(x, y, z2);
   glColor3f(0.5*(x+1), 0.5*(y+1), 0.5*(z2+1));
   glVertex3f(r*x, r*y, r*z2);
  }
  glEnd();
 }
 
 // Bottom cap: a triangle fan
 glBegin(GL_TRIANGLE_FAN);
 glNormal3f(0,0,-1);
 glColor3f(0.5,0.5,0);
 glVertex3f(0,0,-r);
 z = -cos(M_PI/segs);
 R = sin(M_PI/segs);
    for(i = 2*segs; i >= 0; i--) {
  x = R*cos(i*2.0*M_PI/(2*segs));
  y = R*sin(i*2.0*M_PI/(2*segs));
  glNormal3f(x, y, z);
  glColor3f(0.5*(x+1), 0.5*(y+1), 0.5*(z+1));
  glVertex3f(r*x, r*y, r*z);
    }
 glEnd();
}


void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	drawColorSphere2(0.8,30);
	glutSwapBuffers();
}

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}



int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Draw Sphere");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

