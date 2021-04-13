#include "Rigidbody.h"
namespace crynn
{
	Rigidbody::Rigidbody(q3BodyType bodyT, Transform& transform) : m_transform(transform)
	{
		assert(Physics::IsInit()); //Please initialise the physics engine with Physics::Init()

		eventID = Application::OnBeforeUpdate.AddHandler([this](double dt) { Rigidbody::UpdateTransformData(); });
		q3BodyDef def;
		def.position = transform.GetPosition();
		def.bodyType = bodyT;

		body = Physics::GetScene()->CreateBody(def);
	}

	Rigidbody::~Rigidbody()
	{
		Application::OnBeforeUpdate.RemoveHandler(eventID);

		Physics::GetScene()->RemoveBody(body);
	}

	void Rigidbody::AddBox(Vec3 offset, Vec3 extents, Mat3 rotation)
	{
		BoxDef def;
		q3Transform tx;

		tx.position = offset;
		tx.rotation = rotation;
		def.Set(tx, extents);

		body->AddBox(def);
	}

	void Rigidbody::UpdateTransformData()
	{
		const q3Transform& tr = body->GetTransform();
		m_transform.SetPosition(tr.position);
	}
}