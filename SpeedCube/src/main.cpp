#include <Crynn.h>
#include "GameClasses/Player.h"
#include "GameClasses/Level.h"

int main() 
{
	Window window("SpeedCube", 800, 600);
	Player player;
	Level level;

	Application::Instance().OnStart.Invoke(); //Before the while loop, invoke OnStart
	while (!window.ShouldClose())
	{
		window.BeforeRender();
		Application::Instance().Tick();
		window.AfterRender();
	}
}