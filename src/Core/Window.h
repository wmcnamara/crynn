#pragma once
#include <Windows.h>
#include <glad/glad.h>
#pragma warning (disable : 4005)

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "Event.h"
#include "../Utility/Debug.h"

namespace crynn
{
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

		//It makes very little sense to copy/move a window, so I am disabling these to prevent shallow copying the glfwWindow
		Window(const Window& other) = delete; 
		Window(const Window&& other) = delete;
		Window operator=(const Window& other) = delete;
		Window operator=(const Window&& other) = delete;
		~Window();

		/// <summary>
		/// Gets the size of the window.
		/// </summary>
		/// <returns> ImVec2 object with x as the width, and y as the height</returns>
		const Vec2Int& GetSize();

		/// <summary>
		/// Gets the size of the framebuffer.
		/// </summary>
		/// <returns> ImVec2 object with x as the width, and y as the height</returns>
		const Vec2Int& GetFrameBufSize();

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

		//Sets this window as the current, focused window and input and other events will be dispatched from this window
		//The window constructor automatically sets this
		static void SetCurrentWindow(Window* window);
		static Window* GetCurrentWindow();

		//Returns a raw pointer to the underlying GLFWwindow in this object
		GLFWwindow* GetGLFWWindow();
	private:
		/// <summary>
		/// Raw GLFW window.
		/// </summary>
		GLFWwindow* m_glfwWindow = NULL;

		//TODO change constructor
		Vec2Int m_screenSize = Vec2Int(0, 0); ///Size of the window///
		Vec2Int m_frameBufSize = Vec2Int(0, 0); ///Size of the framebuffer///

		static inline Window* m_currentWindow;
	};
}