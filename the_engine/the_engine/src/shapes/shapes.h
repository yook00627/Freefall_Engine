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
	void Create_Triangle();
};