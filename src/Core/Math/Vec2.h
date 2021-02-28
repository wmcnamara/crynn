#pragma once
#include <cmath>
#include "imgui/imgui.h" //Needed for conversion constructors

namespace crynn
{
	class Vec2Int
	{
	public:
		Vec2Int() = default;
		Vec2Int(int x, int y);

		//arithmetic overloads
		Vec2Int operator+(const Vec2Int& other) const { return Vec2Int(m_x + other.m_x, m_y + other.m_y); }
		Vec2Int operator-(const Vec2Int& other) const { return Vec2Int(m_x - other.m_x, m_y - other.m_y); }

		Vec2Int operator*(int n) const { return Vec2Int(m_x * n, m_y * n); }
		Vec2Int operator/(int n) const { return Vec2Int(m_x / n, m_y / n); }

		int Dot(const Vec2Int& other);

		operator ImVec2() { return ImVec2(static_cast<float>(m_x), static_cast<float>(m_y)); } //Convert to ImVec2

		//Euclidean distance of this vector.
		float Length() const;

		static int Dot(const Vec2Int vec1, const Vec2Int vec2);

		int m_x = 0, m_y = 0;
	};
}