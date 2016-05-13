#pragma once
#include <math.h>

namespace MathFuncs
{
	class Vector2
	{
	public:
		Vector2();
		~Vector2();
		Vector2(const float _x, const float _y);
		Vector2(const float _x);
		float x, y;

		float Vector2::Dot(Vector2);
		float Vector2::Magnitude();
		Vector2 Vector2::Normalize();

		Vector2 operator+ (const Vector2);
		Vector2 operator- (const Vector2);
		Vector2 operator* (const float f);
	};

	class Vector3
	{
	public:
		Vector3();
		~Vector3();		
		Vector3(const float _x, const float _y, const float _z);
		Vector3(const float _x, const float _y);
		Vector3(const float _x);
		float x, y, z;

		float Vector3::Dot(Vector3);
		Vector3 Vector3::Cross(Vector3);
		float Vector3::Magnitude();
		Vector3 Vector3::Normalize();

		Vector3 operator+ (const Vector3);
		Vector3 operator- (const Vector3);
		Vector3 operator* (const float f);
	};

	class Vector4
	{
	public:
		Vector4();
		~Vector4();
		Vector4(const float _x, const float _y, const float _z, const float _w);
		Vector4(const float _x, const float _y, const float _z);
		Vector4(const float _x, const float _y);
		Vector4(const float _x);
		float x, y, z, w;

		float Vector4::Dot(Vector4);
		Vector4 Vector4::Cross(Vector4);
		float Vector4::Magnitude();
		Vector4 Vector4::Normalize();

		Vector4 operator+ (const Vector4);
		Vector4 operator- (const Vector4);
		Vector4 operator* (const float f);
	};

	class Matrix2
	{
	public:
		Matrix2();
		~Matrix2();
		Matrix2(const float _x, const float _y, const float _z, const float _w);
		float value[2][2];
		Matrix2 operator* (const Matrix2);
	private:

	};

	class Matrix3
	{
	public:
		Matrix3();
		~Matrix3();
		Matrix3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i);
		float value[3][3]; 
		Matrix3 operator* (const Matrix3);
	private:

	};

	class Matrix4
	{
	public:
		Matrix4();
		~Matrix4();
		Matrix4(const float a, const float b, const float c, const float d,
				const float e, const float f, const float g, const float h, 
				const float i, const float j, const float k, const float l, 
				const float m, const float n, const float o, const float p);
		float value[4][4];
		Matrix4 operator* (const Matrix4);
	private:

	};

	Vector2 operator* (float, Vector2);
	Vector3 operator* (float, Vector3);
	Vector4 operator* (float, Vector4);
	float Mag(const Vector4);
	Vector4 Norm(const Vector4);
}
