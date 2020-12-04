//This class is a basic example of getting up and running with Crynn.
#include "Crynn.h"
using namespace crynn;

int main()
{
	Window window("Crynn", 800, 600); //Initialise crynn, and the window

	Application::Initialise(); //Calls OnStart events. 
	while (!window.ShouldClose())
	{
		window.BeforeRender(); //Clears buffers and sets up GUI data
		Application::Tick(); //Ticks update events.
		window.AfterRender(); //Renders GUI and swaps buffers.
	}
}