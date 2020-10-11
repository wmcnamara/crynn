# Crynn Game Engine
![Crynn Logo](docs/CrynnSmall.png)

## Introduction
   Crynn is an open source game engine created with C++17 and OpenGL. It is very barebones as it stands.
   Crynn is not overtly user friendly. Knowledge of matrix math, event systems, OpenGL and GLFW is required.
  
## Dependencies
Crynn relies on a multitude of dependencies. They are listed here:

### Crynn Depends On:	

- [GLFW](https://www.glfw.org/) for windowing, and input.
- [GLAD](https://github.com/Dav1dde/glad) for loading OpenGL functions.
- [Dear IMGUI](https://github.com/ocornut/imguiDear) for GUI.
- [GLM](https://glm.g-truc.net/0.9.8/index.html) for matrix and other graphics related mathematics.
- [STB_IMAGE](https://github.com/nothings/stb) for image loading.
- [STB_PERLIN](https://github.com/nothings/stb) for perlin noise generation.
- [IMGUIZMO](https://github.com/CedricGuillemet/ImGuizmo) gizmo generation.

*As of now, Crynn does not use submodules for all of its dependencies. This will change, but as it stands you can find the dependency files in the lib/thirdparty folder.*

# Getting Started:
## Downloading Crynn:
To get started, you will need a copy of the Crynn source. If you have Git installed, you can download Crynn by running this command in the console:
`git clone https://github.com/wmcnamara/crynn.git --recursive`
Make sure you use a recursive clone, to fetch all submodules.

## Building Crynn:
To manage the build process, Crynn uses <a href="https://premake.github.io/">Premake</a>. 

1. Naviagate to Crynn's base directory, containing the `premake5.exe` file.
2. Open any command line program, and navigate to that directory.
3. Launch premake5 with a command line argument corresponding with the IDE you're using. 
- Example: `./premake5 vs2019` for Visual Studio 2019 project files
- Example: `./premake5 vs2017` for Visual Studio 2017 project files

To know more about Premake, and how to generate project files for your IDE please visit Premake's, <a href="https://github.com/premake/premake-core/wiki/Using-Premake">"Using Premake"</a> article

## Using Crynn:
Navigate to the docs/html directory, and open index.html. It will bring you to the introduction page, explaining how to use Crynn.