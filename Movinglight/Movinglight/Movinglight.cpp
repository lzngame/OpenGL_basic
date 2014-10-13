// Movinglight.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <gl/glut.h>

static int spin = 0;
void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void render(void){
	GLfloat light_position[] = {0.0,0.0,1.5,1.0};
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//将当前变换矩阵（单位阵）压入栈，如果忽略此句，则每次调用gluLookAt都将使物体缩小
	glPushMatrix();
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	//只对LIGHT0进行旋转，不影响SolidTorus
	glPushMatrix();
	glRotated(spin,1.0,0.0,0.0);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glPopMatrix();
	glutSolidTorus(0.275,0.85,8,15);
	glPopMatrix();
	glFlush();
}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button,int state,int x,int y){
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if(state == GLUT_DOWN){
			spin = (spin+30)%360;
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}

void keyboard(unsigned char key,int x,int y){
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Moving light");
	init();
	glutDisplayFunc(render);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

