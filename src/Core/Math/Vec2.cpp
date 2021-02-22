#include "Vec2.h"
namespace crynn
{
	Vec2Int::Vec2Int(int x, int y) : m_x(x), m_y(x)
	{

	}

	Vec2Int::Vec2Int(Vec2Int&& other) noexcept
	{
		m_x = other.m_x;
		m_y = other.m_y;

		other.m_x = 0;
		other.m_y = 0;
	}

	Vec2Int& Vec2Int::operator=(Vec2Int&& other) noexcept
	{
		if (this != &other)
		{
			m_x = other.m_x;
			m_y = other.m_y;

			other.m_x = 0;
			other.m_y = 0;
		}

		return *this;
	}

	Vec2Int& Vec2Int::operator=(Vec2Int& other)
	{
		m_x = other.m_x;
		m_y = other.m_y;

		return *this;
	}

	int Vec2Int::Dot(const Vec2Int& other)
	{
		return (m_x * other.m_x) + (m_y * other.m_y);
	}

	float Vec2Int::GetMagnitude() const
	{
		int xSqr = m_x * m_x;
		int ySqr = m_y * m_y;

		return std::sqrt(xSqr + ySqr);
	}

	int Vec2Int::Dot(const Vec2Int vec1, const Vec2Int vec2)
	{
		return (vec1.m_x * vec2.m_x) + (vec1.m_y + vec2.m_y);
	}
}