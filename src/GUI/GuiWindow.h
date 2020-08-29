#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "Window.h"
#include "imgui.h"
#include "delegate.h"
#include "IO.h"

class GuiWindow
{	
public:		
	/// <summary>
	/// Creates an onscreen GUI window.
	/// </summary>
	/// <param name="size"> Window size dimensions.</param>
	/// <param name="pos"> Window position on screen relative to the top left corner.</param>
	/// <param name="name"> Name of the window in the title bar.</param>
	/// <param name="drawOGLData"> Draw OpenGL geometry to this window?</param>
	/// <param name="imguiBeginFlags"> ImGui::Begin flags.</param>
	GuiWindow(ImVec2 size, ImVec2 pos, const char* name);
	~GuiWindow();

	void Run();

	virtual void BeginDraw() = 0;
	virtual void EndDraw() = 0;
	virtual void Update() = 0;

	const ImVec2& WindowSize(); //Returns the size of the window.
	const ImVec2 FrameBufferSize(); //Returns the framebuffer size of the window.

	const float WindowAspectRatio(); //Returns (width/height) of the window.
	const float FrameBufferAspectRatio(); //Returns (width/height) of the window framebuffer.	
	
	const unsigned int& GetRenderTexture();
protected:
	bool active = true;	

	ImVec2 m_size;
	ImVec2 m_pos;

	GLuint FBO = 0, RBO = 0;
	unsigned int m_renderTexture = 0;
	const char* m_name;
};

