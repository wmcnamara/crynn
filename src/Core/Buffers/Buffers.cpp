#include "Buffers.h"

namespace crynn
{
	VBO::~VBO()
	{
		glDeleteBuffers(1, &m_id);
	}

	GLuint VBO::ID() const
	{
		return m_id;
	}

	void VBO::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_id);
	}

	void VBO::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	VBO::VBO(VBO&& other) noexcept
	{
		glDeleteBuffers(1, &m_id); //Delete the current buffer

		m_id = other.m_id;

		other.m_id = 0;
	}

	VBO& VBO::operator=(VBO&& other) noexcept
	{
		if (this == &other)
			return *this;

		glDeleteBuffers(1, &m_id); //Delete the current buffer

		m_id = other.m_id;

		other.m_id = 0;

		return *this;
	}

	VAO::VAO(bool bindAfterConstruction)
	{
		glGenVertexArrays(1, &m_id);

		if (bindAfterConstruction)
			glBindVertexArray(m_id);
	}

	VAO::~VAO()
	{
		glDeleteVertexArrays(1, &m_id);
	}

	VAO::VAO(VAO&& other) noexcept
	{
		m_id = other.m_id;

		other.m_id = 0;
	}

	VAO& VAO::operator=(VAO&& other) noexcept
	{
		if (this == &other)
			return *this;

		glDeleteBuffers(1, &m_id); //Delete the current buffer

		m_id = other.m_id;

		other.m_id = 0;

		return *this;
	}

	GLuint VAO::ID() const
	{
		return m_id;
	}

	void VAO::Bind() const
	{
		glBindVertexArray(m_id);
	}

	void VAO::Unbind() const
	{
		glBindVertexArray(0);
	}

	EBO::EBO(const std::vector<GLuint>& indices)
	{
		glGenBuffers(1, &m_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);
	}

	EBO::~EBO()
	{
		glDeleteBuffers(1, &m_id);
	}

	void EBO::Bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	}

	void EBO::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	GLuint EBO::ID() const
	{
		return m_id;
	}

	EBO::EBO(EBO&& other) noexcept
	{
		glDeleteBuffers(1, &m_id); //Delete the current buffer

		m_id = other.m_id;

		other.m_id = 0;
	}

	EBO& EBO::operator=(EBO&& other) noexcept
	{
		if (this == &other)
			return *this;

		glDeleteBuffers(1, &m_id); //Delete the current buffer

		m_id = other.m_id;

		other.m_id = 0;

		return *this;
	}
}