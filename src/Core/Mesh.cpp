#include "Mesh.h"
namespace crynn
{
	Mesh::Mesh(
		float* vertices,
		size_t numOfVertices,
		unsigned int* indices,
		size_t numOfIndices,
		bool useEBO) :

		m_vertices(vertices),
		m_indices(indices),
		m_numOfVertices(numOfVertices),
		m_numOfIndices(numOfIndices),
		m_useEBO(useEBO),
		m_vao(),
		m_vbo(vertices, numOfVertices)
	{
		ScopedTimer timer("Mesh Construction", TimeFormat::Milliseconds);

		//If they want an ebo, make one
		if (useEBO)
			m_ebo = EBO(indices, numOfIndices);
		
		//Vertex Attributes

		//Positon
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//Texture coords
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}

	Mesh::~Mesh()
	{
	}
}
