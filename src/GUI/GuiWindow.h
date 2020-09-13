#pragma once
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "imgui.h"

#include "Core/Window.h"
#include "Core/Event.h"
#include "Core/Behaviour.h"

namespace Crynn
{
	/// <summary>
	/// Base class for any onscreen GUI window.
	/// Uses IMGUI and Crynn events for rendering.
	/// </summary>
	class GuiWindow : protected Behaviour
	{
	public:
		/// <summary>
		/// Creates an onscreen GUI window
		/// </summary>
		/// <param name="size">Window width and height dimensions</param>
		/// <param name="pos">Window x and y position.</param>
		/// <param name="name">Window title</param>
		GuiWindow(ImVec2 size, ImVec2 pos, const char* name);
		~GuiWindow();

		virtual void BeginDraw() = 0;		
		virtual void Draw() = 0;
		virtual void EndDraw() = 0;

		void Update(double deltaTime) override;

		const ImVec2 WindowSize(); //Returns the size of the window.
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
		
		/// Calls BeginDraw(), Draw() and EndDraw() in that order.
		void Run();
	};
}