#include "shapes.h"

Circle::Circle()
{
	radius = 0.04f;
	this->vectors.pos.x = 0f;
	this->vectors.pos.y = 0f;
};

Circle::Circle(float rad, float x, float y)
{
	radius = rad;
	this->vectors.pos.x = x;
	this->vectors.pos.y = y;
}


void Circle::drawCircle()
{

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * degree_radius;
		glVertex2f(cos(degInRad)*radius / 1.7f + vectors.pos.x, sin(degInRad)*radius + vectors.pos.y);
	}
	glEnd();
}