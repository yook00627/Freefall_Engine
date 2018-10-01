#include <iostream>
#include "physics.h"
#include "../shapes/shapes.h"

Collision::Collision()
{
};
Collision::Collision(float rad, float cirx, float ciry, float x_1, float y_1, float x_2, float y_2, float x_3, float y_3, float x_4, float y_4)
{
	radius = rad;
	cx = cirx;
	cy = ciry;
	x1 = x_1;
	y1 = y_1;
	x2 = x_2;
	y2 = y_2;
	x3 = x_3;
	y3 = y_3;
	x4 = x_4;
	y4 = y_4;
}



bool lineCircle(float x1, float y1, float x2, float y2, float cx, float cy, float r) {

	// is either end INSIDE the circle?
	// if so, return true immediately
	bool inside1 = pointCircle(x1, y1, cx, cy, r);
	bool inside2 = pointCircle(x2, y2, cx, cy, r);
	if (inside1 || inside2) return true;

	// get length of the line
	float distX = x1 - x2;
	float distY = y1 - y2;
	float len = sqrt((distX*distX) + (distY*distY));

	// get dot product of the line and circle
	float dot = (((cx - x1)*(x2 - x1)) + ((cy - y1)*(y2 - y1))) / pow(len, 2);

	// find the closest point on the line
	float closestX = x1 + (dot * (x2 - x1));
	float closestY = y1 + (dot * (y2 - y1));

	// is this point actually on the line segment?
	// if so keep going, but if not, return false
	bool onSegment = linePoint(x1, y1, x2, y2, closestX, closestY);
	if (!onSegment) return false;

	// optionally, draw a circle at the closest point on the line
	//fill(255, 0, 0);
	//noStroke();
	//ellipse(closestX, closestY, 20, 20);

	// get distance to closest point
	distX = closestX - cx;
	distY = closestY - cy;
	float distance = sqrt((distX*distX) + (distY*distY));

	if (distance <= r) {
		return true;
	}
	return false;
}


// LINE/POINT
bool linePoint(float x1, float y1, float x2, float y2, float px, float py) {

	// get distance from the point to the two ends of the line
	float d1 = (px, py, x1, y1);
	float d2 = (px, py, x2, y2);

	// get the length of the line
	float lineLen = (x1, y1, x2, y2);

	// since floats are so minutely accurate, add
	// a little buffer zone that will give collision
	float buffer = 0.1;    // higher # = less accurate

	// if the two distances are equal to the line's length, the
	// point is on the line!
	// note we use the buffer here to give a range, rather than one #
	if (d1 + d2 >= lineLen - buffer && d1 + d2 <= lineLen + buffer) {
		return true;
	}
	return false;
}


// POINT/CIRCLE
bool pointCircle(float px, float py, float cx, float cy, float r) {

	// get distance between the point and circle's center
	// using the Pythagorean Theorem
	float distX = px - cx;
	float distY = py - cy;
	float distance = sqrt((distX*distX) + (distY*distY));

	// if the distance is less than the circle's 
	// radius the point is inside!
	if (distance <= r) {
		return true;
	}
	return false;
}


//#include <math.h>
//
////collision::collision
//
//
//float cx, cy; // circle position
//float rad; //circle rad
//float linex1;
//float linex2; //line left coordinates
//float liney1;//line right coordinates
//float liney2;
//bool lineCircle(float cx, float cy, float rad, float linex1, float liney1, float linex2, float liney2)
//{
//	bool inside1 = pointCircle(linex1, liney1, cx, cy, rad);
//	bool inside2 = pointCircle(linex2, liney2, cx, cy, rad);
//
//	if (inside1 || inside2)
//		return (true);
//
//	float distx = linex1 - linex2;
//	float disty = liney1 - liney2;
//
//	float len = sqrt((distx*distx) + (disty*disty));
//	float dot = (cx - linex1) * (linex2 - linex1) + (cy - liney1) * (liney2 - liney1) / pow(len, 2);
//	
//	float closestX = linex1 + (dot * (linex2 - linex1));
//	float closestY = liney1 + (dot * (liney2 - liney1));
//
//	bool check = linePoint(linex1, liney1, linex2, liney2, closestX, closestY);
//
//	if (!check)
//		return (false);
//
//	distx = closestX - cx;
//	disty = closestY - cy;
//
//	float distance = sqrt((distx * distx) + (disty * disty));
//	if (distance <= rad)
//		return (true);
//	return (false);
//}
//
//bool linePoint(float x1, float y1, float x2, float y2, float px, float py)
//{
//	float distx = px - x1;
//	float disty = py - y1;
//	float distx2 = px - x2;
//	float disty2 = py - y2;
//
//	
//
//	float buffer = 5.0f;
//
//	if ()
//}


//nclude "physics.h