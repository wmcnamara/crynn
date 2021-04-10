#include "Rigidbody.h"
namespace crynn
{
	Rigidbody::Rigidbody(RigidbodyDef def, Transform& transform) : m_transform(transform)
	{
		assert(Physics::IsInit() && "Please initialise the physics engine with Physics::Init()");

		body = Physics::GetScene()->CreateBody(def);
	}

	Rigidbody::~Rigidbody()
	{
		Physics::GetScene()->RemoveBody(body);
	}

	void Rigidbody::AddBox(Vec3 offset, Mat3 rotation, Vec3 extents)
	{
		BoxDef def;
		q3Transform tx;

		tx.position = offset;
		tx.rotation = rotation;
		def.Set(tx, extents);

		body->AddBox(def);
	}
}