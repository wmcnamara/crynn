#include "MeshRenderer.h"

namespace crynn
{
	MeshRenderer::MeshRenderer(Mesh* mesh, Texture* texture, Shader* shader, mat4* modelMatrix) :
		m_mesh(mesh),
		m_texture(texture),
		m_shader(shader),
		m_indexed(mesh->Indexed()),
		m_model(modelMatrix)
	{}

	void MeshRenderer::Render()
	{
		if (active)
		{
			glBindTexture(GL_TEXTURE_2D, m_texture->GetTextureID());
			m_mesh->GetVAO().Bind();
			m_shader->Use();

			m_shader->SetFloat("time", (float)glfwGetTime()); //Set time uniform on current shader
			m_shader->SetMatrix4("model", m_model);

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
	void MeshRenderer::Update(double deltaTime)
	{
		Render();
	}
}