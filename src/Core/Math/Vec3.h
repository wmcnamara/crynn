#pragma once
#include <cmath>
#include <ostream>
#include <glm/glm.hpp>

#define VEC3_ZERO Vec3(0.0f, 0.0f, 0.0f)
#define VEC3INT_ZERO Vec3Int(0, 0, 0)

namespace crynn
{
	class Vec3 : public glm::vec3
	{
	public:
		Vec3() : glm::vec3(0, 0, 0) {}
		Vec3(float _x, float _y, float _z);

		/// <summary>
		/// Parses vertexTextStart for three floating point variables, and constructs a Vec3 from them.
		/// Expected in the general format: "-1.0 1.0 1.0", or something similar.
		/// Cannot contain other text like letters. Spaces between letters is ok.
		/// </summary>
		/// <param name="vertexTextStart">String to parse for a Vec3</param>
		/// <returns>A Vec3 constructed from the parameters. Will return 0.0 for any component (xyz)
		/// that fails to properly parse.
		/// </returns>
		static Vec3 Parse(const char* vertexTextStart);

		friend std::ostream& operator<< (std::ostream& out, const Vec3& other);
	};

	class Vec3Int : glm::ivec3
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

		/// <summary>
		/// Parses textStart for three integer variables, and constructs a Vec3Int from them.
		/// Expected in the general format: "-1 1 1", or something similar.
		/// Cannot contain other text like letters. Spaces between letters is ok.
		/// </summary>
		/// <param name="vertexTextStart">String to parse for a Vec3Int</param>
		/// <returns>A Vec3Int constructed from the parameters. Will return 0.0 for any component (xyz) that fails to properly parse.
		/// </returns>
		Vec3Int Parse(const char* textStart);

		//Euclidean length of this vector.
		float Length() const;

		static int Dot(const Vec3Int vec1, const Vec3Int vec2);

		int x = 0, y = 0, z;
	};
}