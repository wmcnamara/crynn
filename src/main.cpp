/*
#include "Window.h"
#include "Calculator.h"
#include "Camera.h"
#include "TextureViewer.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace Crynn;
using namespace Crynn::Events;
using namespace Crynn::Windows;
using namespace Crynn::Rendering;

int main ()
{
	
	Window window();

	Calculator calculator;
	Camera camera(Projection::Perspective);
	TextureViewer texViewer(Window::GetFrameBufSize(), ImVec2(0, 0));

	while (!Window::ShouldClose())
	{
		Window::BeforeRender();

		calculator.Run();
		texViewer.Run();
		camera.Run();
	
		Window::AfterRender();
	}

	return 0;
}	
*/