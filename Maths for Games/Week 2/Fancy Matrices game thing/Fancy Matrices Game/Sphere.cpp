#include "Sphere.h"

void sphere::fit(const Vector2* points, unsigned int count)
{
	//Remove extents
	Vector2 min{ FLT_MAX, FLT_MAX };
	Vector2 max{ FLT_MIN, FLT_MIN };

	//Iterate through the points finding the lowest and highest value
	for (unsigned int i = 0; i < count; ++i, ++points)
	{
		min = Vector2::min(min, *points);
		max = Vector2::max(max, *points);
	}
	//enclose the min-max box in a circle
	centre = (min + max) * 0.5f;
	radius = centre.distance(max);
}

void sphere::fit(const std::vector<Vector2>& points)
{
	//Remove extents
	Vector2 min{ FLT_MAX, FLT_MAX };
	Vector2 max{ FLT_MIN, FLT_MIN };

	//Iterate through the points finding the lowest and highest value
	for (auto& p : points)
	{
		min = Vector2::min(min, p);
		max = Vector2::max(max, p);
	}
	//enclose the min-max box in a circle
	centre = (min + max) * 0.5f;
	radius = centre.distance(max);
}

bool sphere::overlaps(const Vector2& point) const
{
	Vector2 toPoint = point - centre;
	return toPoint.magnitude_squared() <= (radius * radius);
}

Vector2 sphere::closestPoint(const Vector2& point) const
{
	//distance from centre
	Vector2 toPoint = point - centre;
	
	if (toPoint.magnitude_squared() > (radius * radius))
	{
		toPoint = toPoint.normalised() * radius;
	}

	return centre + toPoint;
}