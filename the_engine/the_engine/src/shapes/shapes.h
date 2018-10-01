#pragma once
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <Math.h>
#include "../physics/physics.h"

#define degree_radius 3.14159f / 180.0f;

class BaseShape {
public:
	//base_shape();
	physics vectors;
};

class Circle : public BaseShape
{
public:
	float mass = 1.0f;
	float radius;
	float x;
	float y;
	Circle();
	Circle(float radius, float x, float y, float mass);
	void drawCircle();
	//~Circle();
};

class Line : public BaseShape
{
public:
	float x_1 = 0.0f;
	float y_1 = 0.0f;
	float x_2 = 0.0f; 
	float y_2 = 0.0f;
	float x_3 = 0.0f;
	float y_3 = 0.0f;
	float x_4 = 0.0f;
	float y_4 = 0.0f;
	Line();
	Line(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	void drawline();
};

class Rectangle : public BaseShape {
private:
	float r_width, r_height;

public:
	Rectangle();
	Rectangle(float width, float height, float x, float y);
	void draw_rectangle();
};


// collision class definition
// This class inherits circle's radius and position
// This class inherits lines x and y axes
class Collision : public Circle, public Line {
public:
	float radius;
	float cx;
	float cy;
	float x1;
	float x2;
	float x3;
	float x4;
	float y1;
	float y2;
	float y3;
	float y4;
	Collision();
	Collision(float rad, float cirx, float ciry, float x_1, float y_1, float x_2, float y_2, float x_3, float y_3, float x_4, float y_4) :
		Circle(radius, x, y, mass), Line(x1, y1, x2, y2, x3, y3, x4, y4) 
	{}
	void circle_to_line();
};

//class Square : public Rectangle {
//
//public:
//	Square();
//	Square(float edge, float x, float y);
//};

class Triangle : public BaseShape {
private:
	float t_width, t_height;

public:
	Triangle(float width, float height);
	void create_triangle(double deltat);
};