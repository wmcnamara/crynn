#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "Utility/Debug.h"
#include "Utility/Timer.h"
#include "Buffers/Buffers.h"
namespace crynn
{
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
			bool useEBO);
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

		const VAO& GetVAO() const { return m_vao; }
		const VBO& GetVBO() const { return m_vbo; }

		const bool Indexed() const { return m_useEBO; } //Is this mesh using an EBO?
	private:
		EBO m_ebo; //EBO is optional
		VAO m_vao;
		VBO m_vbo;

		float* m_vertices;
		size_t m_numOfVertices;

		unsigned int* m_indices;
		size_t m_numOfIndices;

		bool m_useEBO;
	};
}