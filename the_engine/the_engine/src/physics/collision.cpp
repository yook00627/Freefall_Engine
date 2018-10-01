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