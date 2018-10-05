#pragma once

#include <glew/glew.h>


//fucntion to print 'PRESS ENTER' on screen
void print_enter(int fontsize, float x, float y)
{

	float centerx = x;
	float centery = y;
	float size = (float)fontsize;
	float s = 0.07f;
	float space;
	glLineWidth(5);
	glColor3f(1.0f, 1.0f, 1.0f);

	//P
	space = s * 0;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//R
	space = s * 1;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
 	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//E
	space = s * 2;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//S
	space = s * 3;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//S
	space = s * 4;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//space

	//E
	space = s * 6;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//N
	space = s * 7;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//T
	space = s * 8;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.005f * size + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.005f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//E
	space = s * 9;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//R
	space = s * 10;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
}

//fucntion to print 'TRIES=' on screen
void print_tries(int fontsize, float x, float y, int tries)
{
	float centerx = x;
	float centery = y;
	float size = (float)fontsize;
	float s = 0.06f;
	float space;
	glLineWidth(3);
	glColor3f(1.0f, 1.0f, 1.0f);

	//T
	space = s * 0;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.005f * size + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.005f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//R
	space = s * 1;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//I
	space = s * 2;
	glBegin(GL_LINES);
	glVertex2f((0.005f * size + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.005f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//E
	space = s * 3;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//S
	space = s * 4;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//=
	space = s * 5;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.005f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.005f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.015f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.015f * size + centery);
	glEnd();

	for (int x = 0; x < tries; x++)
	{
		//I
		space = s * 6 + (0.03f * x);
		glBegin(GL_LINES);
		glVertex2f((0.005f * size + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.005f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
	}
}

//fucntion to print 'LEVEL=' on screen
void print_level(int fontsize, float x, float y, int level)
{
	float centerx = x;
	float centery = y;
	float size = (float)fontsize;
	float s = 0.06f;
	float space;
	glLineWidth(3);
	glColor3f(1.0f, 1.0f, 1.0f);

	//L
	space = s * 0;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//E
	space = s * 1;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//V
	space = s * 2;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.005f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.005f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();

	//E
	space = s * 3;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//L
	space = s * 4;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
	glEnd();

	//=
	space = s * 5;
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.005f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.005f * size + centery);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f((0.0f + space + centerx) / 1.7f, -0.015f * size + centery);
	glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.015f * size + centery);
	glEnd();

	if (level == 1)
	{
		space = s * 6;
		glBegin(GL_LINES);
		glVertex2f((0.005f * size + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.005f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
	}
	else if (level == 2)
	{
		space = s * 6;
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
	}
	else if (level == 3)
	{
		space = s * 6;
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
	}
	else if (level == 4)
	{
		space = s * 6;
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.01f * size + centery);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.01f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
	}
	else if (level == 0)
	{
		//L
		space = s * 6;
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
		//O
		space = s * 7;
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, 0.0f + centery);
		glEnd();
		//L
		space = s * 8;
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, 0.0f + centery);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f((0.0f + space + centerx) / 1.7f, -0.02f * size + centery);
		glVertex2f((0.01f * size + space + centerx) / 1.7f, -0.02f * size + centery);
		glEnd();
	}
}
