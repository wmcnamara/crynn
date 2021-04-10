#pragma once
#include "../Physics/Collision/AABB.h"
#include "qu3e/src/q3.h"

namespace crynn
{
	/// <summary>
	/// This class manages q3 physics scenes. It is not meant to be instantiated
	/// </summary>
	class Physics 
	{
	public:
		Physics() = delete;
		~Physics() = delete;
		
		static void Init(); //Initialises the physics engine
		static void UnInit(); //Deinitialises the physics engine

		static bool IsInit(); //Is the physics engine initialised?

		static q3Scene* GetScene();
	private:
		static inline bool initialised = false;
		static inline q3Scene* scene = nullptr;
	};
}