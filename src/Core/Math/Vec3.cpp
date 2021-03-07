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

	Vec3 Vec3::Parse(const char* vertexTextStart)
	{
		//Get vector components
		float x = 0.0f, y = 0.0f, z = 0.0f;
		char* nextFloatEnd; //used in strtof. check strtof docs to understand

		//Parse the vertex values
		x = strtof(vertexTextStart, &nextFloatEnd);
		y = strtof(nextFloatEnd, &nextFloatEnd);
		z = strtof(nextFloatEnd, NULL);

		//Create Vec3
		return Vec3(x, y, z);
	}

	std::ostream& operator<< (std::ostream& out, const Vec3& other)
	{
		out << "X: " << other.x << " Y: " << other.y << " Z: " << other.z;

		return out;
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