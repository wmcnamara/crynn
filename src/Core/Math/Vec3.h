#pragma once
#include <cmath>
#include "imgui/imgui.h" //Needed for conversion constructors

namespace crynn
{
	class Vec3
	{
	public:
		Vec3() = default;
		Vec3(float x, float y, float z);

		//arithmetic overloads
		Vec3 operator+(const Vec3& other) const { return Vec3(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z); }
		Vec3 operator-(const Vec3& other) const { return Vec3(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z); }

		Vec3 operator*(float n) const { return Vec3(m_x * n, m_y * n, m_z * n); }
		Vec3 operator/(float n) const { return Vec3(m_x / n, m_y / n, m_z / n); }

		float Dot(const Vec3& other) const;

		//Euclidean length of this vector.
		float Length() const;

		static int Dot(const Vec3 vec1, const Vec3 vec2);

		float m_x = 0, m_y = 0, m_z;
	};
}