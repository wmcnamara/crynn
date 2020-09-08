#include "MeshRenderer.h"

namespace Crynn
{
	MeshRenderer::MeshRenderer(Mesh* mesh, Texture* texture, Shader* shader) :
		m_mesh(mesh),
		m_texture(texture),
		m_shader(shader),
		m_indexed(mesh->Indexed())
	{}

	void MeshRenderer::Render()
	{
		if (active)
		{
			glBindTexture(GL_TEXTURE_2D, m_texture->Data());
			glBindVertexArray(m_mesh->GetVAO());
			
			glUseProgram(m_shader->ID);

			m_shader->SetFloat("time", (float)glfwGetTime()); //Set time uniform on current shader
			m_shader->SetMatrix4("model", &model);

			if (m_indexed)
			{
				glDrawElements(GL_TRIANGLES, m_mesh->IndexCount(), GL_UNSIGNED_INT, 0);
			}
			else
			{
				glDrawArrays(GL_TRIANGLES, 0, m_mesh->VertexCount());
			}
		}
	}
}