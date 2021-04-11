#pragma once
#include "../Physics/Collision/AABB.h"
#include "physics/src/q3.h"
#include "../Application.h"

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
		
		//Steps the physics engine
		static void Step();
	private:
		static inline unsigned int stepID = 0;
		static inline bool initialised = false;
		static inline q3Scene* scene = nullptr;
	};
}