# Crynn Game Engine
Game Engine Created In C++17 and OpenGL

![Crynn Logo](docs/CrynnSmall.png)

## Introduction
   Crynn is an open source game engine created with C++17 and OpenGL. It is very barebones as it stands.
   Crynn is not overtly user friendly. Knowledge of matrix math, event systems, OpenGL and GLFW is required.
  
## Dependencies
Crynn relies on a multitude of dependencies. They are listed here:
 
### Crynn Depends On:	
- <a href="https://www.glfw.org/">GLFW</a> for windowing, and input.
- <a href="https://github.com/Dav1dde/glad">GLAD</a> for loading OpenGL functions.
- <a href="https://github.com/ocornut/imgui">Dear IMGUI</a> for GUI.
- <a href="https://glm.g-truc.net/0.9.8/index.html">GLM</a> for matrix and other graphics related mathematics.
- <a href="https://github.com/nothings/stb">STB_IMAGE</a> for image loading.

*As of now, Crynn does not use submodules for its dependencies. This will change, but as it stands you can find the dependency files in the lib/thirdparty folder.*

# Getting Started:
## Downloading Crynn:
To get started, you will need a copy of the Crynn source. If you have Git installed, you can download Crynn by running this command in the console:
`git clone https://github.com/wmcnamara/crynn.git`

## Building Crynn:
To manage the build process, Crynn uses <a href="https://premake.github.io/">Premake</a>. Premake does not need to be installed to use it. 
1. Naviagate to Crynn's base directory, containing the `premake5.exe` file.
2. Open any command line program, and navigate to that directory.
3. Launch premake5 with a command line argument corresponding with the IDE you're using. 
- Example: `./premake5 vs2019` for Visual Studio 2019 project files
- Example: `./premake5 vs2017` for Visual Studio 2017 project files

To know more about Premake, and how to generate project files for your IDE please visit Premake's, <a href="https://github.com/premake/premake-core/wiki/Using-Premake">"Using Premake"</a> section.

## Using Crynn:
Lets try programming with Crynn! Crynn does not use any sort of standalone editor, so any object creation you do is done programmatically. Keep this in mind when you use Crynn.

1. Naviate to src/main.cpp and open it. You should see something like this:
```
#include "Crynn.h" //Get most of Crynns necessary components

int main()
{
	Window window("Crynn", 800, 600); //Create the window

	Application::Instance().Initialise(); //Initialise Crynn
	while (!window.ShouldClose())
	{
		window.BeforeRender(); //Clears buffers and sets up GUI data
		Application::Instance().Tick(); //Ticks update events.
		window.AfterRender(); //Renders GUI and swaps buffers.
	}
}
```
This is the most basic entry point to Crynn that everything starts at.