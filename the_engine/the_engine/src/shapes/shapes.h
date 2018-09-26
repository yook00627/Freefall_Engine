#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Math.h>

void drawcircle(float radius, int sides);

class Triangle {
private:
	float t_width, t_height;

public:
	Triangle(float width, float height);
	void create_triangle();
};

class Rectangle {
private:
	float r_width, r_height;

public:
	Rectangle(float width, float height);
	void draw_rectangle();
};

class Square : public Rectangle {

public:
	Square(float edge);
};