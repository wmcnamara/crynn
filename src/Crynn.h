/// Includes almost all necessary engine components.
#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS

#include "Core/Window.h"
#include "Core/Camera.h"
#include "Core/Input.h"
#include "Core/MeshRenderer.h"
#include "Core/Shader.h"
#include "Core/EventListener.h"
#include "Core/Application.h"
#include "Core/Transform.h"
#include "Core/Mesh.h"
#include "Core/CrynnObject.h"
#include "Core/Scene.h"
#include "Core/Physics/Collision/AABB.h"

#include "Utility/Debug.h"
#include "Utility/IO.h"
#include "Utility/Timer.h"
#include "Utility/Random.h"

#include "GUI/GuiWindow.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

#include <memory>
#include <future>
#include <mutex>

#define DATA_PATH "data/"

using namespace glm;

namespace crynn
{
	//Encapsulates window creation and running the game.
	class Engine
	{
	public:
		Engine
		(
			int windowWidth,
			int windowHeight,
			const char* winName
		);

		~Engine();

		//Calls onstart, and begins calling the main game loop.
		void Run();
		void SetClearColor(float r, float g, float b, float a) const;

	private:
		Window m_window;
	};
}