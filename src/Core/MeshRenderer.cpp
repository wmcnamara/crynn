#include "MeshRenderer.h"

namespace crynn
{
	MeshRenderer::MeshRenderer(const Model& mesh, const Shader& shader, const Transform& transform) :
		m_model(mesh),
		m_shader(shader),
		m_transform(transform),
		m_normalMat(Mat4(transpose(inverse(transform.GetMatrix())))) //Calculate normal matrix //TODO calculate this before setting model
	{}

	void MeshRenderer::Render()
	{
		m_shader.Use();
		m_shader.SetFloat("time", (float)glfwGetTime()); //Set time uniform on current shader
		m_shader.SetMatrix4("model", &m_transform.GetMatrix());
		m_shader.SetMatrix3("normalMatrix", &m_normalMat);

		m_model.Render(m_shader);
	}
}