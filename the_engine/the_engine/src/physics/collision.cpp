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
	/*x3 = lobj.x_3;	y3 = lobj.y_3;
	x4 = lobj.x_4;	y4 = lobj.y_4;*/


	//Checking if either end at top is inside the circle, return true immediately
	/*bool inside3 = pointCircle(x3, y3, cx, cy, radius);
	bool inside4 = pointCircle(x4, y4, cx, cy, radius);

	if (inside3 || inside4)
	{
		glm::vec2 normal;
		if (inside3 == true)
			normal = glm::vec2(cx - x3, cy - y3);
		else
			normal = glm::vec2(cx - x4, cy - y4);
		return true;
	}*/
	bool inside1 = pointCircle(x1, y1, cx, cy, radius);
	bool inside2 = pointCircle(x2, y2, cx, cy, radius);
	float left = cx - x1;
	float right = cx - x2;
	glm::vec2 normal(0.0f, 0.0f);
	if (inside1 || inside2)
	{
		if (inside1 == true)
		{
			normal = glm::vec2(left, cy - y1);
		}
		//	if (left <= 0)
		//		normal = glm::vec2(left, abs(cy - y1));
		//	else
		//		normal = glm::vec2(-left, abs(cy - y1));
		else
			//	if (right >= 0)
		{
			normal = glm::vec2(right, cy - y2);
		}
		//	else
		//		normal = glm::vec2(-right, abs(cy - y2));
		obj.norms = normal;
		bottom = true;
		return true;
	}
	//get lengths of the bottom line
	float distbottomx = x1 - x2;
	float distbottomy = y1 - y2;
	float lenbottom = sqrt((distbottomx*distbottomx) + (distbottomy*distbottomy));

	////get length of the left line
	//float distleftx = x3 - x1;
	//float distlefty = y3 - y1;
	//float lenleft = sqrt((distleftx*distleftx) + (distlefty * distlefty));

	////get length of the right line
	//float distrightx = x4 - x2;
	//float distrighty = y4 - y2;
	//float lenright = sqrt((distrightx*distrightx) + (distrighty * distrighty));

	//dot product of bottom line and circle
	float dotb = (((cx - x1)*(x2 - x1)) + ((cy - y1)*(y2 - y1))) / pow(lenbottom, 2);

	////dot product of bottom left and circle
	//float dotl = (((cx - x1)*(x3 - x1)) + ((cy - y1)*(y3 - y1))) / pow(lenleft, 2);

	////dot product of bottom right and circle
	//float dotr = (((cx - x4)*(x2 - x4)) + ((cy - y4)*(y2 - y4))) / pow(lenright, 2);

	//find closest point on the bottom line
	float cbx = x1 + (dotb * (x2 - x1));
	float cby = y1 + (dotb * (y2 - y1));
	closex = cbx;
	closey = cby;


	float mid = cx - closex;
	normal = glm::vec2(abs(mid), abs(cy - closey));
	obj.norms = normal;

	////find closest point on the left line
	//float clx = x1 + (dotb * (x3 - x1));
	//float cly = y1 + (dotb * (y3 - y1));
	//closexl = clx;
	//closeyl = cly;

	////find closest point on the right line
	//float crx = x4 + (dotb * (x2 - x4));
	//float cry = y4 + (dotb * (y2 - y4));
	//closexr = crx;
	//closeyr = cry;

	//Check if the closest point is on the line segment if yes keep true else false
	bool onSegb = linePoint(x1, y1, x2, y2, cbx, cby);
	/*bool onSegl = false;
	onSegl = linePoint(x1, y1, x3, y3, clx, cly);
	bool onSegr = false;
	onSegr = linePoint(x4, y4, x2, y2, crx, cry);*/
	if (!onSegb)
	{
		return false;
		/*std::cout << "not near bottom " << onSegb << std::endl;
		if (onSegl == false)
		{
			std::cout << "not near left " << onSegl << std::endl;
			if (onSegr == false)
			{*/
		/*		std::cout << "not near right " << onSegr << std::endl;*/
			/*}
		}*/
	}

	//getting distance to the closest point on the line segment to the circle

	//bottom
	distbottomx = cbx - cx;
	distbottomy = cby - cy;
	float db = sqrt((distbottomx*distbottomx) + (distbottomy*distbottomy));

	////left
	//distleftx = clx - cx;
	//distlefty = cly - cy;
	//float dl = sqrt((distleftx*distleftx) + (distlefty*distlefty));

	////right
	//distrightx = crx - cx;
	//distrighty = cry - cy;
	//float dr = sqrt((distrightx*distrightx) + (distrighty*distrighty));

	if (db <= radius)
	{
		std::cout << "touching bottom" << std::endl;
		bottom = true;
		return true;
	}
	bottom = false;
	/*else if (dl < radius)
	{
		std::cout << "touching left" << std::endl;
		left = true;
		return true;
	}
	else if (dr < radius)
	{
		std::cout << "touching right" << std::endl;
		right = true;
		return true;
	}*/
	return false;
}

/* point to circle calculation*/
bool Collision::pointCircle(float px, float py, float cix, float ciy, float r)
{
	//getting distance between point and circle's center using pythagorean theorem
	float distx = px - cix;
	float disty = py - ciy;
	float distance = sqrt((distx * distx) + (disty * disty));

	// if distance is less than radius point is inside
	if (distance == r)
	{
		
		return true;
	}
	return false;
}

/*function to check if the point is on the line segment*/
bool Collision::linePoint(float ax, float ay, float bx, float by, float ptx, float pty)
{
	//get distance from point to the two ends of the line
	float d1 = dist(ptx, pty, ax, ay);
	//float d1x = ptx - ax;
	//float d1y = pty - ay;
	//float d1 = sqrt((d1x * d1x) + (d1y * d1y));
	float d2 = dist(ptx, pty, bx, by);
	/*float d2x = ptx - bx;
	float d2y = ptx - by;
	float d2 = sqrt((d2x * d2x) + (d2y * d2y));*/

	//get line length
	//float lx = bx - ax;
	//float ly = by - ay;
	//float l = sqrt((lx * lx) + (ly * ly));
	float l = dist(ax, ay, bx, by);

	//float are minutely accurate adding buffer that will give collision
	float buffer = 0.0005f;

	//if two distances are equal to the line's length then the point is on the line
	if (d1 + d2 >= l - buffer && d1 + d2 <= l + buffer)
	{
		return true;
	}
	return false;
}

float Collision::dist(float x, float y, float x1, float y1)
{
	float distancex = (x1 - x) * (x1 - x);
	float distancey = (y1 - y) * (y1 - y);
	float distance = sqrt(distancex + distancey);
	return (distance);
}