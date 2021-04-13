#include "Physics.h"

namespace crynn
{
	void Physics::Init()
	{
		scene = new q3Scene(1.0 / 60.0);

		stepID = Application::OnBeforeUpdate.AddHandler([](double dt) { Physics::Step(); }); //step the physics engine

		initialised = true;
	}

	void Physics::UnInit()
	{
		assert(Physics::IsInit()); //assert to prevent double uninit

		delete scene;

		Application::OnBeforeUpdate.RemoveHandler(stepID);
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