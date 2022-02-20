 #pragma once
#include "glad/glad.h"
#include <memory>
#include <cassert>
#include <vector>

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
	/*
		RAII wrapper for a Vertex Buffer Object

		Requires a valid instance of Crynn to be active to work.
	*/
	class VBO
	{
	public:
		/*
			Constructs a vertex buffer object from a std::vector of a chosen vertex data structure.
		*/
		template<typename VertexType>
		VBO(const std::vector<VertexType>& vertices)
		{
			glGenBuffers(1, &m_id);
			glBindBuffer(GL_ARRAY_BUFFER, m_id);

			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexType), vertices.data(), GL_STATIC_DRAW);
		}


		~VBO();

		VBO(const VBO& other) = delete;
		VBO& operator=(const VBO& other) = delete;

		VBO(VBO&& other) noexcept;
		VBO& operator=(VBO&& other) noexcept;

		GLuint ID() const;

		void Bind() const;
		void Unbind() const;

	private:
		GLuint m_id = 0;
	};

	/*
		RAII wrapper for a Vertex Buffer Object

		Requires a valid instance of Crynn to be active to work.
	*/
	class VAO
	{
	public:
		VAO(bool bindAfterConstruction = false);
		~VAO();

		VAO(const VAO& other) = delete;
		VAO& operator=(const VAO& other) = delete;

		VAO(VAO&& other) noexcept;
		VAO& operator=(VAO&& other) noexcept;

		GLuint ID() const;

		void Bind() const;
		void Unbind() const;

	private:
		GLuint m_id = 0;
	};

	/*
		RAII wrapper for a Element Array Buffer Object

		Requires a valid instance of Crynn to be active to work.
	*/
	class EBO
	{
	public:
		EBO(const std::vector<GLuint>& indices);
		~EBO();

		EBO(const EBO& other) = delete;
		EBO& operator=(const EBO& other) = delete;

		EBO(EBO&& other) noexcept;
		EBO& operator=(EBO&& other) noexcept;

		GLuint ID() const;

		void Bind() const;
		void Unbind() const;

	private:
		GLuint m_id = 0;
	};
}
