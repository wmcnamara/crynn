#pragma once
#include <vector>
#include <unordered_set>
#include "CrynnObject.h"
#include "EventListener.h"

namespace crynn 
{
	//Manages allocation for scene object
	class Scene
	{
	public:
		//Constructs and adds an object to the managed list. Must be of type CrynnObject
		template<typename CrynnObjT, typename... ParamT>
		inline static std::weak_ptr<CrynnObjT> CreateObject(ParamT... params)
		{
			static_assert(std::is_base_of <CrynnObject, CrynnObjT>(), "Create object can only be called on CrynnObjects");

			std::shared_ptr<CrynnObjT> newPtr = std::make_shared<CrynnObjT>(params...);
			managedObjects.insert({ newPtr->GetID(), newPtr });

			return std::weak_ptr<CrynnObjT>(newPtr);
		}

		static void RemoveObject(OBJID ID); ///Removes an object from the managed list
		static void ClearObjects(); //Removes every object from the managed list.
		static uint64_t GetObjectCount(); //returns the number of managed objects in the scene

		//Frees unused memory marked for deallocation.
		static void Clean();

		//Returns a const reference to the map of managed objects
		static const std::unordered_map<OBJID, std::shared_ptr<CrynnObject>>& GetManagedObjects() { return managedObjects; }
	private:
		//List of objects managed by the scene class
		inline static std::unordered_map<OBJID, std::shared_ptr<CrynnObject>> managedObjects;

		//ID's of objects marked for deallocation at the end of the frame
		inline static std::unordered_set<OBJID> markedForDealloc;
	};
}


