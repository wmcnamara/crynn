#pragma once
#include "Application.h"

namespace Crynn 
{
	class Behaviour
	{
	protected:
		virtual void Update(double deltaTime) = 0;
		virtual void Start() = 0;

		Behaviour();
		~Behaviour();

	private:
		int updateHandlerID; //Used to remove the update handler when this object is destructed.
		int startHandlerID; //Used to remove the start handler when this object is destructed.
	};
}

