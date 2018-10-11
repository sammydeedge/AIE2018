#include "Matrix3.h"

Matrix3::Matrix3()
{
	mm[0][0] = 1; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = 0;
	mm[0][2] = 0;
	mm[1][0] = 0;
	mm[1][1] = 1;
	mm[1][2] = 0;
	mm[2][0] = 0;
	mm[2][1] = 0;
	mm[2][2] = 1;
}

Matrix3::Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz)
{
	mm[0][0] = Xx; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = Xy;
	mm[0][2] = Xz;
	mm[1][0] = Yx;
	mm[1][1] = Yy;
	mm[1][2] = Yz;
	mm[2][0] = Zx;
	mm[2][1] = Zy;
	mm[2][2] = Zz;
}

Vector3& Matrix3::operator [] (int index)
{
	return axis[index];
}

const Vector3& Matrix3::operator [] (int index) const
{
	return axis[index];
}


Matrix3::operator float* ()				{ return &m[0]; }
Matrix3::operator const float* () const { return &m[0]; }

Matrix3 Matrix3::operator * (const Matrix3& other) const
{
	Matrix3 result;

	for (int c = 0; c < 3; ++c)
	{
		for (int r = 0; r < 3; ++r)
		{
			result.mm[c][r] = mm[0][r] * other.mm[c][0] + mm[1][r] * other.mm[c][1] + mm[2][r] * other.mm[c][2];
		}
	}
	return result;
}

Vector3 Matrix3::operator * (const Vector3& vect) const
{
	Vector3 result;

	for (int r = 0; r < 3; ++r)
	{
			result.data[r] = mm[0][r] * vect[0] + mm[1][r] * vect[1] + mm[2][r] * vect[2];
	}
	return result;
}

Matrix3 Matrix3::operator * (float number) const
{
	Matrix3 result;

	for (int c = 0; c < 3; ++c)
	{
		for (int r = 0; r < 3; ++r)
		{
			result.mm[c][r] = mm[c][r] * number;
		}
	}
	return result;
}

Matrix3 Matrix3::operator + (const Matrix3& other) const
{
	Matrix3 result;

	for (int c = 0; c < 3; ++c)
	{
		for (int r = 0; r < 3; ++r)
		{
			result.mm[c][r] = mm[c][r] + other.mm[c][r];
		}
	}
	return result;
}

Matrix3& Matrix3::operator=(const Matrix3& other)
{
		for (int c = 0; c < 3; ++c)
	{
		for (int r = 0; r < 3; ++r)
		{
			mm[r][c] = other.mm[r][c];
		}
	}

	return *this;
}

void Matrix3::setRotateX(float angle)
{
	mm[0][0] = 1; //Each Matrix is 3 rows, 3 columns, first number is row, second is column
	mm[1][1] = cos(angle);
	mm[1][2] = sin(angle);
	mm[2][1] = -sin(angle);
	mm[2][2] = cos(angle);
}

void Matrix3::setRotateY(float angle)
{
	mm[0][0] = cos(angle); //Each Matrix is 3 rows, 3 columns, first number is row, second is column
	mm[0][2] = -sin(angle);
	mm[1][1] = 1;
	mm[2][0] = sin(angle);
	mm[2][2] = cos(angle);
}

void Matrix3::setRotateZ(float angle)
{
	mm[0][0] = cos(angle); //Each Matrix is 3 rows, 3 columns, first number is row, second is column
	mm[0][1] = sin(angle);
	mm[1][0] = -sin(angle);
	mm[1][1] = cos(angle);
	mm[2][2] = 1;
}

void Matrix3::setallRotates(float pitch_rad, float yaw_rad, float roll_rad) {
	
	Matrix3 x_rotate, y_rotate, z_rotate, result; 
	x_rotate.setRotateX(pitch_rad);
	y_rotate.setRotateY(yaw_rad);
	z_rotate.setRotateZ(roll_rad);
	// combine rotations in a specific order
	*this = z_rotate * y_rotate * x_rotate;

}

void Matrix3::setScaled(float x, float y, float z)
{
	mm[0][0] = x; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = 0;
	mm[0][2] = 0;
	mm[1][0] = 0;
	mm[1][1] = y;
	mm[1][2] = 0;
	mm[2][0] = 0;
	mm[2][1] = 0;
	mm[2][2] = z;
}

void Matrix3::setScaled(const Vector3& vect)
{
	mm[0][0] = vect.x; //Each Matrix is 3 rows, 3 columns, first number is column, second is row
	mm[0][1] = 0;
	mm[0][2] = 0;
	mm[1][0] = 0;
	mm[1][1] = vect.y;
	mm[1][2] = 0;
	mm[2][0] = 0;
	mm[2][1] = 0;
	mm[2][2] = vect.z;
}

void Matrix3::translate(float x, float y)
{
	mm[2][0] += x;
	mm[2][1] += y;
}