#include "EventListener.h"
#include "../Engine.h"

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

		updateHandlerID = m_engine->events.OnUpdate.AddHandler([this](FrameEventData eventData) { Update(eventData); });
		startHandlerID = m_engine->events.OnStart.AddHandler([this]() { Start(); });		
		beforeUpdateHandlerID = m_engine->events.OnBeforeUpdate.AddHandler([this](FrameEventData eventData) { BeforeUpdate(eventData); });
		beforeCloseHandlerID = m_engine->events.OnBeforeClose.AddHandler([this]() { BeforeClose(); });
		renderID = m_engine->events.OnRender.AddHandler([this]() {OnRender(); });
	}

	void EventListener::UnsubscribeEvents()
	{
		//Unsubscribe events
		m_engine->events.OnUpdate.RemoveHandler(updateHandlerID);
		m_engine->events.OnStart.RemoveHandler(startHandlerID);
		m_engine->events.OnBeforeUpdate.RemoveHandler(beforeUpdateHandlerID);
		m_engine->events.OnBeforeClose.RemoveHandler(beforeCloseHandlerID);
		m_engine->events.OnRender.RemoveHandler(renderID);
	}
}