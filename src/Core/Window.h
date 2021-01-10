#pragma once
#include "glad/glad.h"
#include <Windows.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Event.h"
#include "Utility/Debug.h"

#include "Application.h"
#include "Core/Math/Vec2.h"

namespace crynn
{
	class Input;

	/// <summary>
	/// The window everything is rendered on.
	/// Crynn does not support more than 1 monitor.
	/// </summary>
	class Window
	{
	public:
		/// <summary>
		/// Create a new window and display it.
		/// </summary>
		/// <param name="name">Window title seen in the top left</param>
		/// <param name="width">Width of the window</param>
		/// <param name="height">Height of the window</param>
		Window(const char* name, unsigned int width, unsigned int height);
		Window(const Window& other) = delete; //There should only ever be one window.
		Window(const Window&& other) = delete; //There should only ever be one window.
		~Window();

		/// <summary>
		/// Gets the size of the window.
		/// </summary>
		/// <returns> ImVec2 object with x as the width, and y as the height</returns>
		static const ImVec2& GetSize();

		/// <summary>
		/// Gets the size of the framebuffer.
		/// </summary>
		/// <returns> ImVec2 object with x as the width, and y as the height</returns>
		static const ImVec2& GetFrameBufSize();

		/// <summary>
		/// Called before rendering to clear buffers, poll events and setup IMGUI data.
		/// </summary>
		void BeforeRender();

		/// <summary>
		/// Called after rendering to render IMGUI data and swap buffers.
		/// </summary>
		void AfterRender();

		/// <summary>
		/// Updates the framebuffer and screensize with the current data.
		/// Somewhat expensive, and should only be called when you know the data has changed.
		/// </summary>
		void UpdateWindowSize();

		/// <summary>
		/// Returns glfwGetWindowShouldClose();
		/// </summary>
		/// <returns>True if the window should close. Used to hold a game loop.</returns>
		bool ShouldClose();

		static GLFWwindow* GetGLFWWin() 
		{ 
			assert(glfwWindow != NULL);
			return glfwWindow; 
		}
	private:
		/// <summary>
		/// Raw GLFW window.
		/// </summary>
		inline static GLFWwindow* glfwWindow = NULL;

		//TODO change constructor
		static inline ImVec2 m_screenSize = ImVec2(0, 0); ///Size of the window///
		static inline ImVec2 m_frameBufSize = ImVec2(0, 0); ///Size of the framebuffer///
	};
}