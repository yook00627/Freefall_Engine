#pragma once
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <Math.h>
#include "../physics/physics.h"

#define degree_radius 3.14159f / 180.0f;
//void drawCircle(float radius);

class BaseShape {
public:
	//base_shape();
	physics vectors;
};

class Triangle : public BaseShape {
private:
	float t_width, t_height;

public:
	Triangle(float width, float height);
	void create_triangle(double deltat);
};

class Circle : public BaseShape
{
public:
	float mass = 1.0f;
	float radius;
	Circle();
	Circle(float radius, float x, float y, float mass);
	void drawCircle();
	~Circle();
};

class Rectangle : public BaseShape {
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