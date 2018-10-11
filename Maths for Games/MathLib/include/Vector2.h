#pragma once
#include <cmath>

class Vector2
{
public:
	union
	{
		struct
		{
			float x, y;
		};

		float data[2];
	};
	Vector2();
	Vector2(float x, float y);
	float operator[](int index) const;

	operator float* ();
	operator const float* () const;
	Vector2 operator+(const Vector2 & other) const;
	Vector2 operator-(const Vector2 & other) const;
	Vector2 operator*(float scalar) const;
	Vector2 operator/(float scalar) const;
	Vector2 operator=(const Vector2 & other);

	float magnitude() const;
	float magnitude_squared() const;

	void normalise();
	Vector2 normalised();

	float dot(const Vector2& other) const;

	static float min(float a, float b);
	static float max(float a, float b);

	static Vector2 min(const Vector2& a, const Vector2& b);
	static Vector2 max(const Vector2& a, const Vector2& b);

	static float clamp(float t, float a, float b);
	static Vector2 clamp(const Vector2& t, const Vector2& a, const Vector2& b);

	float distance(const Vector2& other);
};

inline Vector2 operator *(float scalar, const Vector2 & vect)
{
	Vector2 update;
	update.x = vect.x * scalar;
	update.y = vect.y * scalar;
	return update;
}