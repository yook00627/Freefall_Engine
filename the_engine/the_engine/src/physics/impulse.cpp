#include "physics.h"
#include <iostream>
#include "../shapes/shapes.h"

float calc_dist(float x1, float y1, float x2, float y2)
{
	float distancex = (x2 - x1) * (x2 - x1);
	float distancey = (y2 - y1) * (y2 - y1);

	float distance = sqrt(distancex - distancey);

	return (distance);
}

void physics::resolve_collision(Circle &a, Line &b, Collision &test)
{
	float factor = 0.5f;
	float distance = 0.0f;

	//deprecated code
	//if (test.bottom == true)
	//{
	//	std::cout << "Impulse bottom" << std::endl;
	//	a.vectors.vel.x = abs(a.vectors.vel.x * factor);
	//	a.vectors.vel.y = abs(a.vectors.vel.y * factor);
	//	//a.vectors.pos.y += 0.05f;
	//	std::cout << a.vectors.vel.x << " " << a.vectors.vel.y << std::endl;

	//	distance = (a.vectors.pos.y - a.radius) - test.closey;
	//	std::cout << "distance impulse " << distance << std::endl;
	//	std::cout << "closey " << test.closey << std::endl;
	//	if (distance <= 0.02f && a.vectors.vel.y <= 0.1f)
	//	{
	//		a.vectors.pos.y += 0.001f;
	//		a.vectors.vel.x = 0.0f;
	//		a.vectors.vel.y = 0.0f;
	//		a.vectors.accel.y = 0.0f;
	//	}
	//}
	//}
	//else if (test.left || test.right)
	//{
	//	std::cout << "Impulse left edge" << std::endl;
	//	a.vectors.vel.x = -a.vectors.vel.x * factor;
	//}
	//else
	//{
	//	std::cout << "Impulse point" << std::endl;
	//	a.vectors.vel.x = abs(a.vectors.vel.x * factor);
	//	a.vectors.vel.y = abs(a.vectors.vel.y * factor);

	//	if (a.vectors.vel.y <= 0.36f)
	//	{
	//		a.vectors.pos.y += 0.01f;
	//		a.vectors.vel.x = 0.0f;
	//		a.vectors.vel.y = 0.0f;
	//		a.vectors.accel.y = 0.0f;
	//	}
	//}
	if (test.bottom == true)
	{
		glm::vec2 rel_vel(b.vectors.vel.x - a.vectors.vel.x, b.vectors.vel.y - a.vectors.vel.y);

		float len4norm = sqrt(a.norms.x * a.norms.x + a.norms.y*a.norms.y);
		a.norms.x /= len4norm;
		a.norms.y /= len4norm;

		float norm = glm::dot(rel_vel, a.norms);

		//if (norm > 0)
		//	return;

		float imp_scalar = -1.6 * norm;
		imp_scalar /= a.mass;

		glm::vec2 impulse(a.norms.x * imp_scalar, a.norms.y * imp_scalar);

		float dist1 = calc_dist(a.vectors.pos.x, a.vectors.pos.y, b.x_1, b.y_1); //point 3
		float dist2 = calc_dist(a.vectors.pos.x, a.vectors.pos.y, b.x_2, b.y_2); //point 4
		if (dist1 < dist2)
		{
			a.vectors.vel.x -= (impulse.x * (1 / a.mass));
			a.vectors.vel.y -= (impulse.y * (1 / a.mass));
		}
		else
		{
			a.vectors.vel.x -= (impulse.x * (1 / a.mass));
			a.vectors.vel.y -= (impulse.y * (1 / a.mass));
		}

		if (abs(a.vectors.vel.y) < 0.04)
		{
			a.vectors.pos.y += 0.00001f;
			a.vectors.vel.x = 0.0f;
			a.vectors.vel.y = 0.0f;
			a.vectors.accel.y = 0.0f;
		}

		//if (dist1 <= 0.0001 || dist2 <= 0.0001)
		//{
		//	a.vectors.vel.x = 0.0f;
		//	a.vectors.vel.y = 0.0f;
		//	a.vectors.accel.y = 0.0f;
		//}
	}
}
