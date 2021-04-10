#pragma once
#include "../../../Core/EventListener.h"
#include "../../../Core/Transform.h"
#include "glm/glm.hpp"

/*
	File: AABB.h

	Author:	Weston McNamara
	Last Revised: 4/10/2021

	Copyright (c) 2021 Weston McNamara https://www.wmcnamara.com/

	This file is subject to the terms and conditions defined in the MIT License.
	https://mit-license.org/
*/

namespace crynn
{
	/// <summary>
	/// Represents an aligned axis bounding box, and provides a set of functions to compare collisions.
	/// Useful for simple, rudimentary and fast AABB collision in simple use cases.
	/// 
	/// Does not work with Rigidbody, and collision resolution. It will just detect collisions. For full
	/// rigidbody dynamics and hit resolution, check Rigidbody.h, and the "Physics" page on the Crynn Github wiki.
	/// </summary>
	class AABB
	{
	public:
		AABB(const Transform& transform, Vec3 size) : Transform(transform), Size(size) {}

		// Returns true if AABB one and two are intersecting
		static bool Compare(const AABB& one, const AABB& two);

		// Returns true if 2 AABB's are intersecting, and runs func with the two AABB's passed as parameters.
		static bool Compare(const AABB& one, const AABB& two, std::function<void(const AABB& one, const AABB& two)> func);

		const Transform& Transform;
		Vec3 Size;
	};
}