#pragma once
#include <cmath>
#include "Vector2.h"


class Vector4
{
public:
	union
	{
		struct
		{
			float x, y, z, w;
		};

		float data[3];
	};
	Vector4();
	Vector4(float set_x, float set_y, float set_z, float set_w);
	Vector4(Vector2 set_x_y, float set_z, float set_w);
	float operator[](int index) const;

	operator float* ();
	operator const float* () const;
	Vector4 operator+(const Vector4 & other) const;
	Vector4 operator-(const Vector4 & other) const;
	Vector4 operator*(float scalar) const;
	Vector4 operator/(float scalar) const;

	float magnitude() const;
	float magnitude_squared() const;

	void normalise();
	Vector4 normalised();

	float dot(const Vector4& other) const;
	Vector4 cross(const Vector4& other) const;
};

inline Vector4 operator *(float scalar, const Vector4 & vect)
{
	Vector4 update;
	update.x = vect.x * scalar;
	update.y = vect.y * scalar;
	update.z = vect.z * scalar;
	update.w = vect.w * scalar;
	return update;
}