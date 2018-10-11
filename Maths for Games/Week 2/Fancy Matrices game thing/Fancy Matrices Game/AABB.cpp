#include "AABB.h"


//Returns a Vector 2 holding the the position of the objects centre point
Vector2 AABB::centre()
{
	return (min + max) * 0.5f;
}

//Returns a Vector 2 holding the the extents (half of the width, half the height)
Vector2 AABB::extents() const
{
	return Vector2((abs(max.x - min.x) * 0.5f), (abs(max.y - min.y) * 0.5f));
}

//Creates a list of position Vectors for 
std::vector<Vector2> AABB::corners() const
{
	std::vector<Vector2> corners(4);
	corners[0] = min;
	corners[1] = Vector2(min.x, max.y);
	corners[2] = max;
	corners[3] = Vector2(max.x, min.y);
	return corners;
}

void AABB::fit(const Vector2* points, unsigned int count)
{
	min = { FLT_MAX, FLT_MAX };
	max = { FLT_MIN, FLT_MIN };

	//find min and max of the point
	for (unsigned int i = 0; i < count; ++i, ++points)
	{
		min = Vector2::min(min, *points);
		max = Vector2::max(max, *points);
	}
}

bool AABB::overlaps(const Vector2& p) const
{
	return !(p.x < min.x || p.y < min.y || p.x > max.x || p.y > max.y);
}

bool AABB::overlaps(const AABB& other) const
{
	return !(max.x < other.min.x || max.y < other.min.y || min.x > other.max.x || min.y > other.max.y);
}

Vector2 AABB::closestPoint(const Vector2& p) const
{
	return Vector2::clamp(p, min, max);
}

Vector2 AABB::getMin()
{
	return min;
}

Vector2 AABB::getMax()
{
	return max;
}