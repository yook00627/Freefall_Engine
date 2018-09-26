#include "shapes.h"

void drawcircle(float radius, int sides)
{

	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	float twopi = (2.0f * 3.14159265358979f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);

	for (int i = 0; i <= 360; i++)
	{
		glVertex2f((radius / 1.7f)*cosf(i*twopi / sides), radius *sinf((i*twopi) / sides ));
	}
	glEnd();
	//glFlush();

}
 
