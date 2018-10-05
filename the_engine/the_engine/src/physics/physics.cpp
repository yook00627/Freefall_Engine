#include "physics.h"
#include <iostream>

//default constructor
physics::physics()
{
	accel = glm::vec2(0.0f, 0.0f);
	vel = glm::vec2(0.0f, 0.0f);
	pos = glm::vec2(0.0f, 0.0f);
};

//calculates new position based on current velocity and acceleration and updates velocity and acceleration
void physics::update_position(float deltat)
{
	if (deltat > 0.016f)
	{
		deltat = 0.016f;
	};
	//deltat *= 1000;

	//update new position based on current velocity and acceleration vector
	pos.x += vel.x * deltat + (accel.x * (deltat * deltat) / 2.0f);
	//std::cout << "physics pos y" << pos.y << std::endl;
	pos.y += vel.y * deltat + (accel.y * (deltat * deltat) / 2.0f);
	//update new velocity based on acceleration
	vel.x += accel.x * deltat;
	vel.y += accel.y * deltat;
	//reset acceleration due to recalculation of new acceleration 
	//accel = glm::vec2(0.0, 0.0);
};

//how to change the position, velocity, and acceleration parameters
void physics::reset(float new_x, float new_y, float new_vx, float new_vy, float new_ax, float new_ay)
{
	pos.x = new_x;
	pos.y = new_y;
	vel.x = new_vx;
	vel.y = new_vy;
	accel.x = new_ax;
	accel.y = new_ay;
};
