#include "physics.h"

void physics::resolve_collision(Circle a, Circle b)
{
	glm::vec2 rel_vel = b.vectors.vel - a.vectors.vel;

	float norm = glm::dot(rel_vel, b.vectors.pos); // CHANGE b to normal of edge at impact

	if (norm > 0)
		return;

	float imp_scalar = -1 * norm;
	imp_scalar /= 1 / a.mass + 1 / b.mass;

	glm::vec2 impulse = imp_scalar * b.vectors.pos;


};