#pragma once
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <Math.h>
#include "../physics/physics.h"

#define degree_radius 3.14159f / 180;
//void drawCircle(float radius);

class base_shape {
public:
	//base_shape();
	physics vectors;
};

class Triangle : public base_shape {
private:
	float t_width, t_height;

public:
	Triangle(float width, float height);
	void create_triangle(double deltat);
};

class Circle : public base_shape
{
public:
	float radius;
	Circle();
	Circle(float radius, float x, float y);
	void drawCircle();
};

class Rectangle : public base_shape {
private:
	float r_width, r_height;

public:
	Rectangle();
	Rectangle(float width, float height, float x, float y);
	void draw_rectangle();
};

class Square : public Rectangle {

public:
	Square();
	Square(float edge, float x, float y);
};