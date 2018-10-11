#pragma once
#include "Vector2.h"
#include "AABB.h"
#include <vector>

class sphere
{
public:
	sphere() {}
	sphere(const Vector2& pos, float rad) : centre(pos), radius(rad) {}

	void fit(const Vector2* points, unsigned int cont);
	void fit(const std::vector<Vector2>& points);

	bool overlaps(const Vector2& point) const;

	Vector2 closestPoint(const Vector2& point) const;

	Vector2 centre;
	float radius;
};