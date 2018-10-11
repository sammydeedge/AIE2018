#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float set_x, float set_y)
{
	x = set_x;
	y = set_y;
}

float Vector2::operator [] (int index) const { return data[index]; }

Vector2::operator float* () { return &x; }
Vector2::operator const float* () const { return &x; }

Vector2 Vector2::operator + (const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator - (const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator * (float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator / (float scalar) const
{
	return Vector2(x / scalar, y / scalar);
}

Vector2 Vector2::operator=(const Vector2& other)
{
	return Vector2(x = other.x, y = other.y);
}

float Vector2::magnitude() const
{
	return sqrt(x * x + y * y);
}

float Vector2::magnitude_squared() const
{
	return (x * x + y * y);
}

void Vector2::normalise()
{
	float magnitude = sqrt(x*x + y * y);
	x /= magnitude;
	y /= magnitude;
}

Vector2 Vector2::normalised()
{
	float magnitude = sqrt(x*x + y * y);
	return Vector2(x / magnitude, y / magnitude);
}

float Vector2::dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}