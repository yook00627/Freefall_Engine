#include "shapes.h"

Circle::Circle()
{
	radius = 0.04f;
	this->vectors.pos.x = 0;
	this->vectors.pos.y = 0;
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
		glVertex2f(cos(degInRad)*this->radius / 1.7f + this->vectors.pos.y, sin(degInRad)*this->radius + this->vectors.pos.x);
	}
	glEnd();
}