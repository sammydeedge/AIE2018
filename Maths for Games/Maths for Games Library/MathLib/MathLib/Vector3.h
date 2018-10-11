#pragma once
#include<cmath>

class Vector3 
{
public:
	union
	{
		struct
		{
			float x, y;
			union {
				float z, w;
			};
		};
		struct
		{
			float r, g, b;
		};

		float data[3];
	};
	Vector3();
	Vector3(float x, float y, float z);
	float operator[](int index) const;

	operator float* ();
	operator const float* () const;
	Vector3 operator+(const Vector3 & other) const;
	Vector3 operator-(const Vector3 & other) const;
	Vector3 operator*(float scalar) const;
	Vector3 operator/(float scalar) const;
	Vector3 operator=(const Vector3 & other);
	
	float magnitude() const;
	float magnitude_squared() const;

	void normalise();
	Vector3 normalised();

	float dot(const Vector3& other) const;
	Vector3 cross(const Vector3& other) const;
};

inline Vector3 operator *(float scalar, const Vector3 & vect)
{
	Vector3 update;
	update.x = vect.x * scalar;
	update.y = vect.y * scalar;
	update.z = vect.z * scalar;
	return update;
}