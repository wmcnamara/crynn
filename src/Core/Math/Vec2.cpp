#include "Vec2.h"
namespace crynn
{
	Vec2Int::Vec2Int(int _x, int _y) : x(_x), y(_y) { }

	int Vec2Int::Dot(const Vec2Int& other)
	{
		return (x * other.x) + (y * other.y);
	}

	float Vec2Int::Length() const
	{
		int xSqr = x * x;
		int ySqr = y * y;

		return std::sqrt(xSqr + ySqr);
	}

	int Vec2Int::Dot(const Vec2Int vec1, const Vec2Int vec2)
	{
		return (vec1.x * vec2.x) + (vec1.y * vec2.y);
	}

	Vec2::Vec2(float _x, float _y) : x(_x), y(_y) { }

	float Vec2::Dot(const Vec2& other)
	{
		return (x * other.x) + (y * other.y);
	}

	float Vec2::Length() const
	{
		float xSqr = x * x;
		float ySqr = y * y;

		return std::sqrt(xSqr + ySqr);
	}

	float Vec2::Dot(const Vec2 vec1, const Vec2 vec2)
	{
		return (vec1.x * vec2.x) + (vec1.y * vec2.y);
	}
}