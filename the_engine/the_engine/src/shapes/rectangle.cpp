#include "shapes.h"
#include "../physics/physics.h"
#include <iostream>
// Creates a rectangle based on height and width parameters


physics Rect;

Rectangle::Rectangle(float width, float height) {
	r_width = width;
	r_height = height;
};

void Rectangle::draw_rectangle() {
	double x = 0, y = 0;
	double new_height = (r_height / 9) / 2;
	double new_width = (r_width / 16) / 2;

	glBegin( GL_TRIANGLES );
	glVertex2f(new_width + Rect.pos.x, new_height + Rect.pos.y);
	glVertex2f(-new_width + Rect.pos.x, new_height + Rect.pos.y);
	glVertex2f(new_width + Rect.pos.x, -new_height + Rect.pos.y);

	glVertex2f(-new_width + Rect.pos.x, new_height + Rect.pos.y);
	glVertex2f(new_width + Rect.pos.x, -new_height + Rect.pos.y);
	glVertex2f(-new_width + Rect.pos.x, -new_height + Rect.pos.y);
	Rect.update_position(0.90);
	std::cout << "x postion: " << Rect.pos.r << " y position: " << y << Rect.pos.y << std::endl;
	glEnd();
}