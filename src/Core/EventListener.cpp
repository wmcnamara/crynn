#include "EventListener.h"

namespace Crynn
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
		assert(!subscribed);

		//TODO move away from lambdas, as they dont look very nice here.
		//Subscribe events. 		

		updateHandlerID = Application::Instance().OnUpdate.AddHandler([this](double deltaTime) { Update(deltaTime); });
		startHandlerID = Application::Instance().OnStart.AddHandler([this]() { Start(); });		

		beforeUpdateHandlerID = Application::Instance().OnBeforeUpdate.AddHandler([this](double deltaTime) { BeforeUpdate(deltaTime); });
		beforeCloseHandlerID = Application::Instance().OnBeforeClose.AddHandler([this]() { BeforeClose(); });

		subscribed = true;
		///Debug::Log("Behaviour Events Subscribed...");
	}

	void EventListener::UnsubscribeEvents()
	{
		assert(subscribed);

		//Unsubscribe events
		Application::Instance().OnUpdate.RemoveHandler(updateHandlerID);
		Application::Instance().OnStart.RemoveHandler(startHandlerID);
		Application::Instance().OnBeforeUpdate.RemoveHandler(beforeUpdateHandlerID);
		Application::Instance().OnBeforeClose.RemoveHandler(beforeCloseHandlerID);

		subscribed = false;
		Debug::Log("Event Listener Unsubscribed");
	}

	bool EventListener::IsSubscribed()
	{
		return subscribed;
	}
}