#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "Utility/Debug.h"

namespace Crynn 
{
	class Mesh
	{
	public:
		/// <summary>
		/// Creates a renderable mesh.
		/// </summary>
		/// <param name="vertices">Array containing the vertices of your mesh.</param>
		/// <param name="indices">Array containing the indices of your mesh. If you do not wish to render with indices, set this to NULL, and useEBO to false.</param>
		/// <param name="numOfVertices">Number of elements in the vertices array.</param>
		/// <param name="numOfIndices">Number of elements in the indices array.</param>
		/// <param name="useEBO">Setting this to true will generate an element buffer, and render with indices.</param>
		Mesh(
			float* vertices,
			unsigned int* indices,
			size_t numOfVertices,
			size_t numOfIndices,
			bool useEBO);
		~Mesh();

		//Returns the amount of vertices this mesh contains.
		const unsigned int VertexCount() const { return m_numOfVertices; }
		//Returns the amount of indices this mesh contains. Returns 0 if you are not using an EBO.
		const unsigned int IndexCount() const 
		{ 
			if (m_useEBO)
				return m_numOfIndices; 

			return 0;
		}

		const unsigned int GetVAO() const { return VAO; }
		const unsigned int GetVBO() const { return VBO; }

		const bool Indexed() const { return m_useEBO; } //Is this mesh using an EBO?
	private:
		unsigned int VBO = 0, VAO = 0, EBO = 0;

		float* m_vertices;
		size_t m_numOfVertices;

		unsigned int* m_indices;
		size_t m_numOfIndices;

		bool m_useEBO;
	};
}