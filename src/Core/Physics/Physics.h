#pragma once
#include "../Physics/Collision/AABB.h"
#include "q3.h"
#include "../Application.h"


namespace crynn
{
	class Engine;

	/// <summary>
	/// This class manages q3 physics scenes. It is not meant to be instantiated
	/// </summary>
	class Physics 
	{
	public:
		Physics() = delete;
		~Physics() = delete;
		
		static void Init(std::shared_ptr<Engine> engine); //Initialises the physics engine
		static void UnInit(); //Deinitialises the physics engine

		static bool IsInit(); //Is the physics engine initialised?

		static q3Scene* GetScene();
		
		//Steps the physics engine
		static void Step();
	private:
		static inline unsigned int stepID = 0;
		static inline bool initialised = false;
		static inline q3Scene* scene = nullptr;
		static inline std::shared_ptr<Engine> m_engine;
	};
}