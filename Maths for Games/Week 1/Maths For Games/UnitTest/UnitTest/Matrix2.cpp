#include "Matrix2.h"


Matrix2::Matrix2()
{
	mm[0][0] = 1; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = 0;
	mm[1][0] = 0;
	mm[1][1] = 1;
}

Matrix2::Matrix2(float Xx, float Xy,float Yx, float Yy)
{
	mm[0][0] = Xx; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = Xy;
	mm[1][0] = Yx;
	mm[1][1] = Yy;
}

Vector2& Matrix2::operator [] (int index)
{
	return axis[index];
}

Matrix2::operator float* () { return &m[0]; }
Matrix2::operator const float* () const { return &m[0]; }

Matrix2 Matrix2::operator * (const Matrix2& other) const
{
	Matrix2 result;

	for (int c = 0; c < 2; ++c)
	{
		for (int r = 0; r < 2; ++r)
		{
			result.mm[c][r] = mm[0][r] * other.mm[c][0] + mm[1][r] * other.mm[c][1];
		}
	}
	return result;
}

Vector2 Matrix2::operator * (const Vector2& vect) const
{
	Vector2 result;

	for (int r = 0; r < 2; ++r)
	{
		result.data[r] = mm[0][r] * vect[0] + mm[1][r] * vect[1];
	}
	return result;
}

Matrix2& Matrix2::operator=(const Matrix2& other)
{
	for (int c = 0; c < 2; ++c)
	{
		for (int r = 0; r < 2; ++r)
		{
			mm[r][c] = other.mm[r][c];
		}
	}

	return *this;
}

//Sets rotational matrix for given angle
void Matrix2::setRotate(float angle)
{
	mm[0][0] = cos(angle);
	mm[0][1] = sin(angle);
	mm[1][0] = -sin(angle);
	mm[1][1] = cos(angle);
}