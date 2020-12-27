#include "Vec2.h"
namespace crynn
{
	Vec2Int::Vec2Int(int x, int y) : x(x), y(x)
	{

	}

	Vec2Int::Vec2Int(Vec2Int&& other) noexcept
	{
		x = other.x;
		y = other.y;

		other.x = 0;
		other.y = 0;
	}

	Vec2Int& Vec2Int::operator=(Vec2Int&& other) noexcept
	{
		if (this != &other)
		{
			x = other.x;
			y = other.y;

			other.x = 0;
			other.y = 0;
		}

		return *this;
	}

	Vec2Int& Vec2Int::operator=(Vec2Int& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	float Vec2Int::GetMagnitude() const
	{
		int xSqr = x * x;
		int ySqr = y * y;

		return std::sqrt(xSqr + ySqr);
	}

	int Vec2Int::Dot(const Vec2Int vec1, const Vec2Int vec2)
	{
		return (vec1.x * vec2.x) + (vec1.y + vec2.y);
	}
}