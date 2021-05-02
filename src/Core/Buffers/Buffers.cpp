#include "Buffers.h"

crynn::VBO::VBO(void* vertices, size_t numOfVertices) : m_size(numOfVertices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * numOfVertices, vertices, GL_STATIC_DRAW);

	initialized = true;
}

crynn::VBO::~VBO()
{
	glDeleteBuffers(1, &ID);
}

void crynn::VBO::Set(void* vertices, size_t numOfVertices)
{
	//DO NOT call Set unless the object was constructed with the default constructor. 
	//DO NOT call Set twice.
	assert(!initialized);

	m_size = numOfVertices;

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * numOfVertices, vertices, GL_STATIC_DRAW);

	initialized = true;
}

crynn::VAO::VAO()
{
	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID); //bind 
}

crynn::VAO::~VAO()
{
	glDeleteVertexArrays(1, &ID);
}

crynn::EBO::EBO(unsigned int* indices, size_t numOfIndices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * numOfIndices, indices, GL_STATIC_DRAW);

	initialized = true;
}

crynn::EBO::~EBO()
{
	glDeleteBuffers(1, &ID);
}

void crynn::EBO::Set(unsigned int* indices, size_t numOfIndices)
{
	//DO NOT call Set unless the object was constructed with the default constructor. 
	//DO NOT call Set twice.
	assert(!initialized);

	m_size = numOfIndices;

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * numOfIndices, indices, GL_STATIC_DRAW);

	initialized = true;
}
