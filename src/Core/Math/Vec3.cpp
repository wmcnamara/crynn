#include "Vec2.h"
#include "Vec3.h"

namespace crynn
{
	Vec3::Vec3(float _x, float _y, float _z) : glm::vec3(_x, _y, _z) {}

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

	Vec3Int Vec3Int::Parse(const char* textStart)
	{
		//Get vector components
		int x = 0, y = 0, z = 0;
		char* nextIntEnd; //used in strtof. check strtof docs to understand

		//Parse the vertex values.
		//These are casted to integers because the data is generally specified as floats, so its retrieved as a float and converted.
		x = (int)strtof(textStart, &nextIntEnd);
		y = (int)strtof(nextIntEnd, &nextIntEnd);
		z = (int)strtof(nextIntEnd, NULL);

		//Create Vec3
		return Vec3Int(x, y, z);
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