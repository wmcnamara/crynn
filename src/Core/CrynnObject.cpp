#include "CrynnObject.h"
namespace Crynn
{
	CrynnObject::CrynnObject() : ID(GenerateID()) {}

	int CrynnObject::GenerateID()
	{
		std::cout << "Crynn Object Created" << std::endl;
		static uint32_t id = 0;
		return id++;
	}
}