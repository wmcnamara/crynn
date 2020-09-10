#include "Behaviour.h"

namespace Crynn
{
	Behaviour::Behaviour()
	{		
		//TODO move away from lambdas, as they dont look very nice here.
		//Subscribe events. 
		updateHandlerID = Application::Instance().OnUpdate.AddHandler([this](double deltaTime) { Update(deltaTime); });
		startHandlerID = Application::Instance().OnStart.AddHandler([this]() { Start(); });
		beforeUpdateHandlerID = Application::Instance().OnBeforeUpdate.AddHandler([this](double deltaTime) { BeforeUpdate(deltaTime); });
		beforeCloseHandlerID = Application::Instance().OnBeforeClose.AddHandler([this]() { BeforeClose(); });
	}

	Behaviour::~Behaviour()
	{
		//Unsubscribe events
		Application::Instance().OnUpdate.RemoveHandler(updateHandlerID);
		Application::Instance().OnStart.RemoveHandler(startHandlerID);
		Application::Instance().OnBeforeUpdate.RemoveHandler(beforeUpdateHandlerID);
		Application::Instance().OnBeforeClose.RemoveHandler(beforeCloseHandlerID);
	}
}