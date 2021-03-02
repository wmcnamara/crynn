#pragma once
#include <cmath>

namespace crynn
{
	class Vec3
	{
	public:
		Vec3() = default;
		Vec3(float _x, float _y, float _z);

		//arithmetic overloads
		Vec3 operator+(const Vec3& other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
		Vec3 operator-(const Vec3& other) const { return Vec3(x - other.x, y - other.y, z - other.z); }

		Vec3 operator*(float n) const { return Vec3(x * n, y * n, z * n); }
		Vec3 operator/(float n) const { return Vec3(x / n, y / n, z / n); }

		float Dot(const Vec3& other) const;

		//Euclidean length of this vector.
		float Length() const;

		//Performs a dot product between vec1 and vec2
		static float Dot(const Vec3 vec1, const Vec3 vec2);

		float x = 0, y = 0, z;
	};

	class Vec3Int 
	{
	public:
		Vec3Int() = default;
		Vec3Int(int _x, int _y, int _z);

		//arithmetic overloads
		Vec3Int operator+(const Vec3Int & other) const { return Vec3Int(x + other.x, y + other.y, z + other.z); }
		Vec3Int operator-(const Vec3Int & other) const { return Vec3Int(x - other.x, y - other.y, z - other.z); }

		Vec3Int operator*(int n) const { return Vec3Int(x * n, y * n, z * n); }
		Vec3Int operator/(int n) const { return Vec3Int(x / n, y / n, z / n); }

		int Dot(const Vec3Int& other) const;

		//Euclidean length of this vector.
		float Length() const;

		static int Dot(const Vec3Int vec1, const Vec3Int vec2);

		int x = 0, y = 0, z;
	};
}