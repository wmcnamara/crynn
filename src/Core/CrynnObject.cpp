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

	bool CrynnObject::operator==(CrynnObject& other)
	{
		return ID == other.ID;
	}

	void* CrynnObject::operator new(size_t size)
	{
		return malloc(size);
	}

	void CrynnObject::operator delete(void* obj)
	{
		free(obj);
	}

	int CrynnObject::GenerateID()
	{
		Debug::Log("Crynn Object Created");
		static uint64_t id = 0;
		return id++;
	}
}