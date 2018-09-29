#include "shapes.h"


void drawCircle(float radius)
{

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 360; i++)
	{
		float degInRad = i * degree_radius;
		glVertex2f(cos(degInRad)*radius / 1.7f + .3f, sin(degInRad)*radius + .3f);
	}
	glEnd();
}