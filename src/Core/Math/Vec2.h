#pragma once
#include <cmath>
#include "imgui.h" //Needed for conversion constructors

namespace crynn
{
	class Vec2
	{
	public:

	private:

	};

	class Vec2Int
	{
	public:
		Vec2Int() = default;
		Vec2Int(int x, int y);

		//Move/copy stuff
		Vec2Int(Vec2Int&& other) noexcept;
		Vec2Int& operator=(Vec2Int&& other) noexcept;
		Vec2Int& operator=(Vec2Int& other);
		Vec2Int(const Vec2Int& other) = default;

		Vec2Int operator+(const Vec2Int& other) const { return Vec2Int(x + other.x, y + other.y); }
		Vec2Int operator-(const Vec2Int& other) const { return Vec2Int(x - other.x, y - other.y); }
		Vec2Int operator*(const Vec2Int& other) const { return Vec2Int(x * other.x, y * other.y); }
		Vec2Int operator/(const Vec2Int& other) const { return Vec2Int(x / other.x, y / other.y); }

		Vec2Int operator+(int other) const { return Vec2Int(x + other, y + other); }
		Vec2Int operator-(int other) const { return Vec2Int(x - other, y - other); }
		Vec2Int operator*(int other) const { return Vec2Int(x * other, y * other); }
		Vec2Int operator/(int other) const { return Vec2Int(x / other, y / other); }

		operator ImVec2() { return ImVec2(static_cast<float>(x), static_cast<float>(y)); } //Convert to ImVec2

		//Euclidean distance of this vector.
		float GetMagnitude() const;

		int x = 0, y = 0;
	};
}