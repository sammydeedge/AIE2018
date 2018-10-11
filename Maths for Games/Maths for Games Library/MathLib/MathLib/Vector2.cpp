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
	if (magnitude != 0)
	{
		x /= magnitude;
		y /= magnitude;
	}
}

Vector2 Vector2::normalised()
{
	float magnitude = sqrt(x*x + y * y);
	if (magnitude != 0)
	{
		return Vector2(x / magnitude, y / magnitude);
	}
	else
	{
		return *this;
	}
}

float Vector2::dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

float Vector2::min(float a, float b)
{
	return a < b ? a : b;
}

float Vector2::max(float a, float b)
{
	return a > b ? a : b;
}

Vector2 Vector2::min(const Vector2& a, const Vector2& b)
{
	return Vector2(min(a.x, b.x), min(a.y, b.y));
}

Vector2 Vector2::max(const Vector2& a, const Vector2& b)
{
	return Vector2(max(a.x, b.x), max(a.y, b.y));
}

float Vector2::clamp(float t, float a, float b)
{
	return max(a, min(b, t));
}

Vector2 Vector2::clamp(const Vector2& t, const Vector2& a, const Vector2& b)
{
	return max(a, min(b, t));
}

float Vector2::distance(const Vector2& other)
{
	float diffX = x - other.x;
	float diffY = y - other.y;
	return sqrt(diffX * diffX + diffY * diffY);
}