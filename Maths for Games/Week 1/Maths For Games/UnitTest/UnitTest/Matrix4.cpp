#pragma once
#include "Matrix4.h"

Matrix4::Matrix4()
{
	mm[0][0] = 1; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = 0;
	mm[0][2] = 0;
	mm[0][3] = 0;
	mm[1][0] = 0;
	mm[1][1] = 1;
	mm[1][2] = 0;
	mm[1][3] = 0;
	mm[2][0] = 0;
	mm[2][1] = 0;
	mm[2][2] = 1;
	mm[2][3] = 0;
	mm[3][0] = 0;
	mm[3][1] = 0;
	mm[3][2] = 0;
	mm[3][3] = 1;
}

Matrix4::Matrix4(float Xx, float Xy, float Xz, float Xt, float Yx, float Yy, float Yz, float Yt, float Zx, float Zy, float Zz, float Zt, float Tx, float Ty, float Tz, float Tt)
{
	mm[0][0] = Xx; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = Xy;
	mm[0][2] = Xz;
	mm[0][3] = Xt;
	mm[1][0] = Yx;
	mm[1][1] = Yy;
	mm[1][2] = Yz;
	mm[1][3] = Yt;
	mm[2][0] = Zx;
	mm[2][1] = Zy;
	mm[2][2] = Zz;
	mm[2][3] = Zt;
	mm[3][0] = Tx;
	mm[3][1] = Ty;
	mm[3][2] = Tz;
	mm[3][3] = Tt;
}

Vector4& Matrix4::operator [] (int index)
{
	return axis[index];
}

Matrix4::operator float* () { return &m[0]; }
Matrix4::operator const float* () const { return &m[0]; }

Matrix4 Matrix4::operator * (const Matrix4& other) const
{
	Matrix4 result;

	for (int c = 0; c < 4; ++c)
	{
		for (int r = 0; r < 4; ++r)
		{
			result.mm[r][c] = mm[0][c] * other.mm[r][0] + mm[1][c] * other.mm[r][1] + mm[2][c] * other.mm[r][2] + mm[3][c] * other.mm[r][3];
		}
	}
	return result;
}

Vector4 Matrix4::operator * (const Vector4& vect) const
{
	Vector4 result;

	for (int r = 0; r < 4; ++r)
	{
		result.data[r] = mm[0][r] * vect[0] + mm[1][r] * vect[1] + mm[2][r] * vect[2] + mm[3][r] * vect[3];
	}
	return result;
}

Matrix4& Matrix4::operator=(const Matrix4& other)
{
	for (int c = 0; c < 4; ++c)
	{
		for (int r = 0; r < 4; ++r)
		{
			mm[r][c] = other.mm[r][c];
		}
	}

	return *this;
}

void Matrix4::setRotateX(float radians)
{
	mm[0][0] = 1; 
	mm[0][1] = 0;
	mm[0][2] = 0;
	mm[1][0] = 0;
	mm[1][1] = cos(radians);
	mm[1][2] = sin(radians);
	mm[2][0] = 0;
	mm[2][1] = -sin(radians);
	mm[2][2] = cos(radians);
}

void Matrix4::setRotateY(float radians)
{
	mm[0][0] = cos(radians); //Each Matrix is 3 rows, 3 columns, first number is row, second is column
	mm[0][1] = 0;
	mm[0][2] = -sin(radians);
	mm[1][0] = 0;
	mm[1][1] = 1;
	mm[1][2] = 0;
	mm[2][0] = sin(radians);
	mm[2][1] = 0;
	mm[2][2] = cos(radians);
}

void Matrix4::setRotateZ(float radians)
{
	mm[0][0] = cos(radians); //Each Matrix is 3 rows, 3 columns, first number is row, second is column
	mm[0][1] = sin(radians);
	mm[0][2] = 0;
	mm[1][0] = -sin(radians);
	mm[1][1] = cos(radians);
	mm[1][2] = 0;
	mm[2][0] = 0;
	mm[2][1] = 0;
	mm[2][2] = 1;
}

const Matrix4 Matrix4::getindentityMatrix()
{
	Matrix4 result;

	result.mm[0][0] = 1;
	result.mm[0][1] = 0;
	result.mm[0][2] = 0;
	result.mm[0][3] = 0;
	result.mm[1][0] = 0;
	result.mm[1][1] = 1;
	result.mm[1][2] = 0;
	result.mm[1][3] = 0;
	result.mm[2][0] = 0;
	result.mm[2][1] = 0;
	result.mm[2][2] = 1;
	result.mm[2][3] = 0;
	result.mm[3][0] = 0;
	result.mm[3][1] = 0;
	result.mm[3][2] = 0;
	result.mm[3][3] = 1;

	return result;

}

void Matrix4::setScaled(float x, float y, float z)
{
	mm[0][0] = x; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = 0;
	mm[0][2] = 0;
	mm[0][3] = 0;
	mm[1][0] = 0;
	mm[1][1] = y;
	mm[1][2] = 0;
	mm[1][3] = 0;
	mm[2][0] = 0;
	mm[2][1] = 0;
	mm[2][2] = z;
	mm[2][3] = 0;
	mm[3][0] = 0;
	mm[3][1] = 0;
	mm[3][2] = 0;
	mm[3][3] = 1;
}

void Matrix4::setPosition(float xPos, float yPos, float zPos)
{
	mm[3][0] = xPos;
	mm[3][1] = yPos;
	mm[3][2] = zPos;
}