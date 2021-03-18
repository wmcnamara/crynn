#include "Mesh.h"
namespace crynn
{
	Mesh::Mesh(
		float* vertices,
		size_t numOfVertices,
		unsigned int* indices,
		size_t numOfIndices,
		VertexAttribFlags flags) :

		m_numOfVertices(numOfVertices),
		m_numOfIndices(numOfIndices),
		m_useEBO(indices != nullptr),
		m_vao(),
		m_vbo(vertices, numOfVertices)
	{
		ScopedTimer timer("Mesh Construction", TimeFormat::Milliseconds);

		//If they want an ebo, make one
		//if (m_useEBO)
			//m_ebo = EBO(indices, numOfIndices);
		
		size_t dataFieldCount = 3; // number of data fields for vertex attributes from the flags. Starts with 3 for xyz vertex.

		//Vertex Attributes

		if (flags & VertexAttribTexCoords)
		{
			dataFieldCount += 2; //uv coord

			//Texture coords
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, dataFieldCount * sizeof(float), (void*)(3 * sizeof(float)));
			glEnableVertexAttribArray(1);
		}

		//Normal vector
		if (flags & VertexAttribNormVec)
		{
			dataFieldCount += 3; //normal vector size

			//Texture coords
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, dataFieldCount * sizeof(float), (void*)(5 * sizeof(float)));
			glEnableVertexAttribArray(2);
		}

		//Positon
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, dataFieldCount * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);	
	}

	Mesh::~Mesh()
	{
	}
}
