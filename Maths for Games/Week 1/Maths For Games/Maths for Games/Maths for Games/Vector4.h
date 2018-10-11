#pragma once

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
	float operator[](int index) const;

	operator float* ();
	operator const float* () const;
	Vector4 operator+(const Vector4 & other) const;
	Vector4 operator-(const Vector4 & other) const;
	Vector4 operator*(float scalar) const;
	Vector4 operator/(float scalar) const;
};