#pragma once
#include "glad/glad.h"
#include <Windows.h>
#include "GLFW/glfw3.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "delegate.h"
#include "Debug.h"

#include "Application.h"

#ifndef UNICODE
#define UNICODE
#endif 

namespace Crynn
{
	struct OnWindowStartArgs
	{
		ImVec2 windowSize;
	};

	class Window
	{
	public:
		Window(const char* name, int width, int height);

		const ImVec2& GetSize();
		const ImVec2& GetFrameBufSize();

		void BeforeRender();
		void AfterRender();

		void UpdateWindowSize();

		bool ShouldClose();
		~Window();
	private:
		GLFWwindow* glfwWindow;

		ImVec2 m_screenSize;
		ImVec2 m_frameBufSize;
	};
}