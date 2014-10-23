// ColorTriangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>

void init(GLvoid){
	glClearColor(1.0,1.0,1.0,0.0);
	//设置着色模式  GL_FLAT:恒定 GL_SMOOTH: 光滑
//	glShadeModel(GL_SMOOTH);
	glShadeModel(GL_FLAT);
}

void triangle(GLvoid){
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f);glVertex2f(5.0f,5.0f);
		glColor3f(0.0f,1.0f,0.0f);glVertex2f(25.0f,5.0f);
		glColor3f(0.0f,0.0f,1.0f);glVertex2f(5.0f,25.0f);
	glEnd();
}

void display(GLvoid){
	glClear(GL_COLOR_BUFFER_BIT);
	triangle();
	glFlush();
}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w ,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		gluOrtho2D(0.0,30.0,0.0,30.0*(GLfloat)h/(GLfloat)w);//左下角x,右上角x,左下角y,右上角y
	else
		gluOrtho2D(0.0,30.0*(GLfloat)w/(GLfloat)h,0.0,30.0);
	glMatrixMode(GL_MODELVIEW);
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL 颜色函数");
	init();
	//注册窗口的显示回调函数
	//窗口改变大小或者从被覆盖状态恢复，或者由于调用glutPostRedisplay()函数要求glut更新时，执行func参数指定的函数
	//形参：void(*func)(void)
	glutDisplayFunc(display);
	//当窗口的大小改变时调用的函数（包括窗口第一次创建) 
	//形参：void func(int width,int height)
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

