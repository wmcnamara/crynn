#pragma once
#include "Core/EventListener.h"
#include "Core/Transform.h"
#include "glm/glm.hpp"

namespace Crynn
{
	/// <summary>
	/// Represents an aligned axis bounding box.
	/// </summary>
	struct AABB
	{
		Transform& transform;
		glm::vec3 Size;
	};

	/// <summary>
	/// Provides functions for testing collisions with AABB's
	/// </summary>
	class AABBSolver
	{
		static bool Compare(const AABB& one, const AABB& two);
	};
}