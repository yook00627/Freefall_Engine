#include "physics.h"


physics::physics()
{
	accel = glm::vec2(0.0, 0.0);
	vel = glm::vec2(0.0, 0.0);
	pos = glm::vec2(0.0, 0.0);
};

void physics::update_position(float deltat)
{
	pos.x += vel.x * deltat + accel.x * (deltat * deltat) / 2;
	pos.y += vel.y * deltat + accel.y * (deltat * deltat) / 2;
	vel.x += accel.x * deltat;
	vel.y += accel.y * deltat;

	accel = glm::vec2(0.0, 0.0);
};

#if 0
bool AABBvsAABB(AABB a, AABB b)
{
	// Exit with no intersection if found separated along an axis
	if (a.max.x < b.min.x or a.min.x > b.max.x) return false;
	if (a.max.y < b.min.y or a.min.y > b.max.y) return false;

	// No separating axis found, therefor there is at least one overlapping axis
	return true;
}

float Distance(glm::vec2 a, glm::vec2 b)
{
	return sqrt((a.x - b.x) ^ 2 + (a.y - b.y) ^ 2);
}


bool CirclevsCircleOptimized(Circle a, Circle b)
{
	float r = a.radius + b.radius;
	r *= r;
	return r < (a.x + b.x) ^ 2 + (a.y + b.y) ^ 2;
}

void ResolveCollision(Object A, Object B)
{
	// Calculate relative velocity
	glm::vec2 rv = B.velocity - A.velocity

		// Calculate relative velocity in terms of the normal direction
		float velAlongNormal = DotProduct(rv, normal)

		// Do not resolve if velocities are separating
		if (velAlongNormal > 0)
			return;

	// Calculate restitution
	float e = min(A.restitution, B.restitution)

		// Calculate impulse scalar
		float j = -(1 + e) * velAlongNormal
		j /= 1 / A.mass + 1 / B.mass

		// Apply impulse
		Vec2 impulse = j * normal
		A.velocity -= 1 / A.mass * impulse
		B.velocity += 1 / B.mass * impulse
}

#endif