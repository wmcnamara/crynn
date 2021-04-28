#include "MeshRenderer.h"

namespace crynn
{
	MeshRenderer::MeshRenderer(const Mesh& mesh, const Shader& shader, Mat4& modelMatrix) :
		m_mesh(mesh),
		m_shader(shader),
		m_model(modelMatrix),
		m_normalMat(Mat4(transpose(inverse(modelMatrix)))) //Calculate normal matrix
	{}

	void MeshRenderer::Render()
	{
		//https://learnopengl.com/Model-Loading/Mesh

		if (!m_mesh.IsReady())
			return;

		unsigned int diffuseNr = 1;
		unsigned int specularNr = 1;
		for (unsigned int i = 0; i < m_mesh.textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding

			// retrieve texture number (the N in diffuse_textureN)
			std::string number;
			std::string name = m_mesh.textures[i].type;

			if (name == "texture_diffuse")
				number = std::to_string(diffuseNr++);
			else if (name == "texture_specular")
				number = std::to_string(specularNr++);

			m_shader.SetFloat(("material." + name + number).c_str(), i);
			glBindTexture(GL_TEXTURE_2D, m_mesh.textures[i].id);
		}
		glActiveTexture(GL_TEXTURE0);

		// draw mesh
		m_mesh.GetVAO().Bind();
		glDrawElements(GL_TRIANGLES, m_mesh.indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}