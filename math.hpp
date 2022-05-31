#pragma once
#include <cmath>

struct Vector2
{
	float x;
	float y;

	Vector2() { }
	Vector2(float x, float y) : x(x), y(y) { }

	Vector2 operator *(Vector2 other)
	{
		return Vector2(other.x * x, other.y * y);
	}

	Vector2 operator *(float other)
	{
		return Vector2(other * x, other * y);
	}

	Vector2 operator +=(Vector2 other)
	{
		return Vector2(other.x + x, other.y + y);
	}

	Vector2 operator +=(float other)
	{
		return Vector2(other + x, other + y);
	}
};

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3() { }
	Vector3(float x, float y, float z) : x(x), y(y), z(z) { }

	Vector3 operator *(Vector3 other)
	{
		return Vector3(other.x * x, other.y * y, other.z * z);
	}

	Vector3 operator *(float other)
	{
		return Vector3(other * x, other * y, other * z);
	}

	Vector3 operator +=(Vector3 other)
	{
		return Vector3(other.x + x, other.y + y, other.z + z);
	}

	Vector3 operator +=(float other)
	{
		return Vector3(other + x, other + y, other + z);
	}
};

class Math
{
public:
	template<typename Num>
	static double GetMagnitude2D(Num x, Num y);
};

template<typename Num>
double Math::GetMagnitude2D(Num x, Num y)
{
	return sqrt((x * x) + (y * y));
}