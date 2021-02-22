#include "Buffers.h"

crynn::VBO::VBO(float* vertexData, size_t size) : m_vertexData(vertexData), m_size(size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertexData, GL_STATIC_DRAW);
}

crynn::VBO::VBO(float* vertexData, size_t size, ConstructionBehaviour behaviour) : m_vertexData(vertexData), m_size(size)
{
	switch (behaviour)
	{
	case BindAfterAllocation: //The VBO must be bound to give it any data, so this works fine.
		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData) * size, vertexData, GL_STATIC_DRAW);
		break;

		glGenBuffers(1, &ID);
		glBindBuffer(GL_ARRAY_BUFFER, ID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData) * size, vertexData, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0); //unbind
		break;
	}
}

crynn::VBO& crynn::VBO::operator=(const VBO& other)
{
	m_size = other.m_size;
	m_vertexData = new float[m_size];

	std::memcpy(m_vertexData, other.m_vertexData, m_size);

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, other.m_size, other.m_vertexData, GL_STATIC_DRAW);

	return *this;
}

crynn::VBO::VBO(const VBO& other)
{
	m_size = other.m_size;
	m_vertexData = new float[m_size];

	std::memcpy(m_vertexData, other.m_vertexData, m_size);

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, other.m_size, other.m_vertexData, GL_STATIC_DRAW);
}

crynn::VBO::~VBO()
{
	glDeleteBuffers(1, &ID);
	delete[] m_vertexData;
}

crynn::VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

crynn::VAO::VAO(ConstructionBehaviour behaviour)
{
	switch (behaviour) 
	{
	case BindAfterAllocation:
		glGenVertexArrays(1, &ID);
		glBindVertexArray(ID); //bind 
		break;

	case UnbindAfterAllocation:
		glGenVertexArrays(1, &ID);
		break;
	}
}

crynn::VAO::~VAO()
{
	glDeleteVertexArrays(1, &ID);
}

crynn::EBO::EBO(unsigned int* indices, unsigned int numOfIndices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices) * numOfIndices, indices, GL_STATIC_DRAW);
}

crynn::EBO::~EBO()
{
	glDeleteBuffers(1, &ID);
}
