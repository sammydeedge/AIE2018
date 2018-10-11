#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	union {
		struct {
			Vector2 right;
			Vector2 up;
		};
		struct {
			float xAxis[2];
			float yAxis[2];
		};

		float m[4];
		float mm[2][2];
		Vector2 axis[2];
	};
	Matrix2();
	Matrix2(float Xx, float Xy, float Yx, float Yy);

	operator float* ();
	operator const float* () const;

	Vector2& operator [] (int index);

	Matrix2 operator * (const Matrix2& other) const;
	Vector2 operator * (const Vector2& vect) const;

	Matrix2& operator=(const Matrix2 & other);

	void setRotate(float angle);

private:

};