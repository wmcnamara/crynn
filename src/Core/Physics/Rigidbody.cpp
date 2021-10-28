#include "Rigidbody.h"
#include "../../Engine.h"
#include "../Transform.h"
#include "../EventListener.h"

namespace crynn
{
	Rigidbody::Rigidbody(q3BodyType bodyT, Transform& transform, Box defaultBox, std::shared_ptr<Engine> engine) : m_transform(transform), m_engine(engine)
	{
		assert(Physics::IsInit()); //Please initialise the physics engine with Physics::Init()

		//Add state update event
		m_eventID = engine->events.OnUpdate.AddHandler([this](FrameEventData data) { this->UpdateTransformData(); });

		//Create the q3Body
		q3BodyDef def;
		def.position = transform.GetPosition();
		def.bodyType = bodyT;
		m_body = Physics::GetScene()->CreateBody(def);

		//Create the q3Box
		q3BoxDef bdef;

		q3Transform tr;
		tr.position = defaultBox.position;
		tr.rotation = defaultBox.defaultRotation;

		bdef.Set(tr, defaultBox.extents);

		m_body->AddBox(bdef);
	}

	Rigidbody::~Rigidbody()
	{
		m_engine->events.OnBeforeUpdate.RemoveHandler(m_eventID);

		m_body->RemoveAllBoxes();
		Physics::GetScene()->RemoveBody(m_body);
	}

	void Rigidbody::AddBox(const Box& box)
	{
		BoxDef def;
		q3Transform tx;
		q3Identity(tx);
		tx.position = box.position;
		tx.rotation = box.defaultRotation;
		def.Set(tx, box.extents);

		m_body->AddBox(def);
	}

	void Rigidbody::UpdateTransformData()
	{
		const q3Transform& tr = m_body->GetTransform();
		m_transform.SetPosition(tr.position);
	}

	void Rigidbody::AddForceWorld(Vec3 worldForceVector)
	{
		m_body->ApplyLinearForce(worldForceVector);
	}
}