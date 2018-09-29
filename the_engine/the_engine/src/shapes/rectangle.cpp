#include "shapes.h"
#include <iostream>
// Creates a rectangle based on height and width parameters

Rectangle::Rectangle()
{
	r_width = 2.0f;
	r_height = 1.0f;
	this->vectors.pos.x = 0.0f;
	this->vectors.pos.y = 0.0f;
};

Rectangle::Rectangle(float width, float height, float x, float y) {
	//sets private width and height
	r_width = width;
	r_height = height;
	this->vectors.pos.x = x;
	this->vectors.pos.y = y;
};

void Rectangle::draw_rectangle() {
	//aspect ratio compensation
	float new_height = (r_height) / 2.0f;
	float new_width = (r_width / 1.667f) / 2.0f;

	//start drawing based on triangles
	glBegin( GL_TRIANGLES );

	glVertex2f(new_width + vectors.pos.x, new_height + vectors.pos.y);
	glVertex2f(-new_width + vectors.pos.x, new_height + vectors.pos.y);
	glVertex2f(new_width + vectors.pos.x, -new_height + vectors.pos.y);

	glVertex2f(-new_width + vectors.pos.x, new_height + vectors.pos.y);
	glVertex2f(new_width + vectors.pos.x, -new_height + vectors.pos.y);
	glVertex2f(-new_width + vectors.pos.x, -new_height + vectors.pos.y);
	//run program to get new position
	//vectors.update_position(deltat);
	std::cout << "new_height: " << new_height << std::endl;
	std::cout << "new_width: " << new_width << std::endl;
	glEnd();
}