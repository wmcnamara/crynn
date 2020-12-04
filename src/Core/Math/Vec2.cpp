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
		std::swap(x, other.x);
		std::swap(y, other.y);

		return *this;
	}

	float Vec2Int::GetMagnitude() const
	{
		int xSqr = x * x;
		int ySqr = y * y;

		return std::sqrt(x + y);
	}
}