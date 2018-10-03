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
	glm::vec2 norms;
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
class Collision {
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
	float closex;
	float closey;
	float closexl;
	float closeyl;
	float closexr;
	float closeyr;
	Collision();
	Collision(Circle &obj, Line &lobj);
	bool lineCircle(Circle &obj, Line &lobj);
	bool linePoint(float x1, float y1, float x2, float y2, float closeX, float closeY);
	float dist(float x, float y, float x1, float y1);
	bool pointCircle(float px, float py, float cx, float cy, float r);
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
	void create_triangle(float deltat);
};