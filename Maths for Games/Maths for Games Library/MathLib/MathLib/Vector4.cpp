#include "Vector4.h"

Vector4::Vector4()
{

}

Vector4::Vector4(float set_x, float set_y, float set_z, float set_w)
{
	x = set_x;
	y = set_y;
	z = set_z;
	w = set_w;
}

Vector4::Vector4(Vector2 set_x_y, float set_z, float set_w)
{
	x = set_x_y.x;
	y = set_x_y.y;
	z = set_z;
	w = set_w;
}


float Vector4::operator [] (int index) const		{ return data[index]; }
Vector4::operator float* ()							{ return &x; }

Vector4::operator const float* () const				{ return &x; }


Vector4 Vector4::operator + (const Vector4& other) const
{
	return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vector4 Vector4::operator - (const Vector4& other) const
{
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vector4 Vector4::operator * (float scalar) const
{
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 Vector4::operator / (float scalar) const
{
	return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
}

float Vector4::magnitude() const
{
	return sqrt(x*x + y * y + z * z + w * w);
}

float Vector4::magnitude_squared() const
{
	return (x*x + y * y + z * z + w * w);
}

void Vector4::normalise()
{
	float magnitude = sqrt(x*x + y * y + z * z + w*w);
	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
		w /= magnitude;
	}

}

Vector4 Vector4::normalised()
{
	float magnitude = sqrt(x*x + y * y + z * z + w*w);
	if (magnitude != 0)
	{
		return Vector4(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
	}
	else
	{
		return *this;
	}
}

float Vector4::dot(const Vector4& other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

Vector4 Vector4::cross(const Vector4& other) const
{
	return Vector4(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x,0);
}