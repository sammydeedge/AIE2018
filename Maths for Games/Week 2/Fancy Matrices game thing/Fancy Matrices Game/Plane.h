#pragma once
#include "Vector2.h"
#include "AABB.h"

class plane
{
public:
	plane() {}
	plane(float x, float y, float d) : normal(x, y), dist(d) {}
	plane(const Vector2& n, float d) : normal(n), dist(d) {}

	plane(const Vector2& p1, const Vector2& p2);

	float distanceTo(const Vector2& p) const;
	Vector2 closestPoint(const Vector2& p) const;

	enum ePlaneResult : int {
		FRONT = 1,
		BACK = -1,
		INTERSECTS = 0
	};

	ePlaneResult testSide(const Vector2& p) const;
	//ePlaneResult testSide(const Sphere& sphere) const;
	ePlaneResult testSide(const AABB& aabb) const;


	Vector2 normal;
	float dist;

};