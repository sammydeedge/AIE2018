#include "Vector3.h"


Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float set_x, float set_y, float set_z)
{
	x = set_x;
	y = set_y;
	z = set_z;
}

float Vector3::operator [] (int index) const { return data[index]; }

Vector3::operator float* ()				 { return &x; }
Vector3::operator const float* () const	 { return &x; }

Vector3 Vector3::operator + (const Vector3& other) const 
{ 
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator - (const Vector3& other) const
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator * (float scalar) const
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator / (float scalar) const
{
	return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3 Vector3::operator=(const Vector3& other)
{
	return Vector3(x = other.x, y = other.y, z = other.z);
}

float Vector3::magnitude() const
{
	return sqrt(x*x + y*y + z*z);
}

float Vector3::magnitude_squared() const
{
	return (x * x + y * y + z * z);
}

void Vector3::normalise()
{
	float magnitude = sqrt(x*x + y * y + z*z);
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

Vector3 Vector3::normalised()
{
	float magnitude = sqrt(x*x + y * y + z*z);
	return Vector3(x / magnitude, y / magnitude, z / magnitude);
}

float Vector3::dot(const Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other) const
{
	return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}