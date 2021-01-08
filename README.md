# Crynn Game Engine
![Crynn Logo](docs/CrynnSmall.png)

## Introduction
   Crynn is an open source game engine created with C++17 and OpenGL. It is very barebones as it stands.
   Crynn is not overtly user friendly. Knowledge of matrix math, event systems, OpenGL and GLFW is required.
   
### Disclaimer
This engine is mostly intended as a personal project to learn more about computer graphics, and as such I will not make any guarantees about master branch stability. I'm not always consistent with my styling, and some of the implemented code is poor, and unfinished. 

## Dependencies
Crynn relies on a multitude of dependencies. They are listed here:

### Crynn Depends On:	

- [GLFW](https://www.glfw.org/) for windowing, and input.
- [GLAD](https://github.com/Dav1dde/glad) for loading OpenGL functions.
- [Dear IMGUI](https://github.com/ocornut/imguiDear) for GUI.
- [GLM](https://glm.g-truc.net/0.9.8/index.html) for matrix and other graphics related mathematics.
- [STB_IMAGE](https://github.com/nothings/stb) for image loading.

*As of now, Crynn does not use submodules for all of its dependencies. This will change, but as it stands you can find the dependency files in the lib/thirdparty folder.*

# Getting Started:
## Downloading Crynn:
To get started, you will need a copy of the Crynn source. If you have Git installed, you can download Crynn by running this command in the console:
`git clone https://github.com/wmcnamara/crynn.git`
The dependencies for Crynn are in the lib folder, and do not use submodules.

## Building Crynn:
Crynn previously supported Premake for building the engine, but now only supports building for Visual Studio.

You can download Visual Studio [here.](https://visualstudio.microsoft.com/downloads/)
Visual Studio 2019 is officially recommended.

Once everything is installed, you can follow these steps to build Crynn:
1. Clone Crynn
2. Open `Crynn.sln` in Visual Studio
3. Right clikc the Crynn solution in the solution explorer, and select build.

## Using Crynn:
Navigate to the docs/html directory, and open index.html. It will bring you to the introduction page, explaining how to use Crynn.
