#pragma once


/*! \mainpage Crynn Game Engine
 *
 * \section intro_sec Introduction
 *
 * Crynn is a basic, open source game engine created with C++17 and OpenGL.
 * 
 * \section dependencies_sec Dependencies
 * Crynn relies on a multitude o
 */
 
/// Includes almost all necessary engine components, and contains main page documentation. ///

#include "Window.h"
#include "Calculator.h"
#include "Camera.h"
#include "TextureViewer.h"
#include "Debug.h"
#include "File.h"
#include "Input.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "Behaviour.h"
#include "Application.h"
#include "Transform.h"

#include <memory>

using namespace glm;
using namespace Crynn;