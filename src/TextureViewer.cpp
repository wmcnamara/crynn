#include "TextureViewer.h"

namespace Crynn
{
	TextureViewer::TextureViewer(ImVec2 size, ImVec2 pos) : GuiWindow(size, pos, "Texture Viewer")
	{
		//Subscribe to events
		onNewTexLoad.AddHandler([this](GetFileArgs args)
		{
			m_texture.Load(args.filePath.c_str());
		});
	}

	TextureViewer::~TextureViewer() {}

	void TextureViewer::EndDraw()
	{
		//Add the render texture to the draw list to display it.
		ImGui::GetWindowDrawList()->AddImage(
			(void*)m_renderTexture,
			ImVec2(ImGui::GetCursorScreenPos()),
			ImVec2(ImGui::GetCursorScreenPos().x + ImGui::GetContentRegionAvail().x,
				ImGui::GetCursorScreenPos().y + ImGui::GetContentRegionAvail().y), ImVec2(0, 1), ImVec2(1, 0));

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glDeleteRenderbuffers(1, &RBO);

		ImGui::End();
	}

	void TextureViewer::BeginDraw()
	{
		glEnable(GL_DEPTH_TEST);

		static bool open = true;
		ImGui::Begin(m_name, &open, ImGuiWindowFlags_MenuBar);

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Load Texture..."))
				{
					//Create a texture argument structure, and call onNewTexLoad with it.
					GetFileArgs args =
					{
						File::GetFile()
					};

					onNewTexLoad.Invoke(args);
				}
				ImGui::EndMenu();
			}
		}
		ImGui::EndMenuBar();

		//Rendering
		if (active)
		{
			glViewport(0, 0, (GLsizei)FrameBufferSize().x, (GLsizei)FrameBufferSize().y);
			glBindFramebuffer(GL_FRAMEBUFFER, FBO);
			glBindTexture(GL_TEXTURE_2D, m_renderTexture);

			//Color
			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				GL_RGBA,
				(GLsizei)FrameBufferSize().x,
				(GLsizei)FrameBufferSize().y,
				0,
				GL_RGBA,
				GL_UNSIGNED_BYTE,
				NULL
			);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			//Color attachment
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_renderTexture, 0);

			//Depth and stencil renderbuffer attachment
			glGenRenderbuffers(1, &RBO);
			glBindRenderbuffer(GL_RENDERBUFFER, RBO);

			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, (GLsizei)FrameBufferSize().x, (GLsizei)FrameBufferSize().y);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, RBO);

			if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
				Debug::Log("Framebuffer not complete", Debug::Error);
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void TextureViewer::Update()
	{
		//Update Model Matrix
		transformMatrix = glm::mat4(1.0f);
		transformMatrix = glm::rotate(
			transformMatrix,
			(float)glfwGetTime() * glm::radians(50.0f),
			glm::vec3(0.5f, 1.0f, 0.0f));

		m_renderer.Render();
	}
}