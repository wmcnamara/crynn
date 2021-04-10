#include "Physics.h"

namespace crynn
{
	void Physics::Init()
	{
		scene = new q3Scene(1.0 / 60.0);

		initialised = true;
	}

	void Physics::UnInit()
	{
		delete scene;

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
}