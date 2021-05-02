#include "Scene.h"
#include <exception>

namespace crynn
{
	void Scene::RemoveObject(OBJID ID)
	{
		if (!managedObjects.contains(ID))
			throw std::runtime_error("Attempting to remove destroyed or nonexistent object");

		markedForDealloc.insert(ID);
	}

	void Scene::ClearObjects()
	{
		managedObjects.clear();
	}

	uint64_t Scene::GetObjectCount()
	{
		return managedObjects.size();
	}

	void Scene::Clean()
	{
		for (uint64_t ID : markedForDealloc) 
		{
			managedObjects.erase(ID);
		}
	}
}