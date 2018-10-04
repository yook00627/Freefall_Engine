#include "shapes.h"

Line::Line()
{

};

Line::Line(float x1, float y1, float x2, float y2/*, float x3, float y3, float x4, float y4*/)
{
	x_1 = x1;
	y_1 = y1;
	x_2 = x2;
	y_2 = y2;
	//x_3 = x3;
	//y_3 = y3;
	//x_4 = x4;
	//y_4 = y4;
}


void Line::drawline()
{
	//bottom
	glBegin(GL_LINES);
	glVertex2f(x_1, y_1); //x1, y1
	glVertex2f(x_2, y_2); //x2, y2
	glEnd();

	////left
	//glBegin(GL_LINES);
	//glVertex2f(x_1, y_1); //x1, y1
	//glVertex2f(x_3, y_3); //x3, y3
	//glEnd();

	////right
	//glBegin(GL_LINES);
	//glVertex2f(x_2, y_2); //x2, y2
	//glVertex2f(x_4, y_4); //x4, y4
	//glEnd();
}