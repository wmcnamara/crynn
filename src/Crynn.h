/// Includes almost all necessary engine components.
#pragma once
#pragma warning (disable : 4005)

#define IMGUI_DEFINE_MATH_OPERATORS
#include "Utility/Defines.h"

#include "Core/Window.h"
#include "Core/Camera.h"
#include "Core/Input.h"
#include "Core/Rendering/MeshRenderer.h"
#include "Core/Rendering/Shader.h"
#include "Core/Rendering/Light.h"
#include "Core/Rendering/Material.h"
#include "Core/EventListener.h"
#include "Core/Application.h"
#include "Core/Transform.h"
#include "Core/Mesh.h"
#include "Core/CrynnObject.h"
#include "Core/Scene.h"
#include "Core/Physics/Collision/AABB.h"
#include "Core/Skybox.h"
#include "Core/Physics/Rigidbody.h"

#include "Utility/Debug.h"
#include "Utility/IO.h"
#include "Utility/Timer.h"
#include "Utility/Random.h"

#include "GUI/GuiWindow.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

#include "Core/Math/Math.h"

#include <memory>
#include <future>
#include <mutex>

#define DATA_PATH "data/"

namespace crynn
{
	//Encapsulates the Crynn game engine.
	class Engine
	{
	public:
		/// <summary>
		/// Creates an instance of the Crynn Game Engine
		/// </summary>
		/// <param name="windowWidth">Width of the window</param>
		/// <param name="windowHeight">Height of the window</param>
		/// <param name="windowName">Name of the window</param>
		Engine
		(
			int windowWidth,
			int windowHeight,
			const char* windowName
		);

		~Engine();

		//Calls onstart, and begins calling the main game loop.
		void Run();
		void SetClearColor(float r, float g, float b, float a) const;

	private:
		Window m_window;
	};
}