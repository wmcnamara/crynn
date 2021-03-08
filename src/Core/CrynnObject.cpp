#include "CrynnObject.h"
namespace crynn
{
	CrynnObject::CrynnObject() : ID(GenerateID()) {}
	CrynnObject::CrynnObject(const CrynnObject& other) : ID(GenerateID()) {}

	OBJID CrynnObject::GenerateID()
	{
		Debug::Log("Crynn Object Created");

		static std::atomic_uint64_t nextID = 0;
		return nextID++;
	}
}