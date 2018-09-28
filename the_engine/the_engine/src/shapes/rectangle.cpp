#include "shapes.h"
#include "../physics/physics.h"
// Creates a rectangle based on height and width parameters


physics Rect;

Rectangle::Rectangle(float width, float height) {
	//sets private width and height
	r_width = width;
	r_height = height;
};

void Rectangle::draw_rectangle(double deltat) {
	//initialize position to origin
	float x = 0, y = 0;
	//aspect ratio compensation
	float new_height = (r_height / 9) / 2;
	float new_width = (r_width / 16) / 2;

	//start drawing basedon triangles
	glBegin( GL_TRIANGLES );
	glVertex2f(new_width + Rect.pos.x, new_height + Rect.pos.y);
	glVertex2f(-new_width + Rect.pos.x, new_height + Rect.pos.y);
	glVertex2f(new_width + Rect.pos.x, -new_height + Rect.pos.y);

	glVertex2f(-new_width + Rect.pos.x, new_height + Rect.pos.y);
	glVertex2f(new_width + Rect.pos.x, -new_height + Rect.pos.y);
	glVertex2f(-new_width + Rect.pos.x, -new_height + Rect.pos.y);
	//run program to get new position
	Rect.update_position(deltat);
	glEnd();
}