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

	const float GuiWindow::WindowAspectRatio()
	{
		return (ImGui::GetWindowSize().x / ImGui::GetWindowSize().y);
	}

	const float GuiWindow::FrameBufferAspectRatio()
	{
		return (ImGui::GetContentRegionAvail().x / ImGui::GetContentRegionAvail().y);
	}

	const ImVec2 GuiWindow::WindowSize()
	{
		return ImGui::GetWindowSize();
	}

	void GuiWindow::AddFBOToDrawList()
	{
		ImGui::GetWindowDrawList()->AddImage(
			(void*)m_renderTexture, ImVec2(ImGui::GetItemRectMin().x + m_pos.x,
				ImGui::GetItemRectMin().y + m_pos.y),
			ImVec2(m_pos.x + m_size.x / 2, m_pos.y + m_size.y / 2), ImVec2(0, 1), ImVec2(1, 0));
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