//This class is a basic example of getting up and running with Crynn.
//Use it as a playground when learning about Crynn.
#include "Crynn.h"

using namespace crynn;

int main()
{
	Engine engine = Engine(800, 600, "Crynn Example");

	Transform tr;
	Rigidbody rb(eDynamicBody, tr, Box(Vec3(0, 0, 0), Vec3(1, 1, 1)));
	engine.Run();
}