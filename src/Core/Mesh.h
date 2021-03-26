#pragma once
#include "glm/glm.hpp"
#include "../Utility/Debug.h"
#include "../Utility/Timer.h"
#include "Buffers/Buffers.h"
#include "../Utility/Parsers/STLParser.h"
#include "glad/glad.h"

namespace crynn
{
	enum VertexAttribFlags
	{
		VertexAttribNone = (1 << 0),
		VertexAttribTexCoords = (1 << 2),
		VertexAttribNormVec = (1 << 3),

		VertexAttribSTL = VertexAttribNormVec //Vertex attributes for an STL file
	};

	class Mesh
	{
	public:
		/// <summary>
		/// Creates a renderable mesh.
		/// </summary>
		/// <param name="vertices">Array containing the vertices of your mesh.</param>
		/// <param name="numOfVertices">Number of elements in the vertices array.</param>
		/// <param name="indices">Array containing the indices of your mesh. If you do not wish to render with indices, set this to NULL, and useEBO to false.</param>
		/// <param name="numOfIndices">Number of elements in the indices array.</param>
		/// <param name="useEBO">Setting this to true will generate an element buffer, and render with indices.</param>
		Mesh(
			float* vertices,
			size_t numOfVertices,
			unsigned int* indices,
			size_t numOfIndices,
			VertexAttribFlags flags);

		~Mesh();

		//TODO change parameter order.

		//Returns the amount of vertices this mesh contains.
		const unsigned int VertexCount() const { return m_numOfVertices; }
		//Returns the amount of indices this mesh contains. Returns 0 if you are not using an EBO.
		const unsigned int IndexCount() const
		{
			if (m_useEBO)
				return m_numOfIndices;

			return 0;
		}

		bool IsReady() const { return m_ready; }
		const VAO& GetVAO() const { return m_vao; }
		const VBO& GetVBO() const { return m_vbo; }

		const bool Indexed() const { return m_useEBO; } //Is this mesh using an EBO?
	private:
		EBO m_ebo; //EBO is optional
		VAO m_vao;
		VBO m_vbo;

		size_t m_numOfVertices = 0;
		size_t m_numOfIndices = 0;

		bool m_useEBO = false;

		bool m_ready = true; //used to prevent render calls for uninitialized meshes
	};
}