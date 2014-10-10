// InitGlut.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl\glut.h>
#include <iostream>
void render(void){
	//清除上次显示结果，每次绘制前调用
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,1.0,0.0,0.0);
	//世界窗口以当前窗口中点为原点，向右为+x轴，向上为+y轴
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,1.0,1.0);
		glVertex3f(1.0,1.0,1.0);
		glVertex3f(-0.5,0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
	glEnd();
	//glFlush();//和单缓冲GLUT_SINGLE 配合使用
	glutSwapBuffers();//和双缓冲GLUT_DOUBLE 配合使用
	std::cout<<"glutSwapBuffers() ---- GLUT_DOUBLE\n";
}
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	//glutInitDisplayMode(GLUT_DEPTH|GLUT_SINGLE|GLUT_RGBA);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowPosition(-1,-1);
	//实现的是比例缩放
	glutInitWindowSize(400,400);
	glutCreateWindow("OpenGL-glutInit()");
	glutDisplayFunc(render);//寄存回调
	glutMainLoop();
	return 0;
}

