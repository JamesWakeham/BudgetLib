#include "MathFuncs.h"

namespace MathFuncs
{
	Vector2::Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2::~Vector2()
	{

	}

	Vector2::Vector2(const float _x, const float _y)
	{
		x = _x;
		y = _y;
	}

	Vector2::Vector2(const float _x)
	{
		x = _x;
		y = 0;
	}

	float Vector2::Dot(Vector2 rhs)
	{
		return (x*rhs.x) + (y*rhs.y);
	}

	float Vector2::Magnitude()
	{
		return Mag(Vector4(x,y));
	}

	Vector2 Vector2::Normalize()
	{
		Vector4 temp = Norm(Vector4(x, y));
		return Vector2(temp.x, temp.y);
	}

	Vector2 Vector2::operator+(const Vector2 rhs)
	{
		Vector2 temp;
		temp.x = x + rhs.x;
		temp.y = y + rhs.y;
		return temp;
	}

	Vector2 Vector2::operator-(const Vector2 rhs)
	{
		Vector2 temp;
		temp.x = x - rhs.x;
		temp.y = y - rhs.y;
		return temp;
	}

	Vector2 Vector2::operator*(const float f)
	{
		Vector2 temp;
		temp.x = x * f;
		temp.y = y * f;
		return temp;
	}

	Vector3::Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}	
	Vector3::Vector3(const float _x, const float _y, const float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3::Vector3(const float _x, const float _y)
	{
		x = _x;
		y = _y;
	}

	Vector3::Vector3(const float _x)
	{
		x = _x;
	}
	float Vector3::Dot(Vector3 rhs)
	{
		return (x*rhs.x) + (y*rhs.y) + (z*rhs.z);
	}
	Vector3 Vector3::Cross(Vector3 rhs)
	{
		return Vector3((y*rhs.z)-(z*rhs.y),(z*rhs.x)-(x*rhs.z),(x*rhs.y)-(y*rhs.x));
	}
	float Vector3::Magnitude()
	{
		return Mag(Vector4(x, y, z));
	}
	Vector3 Vector3::Normalize()
	{
		Vector4 temp = Norm(Vector4(x, y, z));
		return Vector3(temp.x,temp.y,temp.z);
	}
	Vector3 Vector3::operator+(const Vector3 rhs)
	{
		Vector3 temp;
		temp.x = x + rhs.x;
		temp.y = y + rhs.y;
		temp.z = z + rhs.z;
		return temp;
	}
	Vector3 Vector3::operator-(const Vector3 rhs)
	{
		Vector3 temp;
		temp.x = x - rhs.x;
		temp.y = y - rhs.y;
		temp.z = z - rhs.z;
		return temp;
	}
	Vector3 Vector3::operator*(const float f)
	{
		Vector3 temp;
		temp.x = x * f;
		temp.y = y * f;
		temp.z = z * f;
		return temp;
	}
	Vector3::~Vector3()
	{

	}
	Vector4::Vector4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	Vector4::~Vector4()
	{

	}

	Vector4::Vector4(const float _x, const float _y, const float _z, const float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	Vector4::Vector4(const float _x, const float _y, const float _z)
	{
		x = _x;
		y = _y;
		z = _z;
		w = 0;
	}

	Vector4::Vector4(const float _x, const float _y)
	{
		x = _x;
		y = _y;
		z = 0;
		w = 0;
	}

	Vector4::Vector4(const float _x)
	{
		x = _x;
		y = 0;
		z = 0;
		w = 0;
	}

	float Vector4::Dot(Vector4 rhs)
	{
		return (x*rhs.x) + (y*rhs.y) + (z*rhs.z) + (w*rhs.w);
	}

	Vector4 Vector4::Cross(Vector4 rhs)
	{
		//TODO: figure out what to do with w
		return Vector4((y*rhs.z) - (z*rhs.y), (z*rhs.x) - (x*rhs.z), (x*rhs.y) - (y*rhs.x), w);
	}

	float Vector4::Magnitude()
	{
		return Mag(Vector4(x,y,z,w));
	}

	Vector4 Vector4::Normalize()
	{
		return Norm(Vector4(x, y, z, w));
	}

	Vector4 Vector4::operator+(const Vector4 rhs)
	{
		Vector4 temp;
		temp.x = x + rhs.x;
		temp.y = y + rhs.y;
		temp.z = z + rhs.z;
		temp.w = w + rhs.w;
		return temp;
	}

	Vector4 Vector4::operator-(const Vector4 rhs)
	{
		Vector4 temp;
		temp.x = x - rhs.x;
		temp.y = y - rhs.y;
		temp.z = z - rhs.z;
		temp.w = w - rhs.w;
		return temp;
	}

	Vector4 Vector4::operator*(const float f)
	{
		Vector4 temp;
		temp.x = x * f;
		temp.y = y * f;
		temp.z = z * f;
		temp.w = w * f;
		return temp;
	}

	Matrix2::Matrix2()
	{
		value[0][0] = 0;
		value[1][0] = 0;
		value[0][1] = 0;
		value[1][1] = 0;
	}

	Matrix2::~Matrix2()
	{
	}

	Matrix2::Matrix2(const float _x, const float _y, const float _z, const float _w)
	{
		value[0][0] = _x;
		value[1][0] = _y;

		value[0][1] = _z;
		value[1][1] = _w;
	}

	Matrix2 Matrix2::operator*(const Matrix2 rhs)
	{
		///steps
		// a[2,2] * b[2,2] = c[2,2]
		//crate array which is mat [a.colum][mat b.row]
		//the first entry (ie. c[0,0]) will be (a[0,0] * b[0,0]) + (a[1,0] * b[0,1])
		//the second (ie. c[0,1]) will be (a[0,0] * b[1,0]) + (a[1,0] * b[1,1])
		//and so on
		Matrix2 ans = Matrix2();
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					ans.value[i][j] += value[i][k] * rhs.value[k][j];
				}
			}
		}
		return ans;
	}

	Matrix4::Matrix4()
	{
		value[0][0] = 0;
		value[1][0] = 0;
		value[2][0] = 0;
		value[3][0] = 0;

		value[0][1] = 0;
		value[1][1] = 0;
		value[2][1] = 0;
		value[3][1] = 0;

		value[0][2] = 0;
		value[1][2] = 0;
		value[2][2] = 0;
		value[3][2] = 0;

		value[0][3] = 0;
		value[1][3] = 0;
		value[2][3] = 0;
		value[3][3] = 0;
	}

	Matrix4::~Matrix4()
	{
	}

	Matrix4::Matrix4(const float a, const float b, const float c, const float d, 
					 const float e, const float f, const float g, const float h, 
					 const float i, const float j, const float k, const float l, 
					 const float m, const float n, const float o, const float p)
	{
		value[0][0] = a;
		value[1][0] = b;
		value[2][0] = c;
		value[3][0] = d;

		value[0][1] = e;
		value[1][1] = f;
		value[2][1] = g;
		value[3][1] = h;

		value[0][2] = i;
		value[1][2] = j;
		value[2][2] = k;
		value[3][2] = l;

		value[0][3] = m;
		value[1][3] = n;
		value[2][3] = o;
		value[3][3] = p;
	}

	Matrix4 Matrix4::operator*(const Matrix4 rhs)
	{
		Matrix4 ans = Matrix4();
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					ans.value[i][j] += value[i][k] * rhs.value[k][j];
				}
			}
		}
		return ans;
	}

	Matrix3::Matrix3()
	{
		value[0][0] = 0;
		value[1][0] = 0;
		value[2][0] = 0;

		value[0][1] = 0;
		value[1][1] = 0;
		value[2][1] = 0;

		value[0][2] = 0;
		value[1][2] = 0;
		value[2][2] = 0;
	}

	Matrix3::~Matrix3()
	{
	}

	Matrix3::Matrix3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i)
	{
		value[0][0] = a;
		value[1][0] = b;
		value[2][0] = c;

		value[0][1] = d;
		value[1][1] = e;
		value[2][1] = f;

		value[0][2] = g;
		value[1][2] = h;
		value[2][2] = i;
	}

	Matrix3 Matrix3::operator*(const Matrix3 rhs)
	{
		Matrix3 ans = Matrix3();
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					ans.value[i][j] += value[i][k] * rhs.value[k][j];
				}
			}
		}
		return ans;
	}

	Vector2 operator*(float lhs, Vector2 rhs)
	{
		Vector2 temp;
		temp.x = rhs.x * lhs;
		temp.y = rhs.y * lhs;
		return temp;
	}

	Vector3 operator*(float lhs, Vector3 rhs)
	{
		Vector3 temp;
		temp.x = rhs.x * lhs;
		temp.y = rhs.y * lhs;
		temp.z = rhs.z * lhs;
		return temp;
	}

	Vector4 operator*(float lhs, Vector4 rhs)
	{
		Vector4 temp;
		temp.x = rhs.x * lhs;
		temp.y = rhs.y * lhs;
		temp.z = rhs.z * lhs;
		temp.w = rhs.w * lhs;
		return temp;
	}
	float Mag(const Vector4 vec)
	{
		return sqrt((vec.x*vec.x) + (vec.y*vec.y) + (vec.z*vec.z) + (vec.w*vec.w));
	}
	Vector4 Norm(const Vector4 vec)
	{
		Vector4 temp = Vector4(vec.x, vec.y, vec.z, vec.w);
		float mag = temp.Magnitude();
		return Vector4(temp.x / mag, temp.y / mag, temp.z / mag, temp.w / mag);
	}
}