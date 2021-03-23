#include "MeshRenderer.h"

namespace crynn
{
	MeshRenderer::MeshRenderer(const Mesh& mesh, const Texture& texture, const Shader& shader, mat4& modelMatrix) :
		m_mesh(mesh),
		m_texture(texture),
		m_shader(shader),
		m_model(modelMatrix),
		m_normalMat(mat3(transpose(inverse(modelMatrix)))) //Calculate normal matrix
	{}

	void MeshRenderer::Render()
	{
		if (active)
		{
			m_texture.Bind();
			m_mesh.GetVAO().Bind();
			m_shader.Use();

			m_shader.SetFloat("time", (float)glfwGetTime()); //Set time uniform on current shader
			m_shader.SetMatrix4("model", &m_model);
			m_shader.SetMatrix3("normalMatrix", &m_normalMat);
			if (m_mesh.Indexed())
			{
				glDrawElements(GL_TRIANGLES, m_mesh.IndexCount(), GL_UNSIGNED_INT, 0);
			}
			else
			{
				glDrawArrays(GL_TRIANGLES, 0, m_mesh.VertexCount());
			}
		}
	}
	void MeshRenderer::Update(double deltaTime)
	{
		Render();
	}
}