#pragma once
#include <cmath>
#include "imgui/imgui.h" //Needed for conversion constructors

namespace crynn
{
	class Vec2Int
	{
	public:
		Vec2Int() = default;
		Vec2Int(int _x, int _y);

		//arithmetic overloads
		Vec2Int operator+(const Vec2Int& other) const { return Vec2Int(x + other.x, y + other.y); }
		Vec2Int operator-(const Vec2Int& other) const { return Vec2Int(x - other.x, y - other.y); }

		Vec2Int operator*(int n) const { return Vec2Int(x * n, y * n); }
		Vec2Int operator/(int n) const { return Vec2Int(x / n, y / n); }

		int Dot(const Vec2Int& other);

		operator ImVec2() { return ImVec2(static_cast<float>(x), static_cast<float>(y)); } //Convert to ImVec2

		//Euclidean distance of this vector.
		float Length() const;

		//Calculates a dot product between vec1 and vec2
		static int Dot(const Vec2Int vec1, const Vec2Int vec2);

		int x = 0, y = 0;
	};

	class Vec2
	{
	public:
		Vec2() = default;
		Vec2(float _x, float _y);

		//arithmetic overloads
		Vec2 operator+(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
		Vec2 operator-(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }

		Vec2 operator*(float n) const { return Vec2(x * n, y * n); }
		Vec2 operator/(float n) const { return Vec2(x / n, y / n); }

		float Dot(const Vec2& other);

		//Euclidean distance of this vector.
		float Length() const;

		static float Dot(const Vec2 vec1, const Vec2 vec2);

		float x = 0, y = 0;
	};
}