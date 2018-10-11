#include "CLDR.h"


bool CLDR::overlaps(sphere* s, AABB* a)
{
	auto diff = a->closestPoint(s->centre) - s->centre;
	return diff.dot(diff) <= (s->radius * s->radius);
}

bool CLDR::overlaps(sphere* s, sphere* s2)
{
	Vector2 diff = s2->centre - s->centre;
	//compare distance between spheres to difference in radii
	float r = s->radius + s2->radius;
	return diff.magnitude_squared() <= (r * r);
}



bool CLDR::overlaps(AABB* a, AABB* a2)
{
	return !(a->getMax().x < a2->getMin().x || a->getMax().y < a2->getMin().y || a->getMin().x > a2->getMax().x || a->getMin().y > a2->getMax().y);
}



plane::ePlaneResult CLDR::overlaps(plane* p, sphere* s)
{
	float t = p->distanceTo(s->centre);

	if (t > s->radius)			{ return plane::ePlaneResult::FRONT; }
	else if (t < -s->radius)	{ return plane::ePlaneResult::BACK; }
	else						{ return plane::ePlaneResult::INTERSECTS; }
}


plane::ePlaneResult CLDR::overlaps(plane* p, AABB* a)
{
	//create an array with false as the defaults
	bool posChecks[2] = { false, false };

	//check each of the corners
	for (auto c : a->corners())
	{
		auto result = p->testSide(c);
		if (result == plane::ePlaneResult::FRONT)
		{
			posChecks[0] = true;							//If *any* corner is in front of the plane, it will be recorded in the first entry of the "posChecks" array
		}
		else if (result == plane::ePlaneResult::BACK)
		{
			posChecks[1] = true;							//If *any* corner is in behind the plane, it will be recorded in the second entry of the "posChecks" array
		}

	}

	if (posChecks[0] && !posChecks[1]) { return plane::ePlaneResult::FRONT; }	//If any corner is registered as in front of the plane, and none behind, the object is in front of the plane
	if (!posChecks[0] && posChecks[1]) { return plane::ePlaneResult::BACK; }	//If any corner is registered as behind the plane, and none in front, the object is in behind the plane
	else { return plane::ePlaneResult::INTERSECTS; }							//If neither (i.e. some are in front, and some behind), the object intersects the plane.
}


