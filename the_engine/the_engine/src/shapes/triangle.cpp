#include "shapes.h"
// Creates a triangle based on height and width parameters

Triangle::Triangle(float width, float height) {
	t_width = width;
	t_height = height;
};

void Triangle::create_triangle(double deltat) {
	//aspect ratio compensation
	float new_height = (t_height / 9) / 2;
	float new_width = (t_width / 16) / 2;

	//start drawing based on triangles
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f + vectors.pos.x, new_height + vectors.pos.y);
	glVertex2f(-new_width + vectors.pos.x, -new_height + vectors.pos.y);
	glVertex2f(new_width + vectors.pos.x, -new_height + vectors.pos.y);
	//run program to get new position
	vectors.update_position(deltat);

	glEnd();
}