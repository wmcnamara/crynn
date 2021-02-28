#include "Vec2.h"
namespace crynn
{
	Vec2Int::Vec2Int(int x, int y) : m_x(x), m_y(x)
	{

	}

	int Vec2Int::Dot(const Vec2Int& other)
	{
		return (m_x * other.m_x) + (m_y * other.m_y);
	}

	float Vec2Int::Length() const
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