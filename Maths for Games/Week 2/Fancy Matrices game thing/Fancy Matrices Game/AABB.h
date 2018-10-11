#pragma once
#include "Vector2.h"
#include <vector>


//Axis-aligned Bounding box
class AABB
{
public:
	AABB() {}
	AABB(const Vector2& min, const Vector2& max) : min(min), max(max) {}

	Vector2 centre();
	Vector2 extents() const;
	std::vector<Vector2> AABB::corners() const;

	void fit(const Vector2* points, unsigned int count);

	bool overlaps(const Vector2& p) const;
	bool overlaps(const AABB& other) const;

	Vector2 closestPoint(const Vector2& p) const;

	Vector2 getMin();
	Vector2 getMax();

protected:
	Vector2 min, max;
};