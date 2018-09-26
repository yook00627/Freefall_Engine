#include "shapes.h"
// Creates a triangle based on height and width parameters

Triangle::Triangle(float width, float height) {
	t_width = width;
	t_height = height;
};

void Triangle::Create_Triangle() {
	float new_height = (t_height / 9) / 2;
	float new_width = (t_width / 16) / 2;

	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, new_height);
	glVertex2f(-new_width, -new_height);
	glVertex2f(new_width, -new_height);
	glEnd();
}