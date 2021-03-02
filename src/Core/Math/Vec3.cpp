#include "Vec2.h"
#include "Vec3.h"
namespace crynn
{
	Vec3::Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
	{

	}

	float Vec3::Dot(const Vec3& other) const
	{
		return (x * other.x) + (y + other.y) + (z + other.z);
	}

	float Vec3::Length() const
	{
		float xSqr = x * x;
		float ySqr = y * y;
		float zSqr = z * z;

		return std::sqrt(xSqr + ySqr + zSqr);
	}

	float Vec3::Dot(const Vec3 vec1, const Vec3 vec2)
	{
		return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	}

	/////////////
	///VEC3INT///
	/////////////

	Vec3Int::Vec3Int(int _x, int _y, int _z) : x(_x), y(_y), z(_z) { }

	int Vec3Int::Dot(const Vec3Int& other) const
	{
		return (x * other.x) + (y * other.y) + (z * other.z);
	}

	float Vec3Int::Length() const
	{
		int xSqr = x * x;
		int ySqr = y * y;
		int zSqr = z * z;

		return std::sqrtf(xSqr + ySqr + zSqr);
	}

	int Vec3Int::Dot(const Vec3Int vec1, const Vec3Int vec2)
	{
		return (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	}
}