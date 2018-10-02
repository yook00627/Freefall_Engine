#include "physics.h"
#include <iostream>
#include "../shapes/shapes.h"

void physics::resolve_collision(Circle &a, Line &b)
{

	/*if (bottom)
	{
		float factor = 0.5f;
		a.vectors.vel.x = -a.vectors.vel.x * factor;
		a.vectors.vel.y = -a.vectors.vel.y * factor;
		a.vectors.pos.y += 0.05f;
		std::cout << a.vectors.vel.x << " " << a.vectors.vel.y << std::endl;

		if (a.vectors.vel.y <= 0.36f)
		{
			a.vectors.pos.y -= 0.05f;
			a.vectors.vel.x = 0.0f;
			a.vectors.vel.y = 0.0f;
			a.vectors.accel.y = 0.0f;
		}
	}
	else if (edge)
	{
		a.vectors.x = -a.vectors.x;
	}
	else
	{

	}*/
	//std::cout << "impulse catches" << std::endl;
	//glm::vec2 rel_vel = b.vectors.vel - a.vectors.vel;
	//std::cout <<"rel_vel"<< rel_vel.x << " " << rel_vel.y << std::endl;

	////a.norms.x /= a.norms.x;
	////a.norms.y /= a.norms.y;
	//std::cout << "norms" << a.norms.x << " " << a.norms.y << std::endl;
	//float norm = glm::dot(rel_vel, a.norms); 
	//std::cout << "norm" << norm << std::endl;

	//if (norm > 0)
	//	return;

	//float imp_scalar = -1 * norm;
	//imp_scalar /= 1 / a.mass;
	//std::cout << imp_scalar << std::endl;

	//glm::vec2 impulse = imp_scalar * b.vectors.pos;
	//std::cout << a.vectors.vel.x << " " << a.vectors.vel.y << std::endl;

	//impulse.x *= 1 / a.mass;
	//impulse.y *= 1 / a.mass;

	//a.vectors.vel.x -= impulse.x;
	//a.vectors.vel.y -= impulse.y;
	//a.vectors.pos.y += 0.05;
	//std::cout << a.vectors.vel.x << " " << a.vectors.vel.y << std::endl;
};