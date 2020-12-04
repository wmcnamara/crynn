#include "GuiWindow.h"
namespace crynn
{
	GuiWindow::GuiWindow(ImVec2 size, ImVec2 pos, const char* name) :
		m_name(name),
		m_size(size),
		m_pos(pos)
	{
		glGenFramebuffers(1, &FBO);
		glGenTextures(1, &m_renderTexture);
	}

	GuiWindow::~GuiWindow()
	{
		glDeleteFramebuffers(1, &FBO);
		glDeleteTextures(1, &m_renderTexture);
	}
	void GuiWindow::Run()
	{
		BeginGUIDraw();
		GUIDraw();
		EndGUIDraw();
	}

	const float GuiWindow::WindowAspectRatio()
	{
		return (ImGui::GetWindowSize().x / ImGui::GetWindowSize().y);
	}

	const float GuiWindow::FrameBufferAspectRatio()
	{
		return (ImGui::GetContentRegionAvail().x / ImGui::GetContentRegionAvail().y);
	}

	void GuiWindow::Update(double deltaTime)
	{
		Run();
	}

	const ImVec2 GuiWindow::WindowSize()
	{
		return ImGui::GetWindowSize();
	}

	const ImVec2 GuiWindow::FrameBufferSize()
	{
		return ImGui::GetContentRegionAvail();
	}

	const unsigned int& GuiWindow::GetRenderTexture()
	{
		return m_renderTexture;
	}

	
}