#include "Mesh.h"
namespace crynn
{
	Mesh::Mesh(
		float* vertices,
		unsigned int* indices,
		size_t numOfVertices,
		size_t numOfIndices,
		bool useEBO) :

		m_vertices(vertices),
		m_indices(indices),
		m_numOfVertices(numOfVertices),
		m_numOfIndices(numOfIndices),
		m_useEBO(useEBO),
		m_vbo(vertices, numOfVertices),
		m_vao()
		
	{
#ifdef CRYNN_DEBUG
		ScopedTimer timer("Mesh Construction", TimeFormat::Milliseconds);
#endif

		m_vao.Bind();

		//If they chose to use an EBO, construct it now after binding the vao
		if (useEBO)
		{
			m_ebo = EBO(indices, numOfIndices);
		}

		//Vertex Attributes
		/////////////////////////////////////////////
		//Positon
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//Texture coords
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		/////////////////////////////////////////////
	}

	Mesh::~Mesh()
	{
	}
}