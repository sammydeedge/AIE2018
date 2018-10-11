#include "Plane.h"

plane::plane(const Vector2& p1, const Vector2& p2)
{
	//create a normalised vector from p1 to p2
	auto v = p2 - p1;
	v.normalise();

	//set normal
	normal.x = -v.y;
	normal.y = v.x;

	// calculate d
	dist = -p1.dot(normal);
}

float plane::distanceTo(const Vector2& p) const
{
	return p.dot(normal) + dist;
}

Vector2 plane::closestPoint(const Vector2& p) const
{
	return p - normal * distanceTo(p);
}

plane::ePlaneResult plane::testSide(const Vector2& p) const
{
	float t = p.dot(normal) + dist;

	if (t < 0)		{ return ePlaneResult::BACK; }
	if (t > 0)		{ return ePlaneResult::FRONT; }
	else			{ return ePlaneResult::INTERSECTS; }
}

plane::ePlaneResult plane::testSide(const AABB& aabb) const
{
	//create an array with false as the defaults
	bool posChecks[2] = { false, false };

	//check each of the corners
	for (auto c : aabb.corners())
	{
		auto result = testSide(c);
		if (result == ePlaneResult::FRONT)
		{
			posChecks[0] = true;							//If *any* corner is in front of the plane, it will be recorded in the first entry of the "posChecks" array
		}
		else if (result == ePlaneResult::BACK)
		{
			posChecks[1] = true;							//If *any* corner is in behind the plane, it will be recorded in the second entry of the "posChecks" array
		}

	}

	if (posChecks[0] && !posChecks[1]) { return ePlaneResult::FRONT; }	//If any corner is registered as in front of the plane, and none behind, the object is in front of the plane
	if (!posChecks[0] && posChecks[1]) { return ePlaneResult::BACK; }	//If any corner is registered as behind the plane, and none in front, the object is in behind the plane
	else { return ePlaneResult::INTERSECTS; }							//If neither (i.e. some are in front, and some behind), the object intersects the plane.
}