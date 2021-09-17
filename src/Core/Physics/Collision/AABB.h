#pragma once
#include <functional>
#include "../../Math/Math.h"

namespace crynn
{
	class Transform;

	/// <summary>
	/// Represents an aligned axis bounding box, and provides a set of functions to compare collisions.
	/// Useful for simple, rudimentary and fast AABB collision detection in simple use cases.
	/// 
	/// Does not work with Rigidbody, and provides no collision resolution. It will just detect collisions. For full
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