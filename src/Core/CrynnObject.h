#pragma once
#include <memory>
#include <unordered_map>
#include "EventListener.h"

namespace Crynn
{
	class CrynnObject : EventListener 
	{
	public:
		CrynnObject();
		int GetID() { return ID; }
	private:
		int ID;
		static int GenerateID();
	};

	class ObjectManager
	{
	public:
		std::shared_ptr<CrynnObject> CreateObject();
		void DeleteObject(std::shared_ptr<CrynnObject> object);
		
	private:
		std::unordered_map<int, std::shared_ptr<CrynnObject>> managedObjects;
	};
}