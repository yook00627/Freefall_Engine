#include <iostream>
#include "physics.h"
#include "../shapes/shapes.h"

Collision::Collision()
{
	radius = 0.0f;
	cx = 0.0f;	cy = 0.0f;
	x1 = 0.0f; 	y1 = 0.0f;
	x2 = 0.0f;	y2 = 0.0f;
	x3 = 0.0f;	y3 = 0.0f;
	x4 = 0.0f;	y4 = 0.0f;

};
Collision::Collision(Circle &obj, Line &lobj)
{

}


bool Collision::lineCircle(Circle &obj, Line &lobj)
{

	// Check if edge inside the circle
	// return true
	cy = obj.vectors.pos.y;
	cx = obj.vectors.pos.x;
	radius = obj.radius;
	x1 = lobj.x_1;	y1 = lobj.y_1;
	x2 = lobj.x_2;	y2 = lobj.y_2;
	x3 = lobj.x_3;	y3 = lobj.y_3;
	x4 = lobj.x_4;	y4 = lobj.y_4;

	//std::cout << "y in collision" << cy << std::endl;
	bool inside1 = pointCircle(x1, y1, cx, cy, radius);
	bool inside2 = pointCircle(x2, y2, cx, cy, radius);

	if (inside1 || inside2)
	{
		std::cout << "inside1 " << inside1 << std::endl;
		std::cout << "inside2" << inside2 << std::endl;
		std::cout << "edge collision detected" << std::endl
		glm::vec2 normal = glm::vec2(cx - closestX, cy - closestY);
		obj.norms = normal;
		return (true);
	}

	//segv =  seg_b - seg_b
	//distance between 2 pts bottom
	float linedistx = x1 - x2;
	float linedisty = y1 - y2;

	float len = sqrt((linedistx * linedistx) + (linedisty * linedisty));

	//getting dot product between the line and the circle to find the closest
	// point to the circle's center on the line segment
	float dot = (((cx - x1)*(x2 - x1)) + ((cy - y1)*(y2 - y1))) / pow(len, 2);
	float closestX = x1 + (dot * (x2 - x1));
	float closestY = y1 + (dot * (y2 - y1));

	//function call to check if the point is on the line segment
	bool onSegment = linePoint(x1, y1, x2, y2, closestX, closestY);

	if (!onSegment)
		return false;

	// get distance to the closest pt
	linedistx = closestX - cx;
	linedisty = closestY - cy;
	float distance = sqrt((linedistx * linedistx) + (linedisty * linedisty));
	
	if (distance <= radius)
	{
		std::cout << "this is hitting" << std::endl;
		return true;
	}
	return false;
}


bool Collision::linePoint(float x1, float y1, float x2, float y2, float closeX, float closeY)
{
	
	// get distance from the point to the two ends of the line
	float d1 = dist(closeX, closeY, x1, y1);
	float d2 = dist(closeX, closeY, x2, y2);
	
	// get the length of the line
	float lineLen = dist(x1, y1, x2, y2);
	
	// since floats are so minutely accurate, add
	// a little buffer zone that will give collision
	float buffer = 0.1;    // higher # = less accurate
	
	// if the two distances are equal to the line's length, the
	// point is on the line!
	// note we use the buffer here to give a range, rather than one #
	if (d1 + d2 >= lineLen - buffer && d1 + d2 <= lineLen + buffer) 
	{
		return true;
	}
	return false;
}

float Collision::dist(float x, float y, float x1, float y1)
{
	float distancex = (x1 - x) * (x1 - x);
	float distancey = (y1 - y) * (y1 - y);

	float distance = sqrt(distancex - distancey);

	return (distance);
}


// finding the distance between the point and the circle
bool Collision::pointCircle(float px, float py, float cx, float cy, float r) 
{
	
		//get distance between the point and circle's center
		// using the Pythagorean Theorem
		float distX = px - cx;
		float distY = py - cy;
		float distance = sqrt((distX*distX) + (distY*distY));
	
		//if the distance is less than the circle's 
		//radius the point is inside!
		if (distance <= r) 
		{
			//std::cout << "collided" << std::endl;
			return true;
		}
		return false;
}

