#include "CrynnObject.h"

namespace crynn
{
	CrynnObject::CrynnObject() : ID(GenerateID()) {}

	//Copy constructors
	CrynnObject::CrynnObject(const CrynnObject& other) : ID(GenerateID()) {}
	CrynnObject& CrynnObject::operator=(const CrynnObject& other)
	{
		ID = GenerateID();

		return *this;
	}

	//move constructors
	CrynnObject::CrynnObject(CrynnObject&& other) noexcept
	{
		ID = other.ID;
		other.ID = 0;
	}

	CrynnObject& CrynnObject::operator=(CrynnObject&& other) noexcept
	{
		ID = other.ID;
		other.ID = 0;

		return *this;
	}

	OBJID CrynnObject::GenerateID()
	{
		Debug::Log("Crynn Object Created");

		static std::atomic_uint64_t nextID = 0;
		return nextID++;
	}
}