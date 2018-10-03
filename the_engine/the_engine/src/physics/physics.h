#pragma once
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../shapes/shapes.h"

#if 0
struct Circle
{
	float radius;
	glm::vec position;
};

struct AABB
{
	glm::vec2 min;
	glm::vec2 max;
};
#endif

class Circle;
class Line;
class Collision;
class physics {
public:
	glm::vec2 accel;
	glm::vec2 vel;
	glm::vec2 pos;
 
	//constructor
	physics();

	void update_position(float deltat);
	void reset(float new_x, float new_y, float new_vx, float new_vy, float new_ax, float new_ay);
	void resolve_collision(Circle &a, Line &b, Collision test);
};
