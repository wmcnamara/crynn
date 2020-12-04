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
		//TODO move away from lambdas, as they dont look very nice here.
		//Subscribe events. 	

		if (subscribed)
			return;

		updateHandlerID = Application::OnUpdate.AddHandler([this](double deltaTime) { Update(deltaTime); });
		startHandlerID = Application::OnStart.AddHandler([this]() { Start(); });		
		beforeUpdateHandlerID = Application::OnBeforeUpdate.AddHandler([this](double deltaTime) { BeforeUpdate(deltaTime); });
		beforeCloseHandlerID = Application::OnBeforeClose.AddHandler([this]() { BeforeClose(); });

		subscribed = true;
		///Debug::Log("Behaviour Events Subscribed...");
	}

	void EventListener::UnsubscribeEvents()
	{
		if (!subscribed)
			return;

		//Unsubscribe events
		Application::OnUpdate.RemoveHandler(updateHandlerID);
		Application::OnStart.RemoveHandler(startHandlerID);
		Application::OnBeforeUpdate.RemoveHandler(beforeUpdateHandlerID);
		Application::OnBeforeClose.RemoveHandler(beforeCloseHandlerID);

		subscribed = false;
		Debug::Log("Event Listener Unsubscribed");
	}
}