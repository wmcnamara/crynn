#pragma once
#include "glad/glad.h"
#pragma warning( disable : 26812)

/// <summary>
/// This class contains object oriented implementations of various buffers used in OpenGL.
/// 
/// The default constructor for VAO allocates memory. They all call the corresponding glGen function for the buffer they represent, when you construct them.
/// </summary>
namespace crynn
{
	//Allows custom behaviour to automatically take place when creating the buffers.
	enum ConstructionBehaviour 
	{ 
		BindAfterAllocation, //Used in VAO to bind the VAO after allocating in the constructor.
		UnbindAfterAllocation //Used in VBO/EBO/FBO to unbind the buffer after allocating in the constructor.
	}; 

	class VBO
	{
	public:
		VBO(float* vertexData, size_t size);
		VBO(float* vertexData, size_t size, ConstructionBehaviour behaviour);
		VBO() = default;
		~VBO();

		//TODO Implement real copy constructor
		VBO(const VBO& other) = delete;

		GLuint GetID() const { return ID; }
		void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, ID); }
	private:
		GLuint ID = 0;
	};

	class VAO
	{
	public:
		VAO(); //Calls glGenVertexArrays.
		VAO(ConstructionBehaviour behaviour);
		~VAO();

		//TODO Implement real copy constructor
		VAO(const VAO& other) = delete;

		void Bind() const { glBindVertexArray(ID); }
		GLuint GetID() const { return ID; }
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

		void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }
		GLuint GetID() const { return ID; }
	private:
		GLuint ID = 0;
	};
}
