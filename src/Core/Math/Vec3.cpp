#include "Vec2.h"
#include "Vec3.h"
namespace crynn
{
	Vec3::Vec3(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
	{

	}

	float Vec3::Dot(const Vec3& other) const
	{
		return (m_x * other.m_x) + (m_y + other.m_y) + (m_z + other.m_z);
	}

	float Vec3::Length() const
	{
		float xSqr = m_x * m_x;
		float ySqr = m_y * m_y;
		float zSqr = m_z * m_z;

		return std::sqrt(xSqr + ySqr + zSqr);
	}

	int Vec3::Dot(const Vec3 vec1, const Vec3 vec2)
	{
		return (vec1.m_x * vec2.m_x) + (vec1.m_y * vec2.m_y) + (vec1.m_z * vec2.m_z);
	}
}