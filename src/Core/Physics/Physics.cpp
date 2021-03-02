#include "Physics.h"

namespace crynn
{
	Ray::Ray(Vec3 origin, Vec3 direction, float length) : 
		m_origin(origin), 
		m_dir(direction),
		m_length(length) {}

	bool Ray::CompAABB(AABB& other)
	{
		const float maxSteps = m_length;
		const float step = 0.1;

		for (float len = 0; len < maxSteps; len += step)
		{
			Vec3 p = m_origin + (m_dir * len);

			//check x
			bool x = p.x >= other.Transform.GetPosition().x + other.Size.x;
			
			//check y
			bool y = p.y >= other.Transform.GetPosition().y + other.Size.y;
			
			//check z
			bool z = p.z >= other.Transform.GetPosition().z + other.Size.z;

			if (x && y && z)
				return true;
		}

		return false;
	}
}