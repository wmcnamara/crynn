 #pragma once
#include "glad/glad.h"
#include <memory>
#pragma warning( disable : 26812)

/// <summary>
/// This class contains object oriented implementations of various buffers used in OpenGL.
/// 
/// The default constructor for VAO allocates memory. They all call the corresponding glGen function for the buffer they represent, when you construct them.
/// </summary>
namespace crynn
{
	//A vertex buffer object with simple memory management functions.
	class VBO
	{
	public:
		VBO(float* vertexData, size_t size);
		VBO() = default;
		~VBO();

		//TODO Implement real copy constructor
		VBO(const VBO& other) = delete;

		size_t VertexCount() { return m_size; }

		GLuint GetID() const { return ID; }
		void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, ID); } //Calls glBindBuffer
	private:
		size_t m_size = 0;
		GLuint ID = 0;
	};

	//A vertex array object with simple memory management functions. This class's default constructor will allocate memory.
	class VAO
	{
	public:
		VAO(); //Calls glGenVertexArrays.
		~VAO();

		//TODO Implement real copy constructor
		VAO(const VAO& other) = delete;

		GLuint GetID() const { return ID; }
		void Bind() const { glBindVertexArray(ID); } //Calls glBindBuffer
	private:
		GLuint ID = 0;
	};

	//An element array buffer object with simple memory managment functions.
	class EBO
	{
	public:
		EBO(unsigned int* indices, unsigned int numOfIndices);
		EBO() = default;
		~EBO();

		//TODO Implement real copy constructor
		EBO(const EBO& other) = delete;

		void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }
		GLuint GetID() const { return ID; }
	private:
		GLuint ID = 0;
	};
}
