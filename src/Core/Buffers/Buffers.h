#pragma once
#include "glad/glad.h"

namespace crynn
{
	class VBO
	{
	public:
		VBO(float* vertexData, size_t size);
		VBO() = default;
		~VBO();

		//TODO Implement real copy constructor
		VBO(const VBO& other) = delete;

		GLuint GetID() { return ID; }
		void Bind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }
	private:
		GLuint ID = 0;
	};

	class VAO
	{
	public:
		VAO();
		~VAO();

		//TODO Implement real copy constructor
		VAO(const VAO& other) = delete;

		void Bind() const { glBindVertexArray(ID); }
		GLuint GetID() { return ID; }
	private:
		GLuint ID = 0;
	};

	class EBO
	{
	public:
		EBO(unsigned int* indices, unsigned int numOfIndices);
		EBO() = default;
		~EBO();

		//TODO Implement real copy constructor
		EBO(const EBO& other) = delete;

		void Bind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }
		GLuint GetID() { return ID; }
	private:
		GLuint ID = 0;
	};
}
