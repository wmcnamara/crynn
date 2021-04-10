#include "Rigidbody.h"
namespace crynn
{
	Rigidbody::Rigidbody(RigidbodyDef def)
	{
		assert(Physics::IsInit() && "Please initialise the physics engine with Physics::Init()");

		body = Physics::GetScene()->CreateBody(def);
	}

	Rigidbody::~Rigidbody()
	{
		Physics::GetScene()->RemoveBody(body);
	}
}