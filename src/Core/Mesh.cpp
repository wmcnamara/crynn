#include "Mesh.h"

namespace crynn
{
	Mesh::Mesh(
		std::vector<Vertex> _vertices,
		std::vector<unsigned int> _indices,
		std::vector<MeshTexData> _textures) :

		vertices(_vertices),
		indices(_indices),
		textures(_textures),
		m_vao() //binds the VAO
	{
#ifdef CRYNN_DEBUG
		ScopedTimer timer("Mesh Construction", TimeFormat::Milliseconds);
#endif
		//Vertex Attributes
		m_vbo.Set(vertices.data(), vertices.size());
		m_ebo.Set(indices.data(), indices.size());

		//Positon
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);

		//normal vec
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
		glEnableVertexAttribArray(1);

		//Texture coords
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoord));
		glEnableVertexAttribArray(2);

	}

	Mesh::~Mesh()
	{
	}
}
