#pragma once
#include "Vector4.h"

class Matrix4 {
public:

	union {
		struct {
			Vector4 right;
			Vector4 up;
			Vector4 backward;
			Vector4 transform;
		};
		struct {
			float xAxis[4];
			float yAxis[4];
			float zAxis[4];
			float translate[4];
		};

		float m[16];
		float mm[4][4];
		Vector4 axis[4];
	};

	Matrix4();
	//Intialises Matrix with chosen values (reading down columns, left column to right column)
	Matrix4(float Xx, float Xy, float Xz, float Xt, float Yx, float Yy, float Yz, float Yt, float Zx, float Zy, float Zz, float Zt, float Tx, float Ty, float Tz, float Tt);

	operator float* ();
	operator const float* () const;

	//Allows elements to be read based on index
	Vector4& operator [] (int index);

	//Multiplication by Matrix
	Matrix4 operator * (const Matrix4& other) const;
	//Multiplication by Vector
	Vector4 operator * (const Vector4& vect) const;

	Matrix4& operator=(const Matrix4 & other);

	//Sets rotations values, rotating around a specific 
	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	//Intialises an identity Matrix
	const Matrix4 getindentityMatrix();

	void setScaled(float x, float y, float z);
	void setPosition(float xPos, float yPos, float zPos);
};