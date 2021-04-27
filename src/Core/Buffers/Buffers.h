 #pragma once
#include "glad/glad.h"
#include <memory>
#include <cassert>

#pragma warning( disable : 26812)

/*
/// This file contains simple RAII wrappers for various buffers used in OpenGL.
/// They all call the corresponding glGen function for the buffer they represent, when you construct them, and deallocate them when they go out of scope.
/// If you use the default constructor for one of these, please use the Set() function instead of trying to copy them. They cannot be copied or moved.
/// Do not call Set() if you didnt use the default constructor. You cannot call Set twice, or use the non default constructor and then call Set.
/// If you need to copy a VBO, please reconstruct another one from the same data pointer.
/// 
/// It is totally possible for these buffers to get in your way in some situations, so feel free to not use them, and construct your own buffers.
*/


namespace crynn
{
	//A vertex buffer object with simple memory management functions.
	class VBO
	{
	public:
		VBO(float* vertices, size_t numOfVertices);
		VBO() = default;
		~VBO();

		//No copying or moving
		VBO(const VBO& other) = delete;
		VBO operator=(const VBO& other) = delete;
		VBO(VBO&& other) = delete;
		VBO operator=(VBO&& other) = delete;

		//Returns the number of vertices stored in this VBO object. Equal to numOfVertices passed in the constructor
		size_t VertexCount() const { return m_size; }

		//Constructs the VBO with the data provided by the two parameters.
		//Intended to allow delayed construction if you used the default constructor.
		//Do not call Set unless you used the default constructor to create this object, it may result in memory leaks.
		void Set(float* vertices, size_t numOfVertices);

		GLuint GetID() const { return ID; }
		void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, ID); } //Calls glBindBuffer
	private:
		size_t m_size = 0;
		GLuint ID = 0;

		bool initialized = false;
	};

	//A vertex array object with simple memory management functions. This class's default constructor will allocate memory, and bind the VAO.
	class VAO
	{
	public:
		VAO();
		~VAO();

		//No copying or moving
		VAO(const VAO& other) = delete;
		VAO operator=(const VAO& other) = delete;
		VAO(VAO&& other) = delete;
		VAO operator=(VAO&& other) = delete;

		GLuint GetID() const { return ID; }
		void Bind() const { glBindVertexArray(ID); } //Calls glBindBuffer
	private:
		GLuint ID = 0;

		bool initialized = false;
	};

	//An element array buffer object with simple memory managment functions.
	class EBO
	{
	public:
		EBO(unsigned int* indices, size_t numOfIndices);
		EBO() = default;
		~EBO();
	
		//No copying or moving
		EBO(const EBO& other) = delete;
		EBO operator=(const EBO& other) = delete;
		EBO(EBO&& other) = delete;
		EBO operator=(EBO&& other) = delete;

		//Returns the number of indices stored in this EBO object. Equal to numOfIndices passed in the constructor
		size_t IndexCount() const { return m_size; }

		//Constructs the EBO with the data provided by the two parameters.
		//Intended to allow delayed construction if you used the default constructor.
		//Do not call Set unless you used the default constructor to create this object, it may result in memory leaks.
		void Set(unsigned int* indices, size_t numOfIndices);

		GLuint GetID() const { return ID; }
		void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }
	private:
		GLuint ID = 0;
		size_t m_size = 0;

		bool initialized = false;
	};
}
