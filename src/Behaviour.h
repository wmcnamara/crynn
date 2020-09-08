#pragma once
#include "Application.h"

namespace Crynn 
{
	class Behaviour
	{
	protected:
		virtual void Update(double deltaTime) {};
		virtual void Start() {};
		virtual void BeforeUpdate() {};

		Behaviour();
		~Behaviour();

	private:
		//Used to remove handlers when this object is destructed.
		int updateHandlerID; 
		int startHandlerID;
		int beforeUpdateHandlerID;
	};
}

