#include "physics.h"

physics::physics()
{
	accel = glm::vec2(0.0f,-9.8f);
	vel = glm::vec2(0.0f, 0.0f);
	pos = glm::vec2(0.0f, 0.0f);
};

void physics::update_position(float deltat)
{
	if (deltat > 0.016)
	{
		deltat = (float)0.016;
	};
	//deltat *= 1000;

	//update new position based on current velocity and acceleration vector
	pos.x += vel.x * deltat + (accel.x * (deltat * deltat) / 2.0f);
	pos.y += vel.y * deltat + (accel.y * (deltat * deltat) / 2.0f);
	//update new velocity based on acceleration
	vel.x += accel.x * deltat;
	vel.y += accel.y * deltat;
	//reset acceleration due to recalculation of new acceleration 
	//accel = glm::vec2(0.0, 0.0);
};

