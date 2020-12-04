#pragma once
class Buffers
{
};
#include "glad/glad.h"

namespace crynn
{
	class VBO
	{
	public:
		VBO(float* vertexData, size_t size)
		{
			glGenBuffers(1, &ID);
			glBindBuffer(GL_ARRAY_BUFFER, ID);
			glBufferData(GL_ARRAY_BUFFER, size, vertexData, GL_STATIC_DRAW);
		}

		//TODO Implement real copy constructor
		VBO(const VBO& other) = delete;

		~VBO()
		{
			glDeleteBuffers(1, &ID);
		}

		GLuint GetID() { return ID; }
		void Bind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }
	private:
		GLuint ID;
	};

	class VAO
	{
	public:
		VAO()
		{
			glGenVertexArrays(1, &ID);
		}

		~VAO()
		{
			glDeleteBuffers(1, &ID);
		}

		void Bind() { glBindVertexArray(ID); }
		GLuint GetID() { return ID; }
	private:
		GLuint ID;
	};
}
