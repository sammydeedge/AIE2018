#include "Vector4.h"

Vector4::Vector4()
{

}

Vector4::Vector4(float setx, float sety, float setz, float setw)
{
	x = setx;
	y = sety;
	z = setz;
	w = setw;
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