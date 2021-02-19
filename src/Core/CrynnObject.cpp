#include "CrynnObject.h"
namespace crynn
{
	CrynnObject::CrynnObject() : ID(GenerateID()) {}
	CrynnObject::CrynnObject(const CrynnObject& other) : ID(GenerateID()) {}

	CrynnObject& CrynnObject::operator=(const CrynnObject& other)
	{
		ID = other.ID;

		return *this;
	}

	int CrynnObject::GenerateID()
	{
		Debug::Log("Crynn Object Created");
		static uint64_t id = 0;
		return id++;
	}
}