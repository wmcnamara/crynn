#include "CrynnObject.h"
namespace Crynn
{
	CrynnObject::CrynnObject() : ID(GenerateID()) {}

	int CrynnObject::GenerateID()
	{
		static uint32_t id = 0;
		return id++;
	}
}