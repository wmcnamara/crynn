//This class is a basic example of getting up and running with Crynn.
#include "Crynn.h"

int main()
{
	Window window("Crynn", 800, 600); //Initialise crynn, and the window

	Application::Instance().Initialise(); //Calls OnStart events. 
	while (!window.ShouldClose())
	{
		window.BeforeRender(); //Clears buffers and sets up GUI data
		Application::Instance().Tick(); //Ticks update events.
		window.AfterRender(); //Renders GUI and swaps buffers.
	}
}