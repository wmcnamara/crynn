#include "Behaviour.h"

namespace Crynn
{
	Behaviour::Behaviour()
	{
		//Subscribe events
		updateHandlerID = Application::Instance().OnUpdate.AddHandler([this](double deltaTime) { Update(deltaTime); });
		startHandlerID = Application::Instance().OnStart.AddHandler([this]() { Start(); });
		beforeUpdateHandlerID = Application::Instance().OnBeforeUpdate.AddHandler([this](double deltaTime) { BeforeUpdate(deltaTime); });
		beforeCloseHandlerID = Application::Instance().OnBeforeClose.AddHandler([this]() { OnBeforeClose; });
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