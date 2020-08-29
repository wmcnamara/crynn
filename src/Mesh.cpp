#include "Mesh.h"

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
	m_useEBO(useEBO)
{		
	//Setup buffers
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	if (useEBO) 
	{
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * numOfIndices, indices, GL_STATIC_DRAW);
	}

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * numOfVertices, vertices, GL_STATIC_DRAW);

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
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}