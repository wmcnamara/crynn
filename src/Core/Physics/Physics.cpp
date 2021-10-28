#include "Physics.h"
#include "../../Engine.h"
#include <memory>
#include "../EventListener.h"

namespace crynn
{
	void Physics::Init(std::shared_ptr<Engine> engine)
	{
		m_engine = engine;
		scene = new q3Scene(1.0f / 60.0f);

		stepID = engine->events.OnBeforeUpdate.AddHandler([](FrameEventData dt) { Physics::Step(); }); //step the physics engine

		initialised = true;
	}

	void Physics::UnInit()
	{
		assert(Physics::IsInit()); //assert to prevent double uninit

		delete scene;

		m_engine->events.OnBeforeUpdate.RemoveHandler(stepID);
		initialised = false;
	}

	bool Physics::IsInit()
	{
		return initialised;
	}

	q3Scene* Physics::GetScene()
	{
		return scene;
	}

	void Physics::Step()
	{
		scene->Step();
	}
}