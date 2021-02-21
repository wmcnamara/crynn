#include "Scene.h"
#include <exception>

namespace crynn
{
	void Scene::RemoveObject(int& ID)
	{
		if (!managedObjects.contains(ID))
			throw std::runtime_error("Attempting to remove destroyed object");

		markedForDealloc.insert(ID);

		ID = 0;
	}

	void Scene::ClearObjects()
	{
		managedObjects.clear();
	}

	int Scene::GetObjectCount()
	{
		return managedObjects.size();
	}

	void Scene::Clean()
	{
		for (int ID : markedForDealloc) 
		{
			managedObjects.erase(ID);
		}
	}
}