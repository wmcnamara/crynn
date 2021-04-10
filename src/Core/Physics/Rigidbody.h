#pragma once
#include "Physics.h"


//Document this

namespace crynn
{
	using RigidbodyDef = q3BodyDef;

	class Rigidbody
	{
	public:
		Rigidbody(RigidbodyDef def);
		virtual ~Rigidbody();

	private:
		q3Body* body;
	};
}