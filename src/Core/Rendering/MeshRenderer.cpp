#include "MeshRenderer.h"

namespace crynn
{
	MeshRenderer::MeshRenderer(const Model& mesh, const Material& material, const Transform& transform) :
		m_transform(transform),
		m_model(mesh),
		m_material(material)
	{}

	void MeshRenderer::OnRender()
	{
		const Shader& shader = m_material.GetShader();

		Mat4 modelMatrix = m_transform.GetMatrix();
		Mat3 normalMatrix = glm::transpose(glm::inverse(modelMatrix));

		shader.Use();

		shader.SetFloat("time", (float)glfwGetTime());
		shader.SetMatrix4("model", &modelMatrix);
		shader.SetMatrix3("normalMatrix", &normalMatrix);


		m_material.SetUniforms();

		m_model.Render(shader);
	}
}