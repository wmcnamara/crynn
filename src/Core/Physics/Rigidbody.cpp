#include "Rigidbody.h"
namespace crynn
{
	Rigidbody::Rigidbody(q3BodyType bodyT, Transform& transform, Box defaultBox) : m_transform(transform)
	{
		assert(Physics::IsInit()); //Please initialise the physics engine with Physics::Init()

		//Add state update event
		eventID = Application::OnBeforeUpdate.AddHandler([this](double dt) { Rigidbody::UpdateTransformData(); });

		//Create the q3Body
		q3BodyDef def;
		def.position = transform.GetPosition();
		def.bodyType = bodyT;
		body = Physics::GetScene()->CreateBody(def);

		//Create the q3Box
		q3BoxDef bdef;

		q3Transform tr;
		tr.position = defaultBox.position;
		tr.rotation = defaultBox.defaultRotation;

		bdef.Set(tr, defaultBox.extents);

		body->AddBox(bdef);
	}

	Rigidbody::~Rigidbody()
	{
		Application::OnBeforeUpdate.RemoveHandler(eventID);

		body->RemoveAllBoxes();
		Physics::GetScene()->RemoveBody(body);
	}

	void Rigidbody::AddBox(const Box& box)
	{
		BoxDef def;
		q3Transform tx;
		q3Identity(tx);
		tx.position = box.position;
		tx.rotation = box.defaultRotation;
		def.Set(tx, box.extents);

		body->AddBox(def);
	}

	void Rigidbody::UpdateTransformData()
	{
		const q3Transform& tr = body->GetTransform();
		m_transform.SetPosition(tr.position);
	}

	void Rigidbody::AddForceWorld(Vec3 worldForceVector)
	{
		body->ApplyLinearForce(worldForceVector);
	}
}