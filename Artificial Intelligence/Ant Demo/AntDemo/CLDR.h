#pragma once
#include "Sphere.h"

namespace CLDR
{
	//bool overlaps(sphere* s, AABB* a);
	bool overlaps(sphere* s, sphere* s2);
	bool overlaps(sphere* s, Vector2* point);
	bool overlaps(sphere s, Vector2 point);
	bool overlaps(Vector2 point, Vector2 point2);

	//bool overlaps(AABB* a, AABB* a2);

	////plane::ePlaneResult overlaps(sphere* s, struct list)

	//plane::ePlaneResult overlaps(plane* p, sphere* s);	
	//plane::ePlaneResult overlaps(plane* p, AABB* a);
	
	/*
	bool S_A_Check = sphere::overlaps(AABB* other);
	bool S_P_Check = sphere::overlaps(plane* other);

	bool A_S_Check = AABB::overlaps(sphere* other);
	bool A_A_Check = AABB::overlaps(AABB* other);
	bool A_P_Check = AABB::overlaps(plane* other);*/
}