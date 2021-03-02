#pragma once
#include "../../Core/Math/Vec3.h"
#include "../Physics/Collision/AABB.h"

namespace crynn
{
	class Ray 
	{
	public:
		//Constructs a ray from a given origin, direction and length. Direction must be normalized.
		Ray(Vec3 origin, Vec3 direction, float length);

		bool CompAABB(AABB& other);
	private:
		Vec3 m_origin, m_dir;
		float m_length;
	};
}