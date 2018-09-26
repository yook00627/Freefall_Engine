#include "shapes.h"
// Creates a rectangle based on height and width parameters

Rectangle::Rectangle(float width, float height) {
	r_width = width;
	r_height = height;
};

void Rectangle::Create_Rectangle() {
	float new_height = (r_height / 9) / 2;
	float new_width = (r_width / 16) / 2;

	glBegin(GL_TRIANGLES);
	glVertex2f(new_width, new_height);
	glVertex2f(-new_width, -new_height);
	glVertex2f(-new_width, new_height);
	glVertex2f(new_width, -new_height);
	glEnd();
}