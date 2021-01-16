//This class is a basic example of getting up and running with Crynn.
//Use it as a playground when learning about Crynn.
#include "Crynn.h"

using namespace crynn;

int main()
{
	Window window("Crynn", 800, 600); //Initialise crynn, and the window

	Application::Initialise(); //Calls OnStart events. Should be right before the while loop.
	while (!window.ShouldClose())
	{
		window.BeforeRender(); //Clears buffers and sets up GUI data
		Application::Tick(); //Ticks update events.
		window.AfterRender(); //Renders GUI and swaps buffers.
	}

	return 0;
}