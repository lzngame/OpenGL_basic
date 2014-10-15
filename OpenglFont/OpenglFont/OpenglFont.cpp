// OpenglFont.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
#include <Windows.h>
#define MAX_CHAR 128
void drawString(const char* str){
	static int isFirstCall = 1;
	static GLuint lists;
	if(isFirstCall){
		isFirstCall = 0;
		lists = glGenLists(MAX_CHAR);
		wglUseFontBitmaps(wglGetCurrentDC(),0,MAX_CHAR,lists);
	}
	for(;*str!='\0';++str)
		glCallList(lists+*str);
}

void drawCnSt(const char* str){
	int len,i;
	wchar_t* wstring;
	HDC hDc = wglGetCurrentDC();
	GLuint list = glGenLists(1);

	len = 0;
	for(i=0;str[i]!='\0';++i){
		if(IsDBCSLeadByte(str[i]))
			++i;
		++len;
	}
	wstring = (wchar_t*)malloc((len+1)*sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,str,-1,wstring,len);
	wstring[len] = L'\0';

	for(i=0;i<len;++i){
		wglUseFontBitmapsW(hDc,wstring[i],1,list);
		glCallList(list);
	}

	free(wstring);
	glDeleteLists(list,1);
}

void selectFont(int size,int charset,const char* face){
	HFONT hFont = CreateFontA(size,0,0,0,FW_MEDIUM,0,0,0,charset,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,face);
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(),hFont);
	DeleteObject(hOldFont);
}

void display(void){
	selectFont(48,ANSI_CHARSET,"Comic Sans MS");
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f);
	glRasterPos2f(0.0f,0.0f);
	drawString("Hello,World！");

	selectFont(48,GB2312_CHARSET,"楷体_GB2312");
	glColor3f(1.0f,1.0f,0.0f);
	glRasterPos2f(-0.7f,-0.31f);
	drawCnSt("OpenGL 汉字");
	glutSwapBuffers();
}

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}


	
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc,(char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL Font");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

