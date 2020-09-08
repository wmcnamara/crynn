#include "Behaviour.h"

namespace Crynn
{
	Behaviour::Behaviour()
	{
		//Subscribe Update(), and get the handlerID
		updateHandlerID = Application::Instance().OnUpdate.AddHandler([this](float deltaTime)
		{
			Update(deltaTime);
		});

		//Subscribe Start(), and get the handlerID
		startHandlerID = Application::Instance().OnStart.AddHandler([this]()
		{
			Start();
		});

		//Subscribe Start(), and get the handlerID
		beforeUpdateHandlerID = Application::Instance().OnBeforeUpdate.AddHandler([this]()
		{
			BeforeUpdate();
		});
	}

	Behaviour::~Behaviour()
	{
		Application::Instance().OnUpdate.RemoveHandler(updateHandlerID);
		Application::Instance().OnStart.RemoveHandler(startHandlerID);
	}
}