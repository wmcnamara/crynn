#pragma once
#include "../../../Core/EventListener.h"
#include "../../../Core/Transform.h"
#include "glm/glm.hpp"

namespace crynn
{
	/// <summary>
	/// Represents an aligned axis bounding box.
	/// </summary>
	class AABB
	{
	public:
		AABB(Transform& transform, glm::vec3 size) : Transform(transform), Size(size) {}

		/// <summary>
		/// Compares two AABB's for collisions.
		/// </summary>
		/// <param name="one">The first AABB to compare.</param>
		/// <param name="two">The second AABB to compare.</param>
		/// <returns>True if the two AABB's are colliding.</returns>
		static bool Compare(const AABB& one, const AABB& two);

		/// Returns true if 2 AABB's are colliding, and runs func with the two AABB's passed as parameters if they are collidiing.
		static bool Compare(const AABB& one, const AABB& two, std::function<void(const AABB& one, const AABB& two)> func);

		Transform& Transform;
		glm::vec3 Size;
	};
}