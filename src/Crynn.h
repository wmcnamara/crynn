/*! \mainpage Crynn Game Engine
 *
 * \section intro_sec Introduction
 *
 * Crynn is an open source game engine created with C++17 and OpenGL.
 * The source code for Crynn can be found on <a href="https://github.com/wmcnamara/crynn">Github.</a>
 * 
 * \section dependencies_sec Dependencies
 * Crynn relies on a multitude of dependencies. They are listed here:
 *
 * Crynn Depends On:	
 *	- <a href="https://www.glfw.org/">GLFW</a> for windowing, and input.
 *	- <a href="https://github.com/Dav1dde/glad">GLAD</a> for loading OpenGL functions.
 *  - <a href="https://github.com/ocornut/imgui">Dear IMGUI</a> for GUI.
 *  - <a href="https://glm.g-truc.net/0.9.8/index.html">GLM</a> for matrix and other graphics related mathematics.
 *  - <a href="https://github.com/nothings/stb">STB_IMAGE</a> for image loading.
 */
 
/// Includes almost all necessary engine components.
#pragma once

#include "Core/Window.h"
#include "Core/Camera.h"
#include "Core/TextureViewer.h"
#include "Core/Input.h"
#include "Core/MeshRenderer.h"
#include "Core/Shader.h"
#include "Core/Behaviour.h"
#include "Core/Application.h"
#include "Core/Transform.h"

#include "Utility/Debug.h"
#include "Utility/File.h"
#include "Utility/Timer.h"

#include "GUI/GuiWindow.h"
#include "GUI/MatrixEditor.h"

#include <memory>

using namespace glm;
using namespace Crynn;