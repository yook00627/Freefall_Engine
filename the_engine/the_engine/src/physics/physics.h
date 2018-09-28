#pragma once
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

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
class physics {
public:
	glm::vec2 accel;
	glm::vec2 vel;
	glm::vec2 pos;
	//constructor
	physics();

	void update_position(float deltat);

};
