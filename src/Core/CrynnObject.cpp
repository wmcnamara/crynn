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
		std::swap(ID, other.ID);
		other.ID = 0;
	}

	CrynnObject& CrynnObject::operator=(CrynnObject&& other) noexcept
	{
		std::swap(ID, other.ID);
		other.ID = 0;

		return *this;
	}

	OBJID CrynnObject::GenerateID()
	{
#ifdef CRYNN_GENID_LOG
		std::cout << "Crynn Object Created\n";
#endif
		static std::atomic_uint64_t nextID = 0;
		return nextID++;
	}
}