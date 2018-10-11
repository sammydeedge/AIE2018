#pragma once
class Vector3 
{
public:
	union
	{
		struct
		{
			float x, y, z;
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
};

inline Vector3 operator *(float scalar, const Vector3 & vect)
{
	Vector3 update;
	update.x = vect.x * scalar;
	update.y = vect.y * scalar;
}