#include "Buffers.h"

crynn::VBO::VBO(float* vertexData, size_t size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertexData, GL_STATIC_DRAW);
}

crynn::VBO::~VBO()
{
	glDeleteBuffers(1, &ID);
}

crynn::VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

crynn::VAO::~VAO()
{
	glDeleteVertexArrays(1, &ID);
}

crynn::EBO::EBO(unsigned int* indices, unsigned int numOfIndices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numOfIndices, indices, GL_STATIC_DRAW);
}

crynn::EBO::~EBO()
{
	glDeleteBuffers(1, &ID);
}
