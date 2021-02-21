#include "EventListener.h"

namespace crynn
{
	EventListener::EventListener()
	{
		SubscribeEvents();
	}

	EventListener::~EventListener()
	{
		UnsubscribeEvents();
	}

	void EventListener::SubscribeEvents()
	{		
		//TODO move away from lambdas, as thaey dont look very nice here.
		//Subscribe events. 	

		updateHandlerID = Application::OnUpdate.AddHandler([this](double deltaTime) { Update(deltaTime); });
		startHandlerID = Application::OnStart.AddHandler([this]() { Start(); });		
		beforeUpdateHandlerID = Application::OnBeforeUpdate.AddHandler([this](double deltaTime) { BeforeUpdate(deltaTime); });
		beforeCloseHandlerID = Application::OnBeforeClose.AddHandler([this]() { BeforeClose(); });
	}

	void EventListener::UnsubscribeEvents()
	{
		//Unsubscribe events
		Application::OnUpdate.RemoveHandler(updateHandlerID);
		Application::OnStart.RemoveHandler(startHandlerID);
		Application::OnBeforeUpdate.RemoveHandler(beforeUpdateHandlerID);
		Application::OnBeforeClose.RemoveHandler(beforeCloseHandlerID);
	}
}