#include "CLDR.h"
#include "Vector2.h"


bool CLDR::overlaps(sphere* s, sphere* s2)
{
	Vector2 diff = s2->centre - s->centre;
	//compare distance between spheres to difference in radii
	float r = s->radius + s2->radius;

	return diff.magnitude_squared() <= (r * r);
}

bool CLDR::overlaps(Vector2 point1, Vector2 point2)
{
	Vector2 p1_min = Vector2(point1.x - 1, point1.y - 1);
	Vector2 p1_max = Vector2(point1.x + 1, point1.y + 1);
	Vector2 p2_min = Vector2(point2.x - 1, point2.y - 1);
	Vector2 p2_max = Vector2(point2.x + 1, point2.y + 1);

	return !(p1_max.x < p2_min.x || p2_max.x < p1_min.x || p1_max.y < p2_min.y || p2_max.y < p1_min.y);
}

bool CLDR::overlaps(sphere* s, Vector2* point)
{

	auto dist = point->distance(s->centre);
	return s->radius < dist;
}

bool CLDR::overlaps(sphere s, Vector2 point)
{

	auto dist = point.distance(s.centre);
	return s.radius < dist;
}