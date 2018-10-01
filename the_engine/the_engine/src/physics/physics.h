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
	glm::vec2 linea; //line pt1
	glm::vec2 lineb; //line pt2
	glm::vec2 linedist; //distance between pt1 and pt2
	glm::vec2 circ_pos_rel_line; //relative dist between circle pos and pt1
	glm::vec2 dist; // closest distance between circle pos and line segment

	//constructor
	physics();

	void update_position(float deltat);
	void reset(float new_x, float new_y, float new_vx, float new_vy, float new_ax, float new_ay);

};
