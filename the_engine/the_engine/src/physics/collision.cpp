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


	//BOTTOM LINE TESTING

	//bool inside1 = pointCircle(x1, y1, cx, cy, radius);
	//bool inside2 = pointCircle(x2, y2, cx, cy, radius);

	//LEFT LINE TOP TESTING
	bool inside3 = pointCircle(x3, y3, cx, cy, radius);

	//RIGHT LINE TOP TESTING
	bool inside4 = pointCircle(x4, y4, cx, cy, radius);

	if (inside3 || inside4)
	{
		glm::vec2 normal;
		if (inside3 == true)
			normal = glm::vec2(cx - x1, cy - y1);
		else
			normal = glm::vec2(cx - x2, cy - y2);
		return true;
	}

	//segv =  seg_b - seg_b
	//distance between 2 pts bottom
	float linedistx = x1 - x2;
	float linedisty = y1 - y2;

	float linedistxl = x1 - x3;
	float linedistyl = y1 - y3;

	float linedistxr = x2 - x4;
	float linedistyr = y2 - y4;

	//left line distance
	float lenl = sqrt((linedistxl * linedistxl) + (linedistyl * linedistyl));

	//right line distance
	float lenr = sqrt((linedistxr * linedistxr) + (linedistyr * linedistyr));

	//bottom line distance
	float len = sqrt((linedistx * linedistx) + (linedisty * linedisty));

	//getting dot product between the line and the circle to find the closest
	// point to the circle's center on the line segment
	float dot = (((cx - x1)*(x2 - x1)) + ((cy - y1)*(y2 - y1))) / pow(len, 2);
	float closestX = x1 + (dot * (x2 - x1));
	float closestY = y1 + (dot * (y2 - y1));
	closex = closestX;
	closey = closestY;

	//line left
	float dotl = (((cx - x1) * (x3 - x1)) + ((cy - y1) * (y3 - y1))) / pow(len, 2);
	float closestXl = x1 + (dotl * (x3 - x1));
	float closestYl = y1 + (dotl * (y3 - y1));
	closexl = closestXl;
	closexl = closestYl;

	//line right
	float dotr = (((cx - x2) * (x4 - x2)) + ((cy - y2) * (y4 - y2))) / pow(len, 2);
	float closestXr = x2 + (dotr * (x4 - x2));
	float closestYr = y2 + (dotr * (y4 - y2));
	closexr = closestXr;
	closeyr = closestYr;

	//function call to check if the point is on the line segment
	bool onSegment = linePoint(x1, y1, x2, y2, closestX, closestY);
	bool onSegmentl = linePoint(x1, y1, x3, y3, closestXl, closestYl);
	bool onSegmentr = linePoint(x2, y2, x4, y4, closestXr, closestYr);
	if (onSegment == false && onSegmentl == false && onSegmentr == false)
		return false;
	

	// get distance to the closest pt
	linedistx = closestX - cx;
	linedisty = closestY - cy;

	linedistxl = closestXl - cx;
	linedistyl = closestYl - cy;

	linedistxr = closestXr - cx;
	linedistyr = closestYr - cy;


	float distance = sqrt((linedistx * linedistx) + (linedisty * linedisty));
	float distancel = sqrt((linedistxl * linedistxl) + (linedistyl * linedistyl));
	float distancer = sqrt((linedistxr * linedistxr) + (linedistyr * linedistyr));

	if (distance <= radius && (distance - radius == 0 && distancel - radius != 0 && distancer - radius != 0))
	{
		std::cout << "this is hitting" << std::endl;
		right = false;
		left = false;
		bottom = true;
		return true;
	}
	else if (distancel <= radius && (distancel - radius == 0 && distance - radius != 0 && distancer - radius != 0))
	{
		left = true;
		right = false;
		bottom = false;
		std::cout << "hitting left" << std::endl;
		return true;
	}
	else if (distancer <= radius && (distancer - radius == 0 && distancel - radius != 0 && distance - radius != 0))
	{
		bottom = false;
		left = false;
		right = true;
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
	//float buffer = 0.01f;    // higher # = less accurate
	
	// if the two distances are equal to the line's length, the
	// point is on the line!
	// note we use the buffer here to give a range, rather than one #
	if (d1 + d2 >= lineLen /*- buffer*/ && d1 + d2 <= lineLen /*+ buffer*/) 
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
			return true;
		}
		return false;
}

