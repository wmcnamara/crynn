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

		updateHandlerID = Application::OnUpdate.AddHandler([this](float deltaTime) { Update(deltaTime); });
		startHandlerID = Application::OnStart.AddHandler([this]() { Start(); });		
		beforeUpdateHandlerID = Application::OnBeforeUpdate.AddHandler([this](float deltaTime) { BeforeUpdate(deltaTime); });
		beforeCloseHandlerID = Application::OnBeforeClose.AddHandler([this]() { BeforeClose(); });
		renderID = Application::OnRender.AddHandler([this]() {Render(); });
	}

	void EventListener::UnsubscribeEvents()
	{
		//Unsubscribe events
		Application::OnUpdate.RemoveHandler(updateHandlerID);
		Application::OnStart.RemoveHandler(startHandlerID);
		Application::OnBeforeUpdate.RemoveHandler(beforeUpdateHandlerID);
		Application::OnBeforeClose.RemoveHandler(beforeCloseHandlerID);
		Application::OnRender.RemoveHandler(renderID);
	}
}