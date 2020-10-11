#include "CrynnObject.h"
namespace Crynn
{
	CrynnObject::CrynnObject() : ID(GenerateID()) {}

	int CrynnObject::GenerateID()
	{
		static uint32_t id = 0;
		return id++;
	}

	std::shared_ptr<CrynnObject> ObjectManager::CreateObject()
	{
		std::shared_ptr<CrynnObject> obj = std::make_shared<CrynnObject>();
		managedObjects.insert(std::pair<int, std::shared_ptr<CrynnObject>>(obj->GetID(), obj));

		return obj;
	}
	void ObjectManager::DeleteObject(std::shared_ptr<CrynnObject> object)
	{
		managedObjects.erase(object->GetID());
	}
}