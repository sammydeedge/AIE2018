#pragma once
#include "Vector3.h"

class Matrix3 {
public:

	union {
		struct {
			Vector3 right;
			Vector3 up;
			Vector3 backward;
		};
		struct {
			float xAxis[3];
			float yAxis[3];
			float zAxis[3];
		};

		float m[9];
		float mm[3][3];
		Vector3 axis[3];
	};
	Matrix3();
	Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);

	operator float* ();
	operator const float* () const;

	Vector3& operator [] (int index);
	
	Matrix3 operator * (const Matrix3& other) const;
	Vector3 operator * (const Vector3& vect) const;

	Matrix3& operator=(const Matrix3 & other);

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);
	void setallRotates(float pitch_rad, float yaw_rad, float roll_rad);

	void setScaled(float x, float y, float z);
	void setScaled(const Vector3& vect);
};