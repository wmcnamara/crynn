/*
#include "Crynn.h"

int main()
{
	Window window("Crynn", 800, 600);

	Application::Instance().OnStart.Invoke(); //Before the while loop, invoke OnStart
	while (!window.ShouldClose())
	{
		window.BeforeRender();
		Application::Instance().Tick(); //Ticks update events.
		window.AfterRender();
	}
}
*/