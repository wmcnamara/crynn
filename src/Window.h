#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include "delegate.h"
#include "Debug.h"

const int DEFAULT_SCR_WIDTH = 800;
const int DEFAULT_SCR_HEIGHT = 600;

struct OnWindowStartArgs 
{
	ImVec2 windowSize;
};

class Window
{
public:
	~Window();

	const ImVec2& GetSize() { return screenSize; }
	ImVec2 GetFrameBufSize();

	void BeforeRender();
	void AfterRender();

	GLFWwindow* GetWindow() { return m_window; }

	static void Init() { Instance(); }

	const int GetFrameCount() { return frameCount; }
	
	Delegate<ImVec2> OnWindowResize;
	Delegate<OnWindowStartArgs> OnWindowStart;

	void SetSize(int width, int height) { screenSize = ImVec2(width, height); }

	//Updates size based on window dimensions
	void SizeUp() 
	{
		int width, height;
		glfwGetFramebufferSize(m_window, &width, &height);

		Window::Instance().SetSize(width, height);
		Window::Instance().OnWindowResize.Invoke(ImVec2(width, height));
	}

	void DisplayFPS() 
	{
		//FPS
		std::string output("FPS: ");
		output += std::to_string(Window::Instance().GetFrameCount());
		ImGui::Text(output.c_str());
	}
private:
	GLFWwindow* m_window;

	ImVec2 screenSize;

	//FPS data
	double previousTime = 0;
	int frameCount = 0; //This is updated every second.

//SINGLETON//
public:
	static Window& Instance()
	{
		static Window instance;
		return instance;
	}

	Window(Window const&) = delete;
	void operator=(Window const&) = delete;
private:	

	Window();
};