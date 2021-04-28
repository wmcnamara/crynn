#pragma once
#include "glm/glm.hpp"
#include "../Utility/Debug.h"
#include "../Utility/Timer.h"
#include "Buffers/Buffers.h"
#include "../Utility/Parsers/STLParser.h"
#include "glad/glad.h"
#include "assimp/scene.h"

namespace crynn
{
	enum VertexAttribFlags
	{
		VertexAttribNone = (1 << 0),
		VertexAttribTexCoords = (1 << 2),
		VertexAttribNormVec = (1 << 3),

		VertexAttribSTL = VertexAttribNormVec //Vertex attributes for an STL file
	};

	struct Vertex 
	{
		Vec3 Pos;
		Vec3 Normal;
		Vec2 TexCoord;
	};

	struct MeshTexData 
	{
		unsigned int id;
		std::string type;
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
			std::vector<Vertex> _vertices,
			std::vector<unsigned int> _indices,
			std::vector<MeshTexData> _textures);

		~Mesh();
		Mesh(Mesh& other) = delete;
		Mesh operator=(Mesh& other) = delete;

		Mesh(Mesh&& other) = delete;
		Mesh operator=(Mesh&& other) = delete;

		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<MeshTexData> textures;
		
		bool IsReady() const { return m_ready; }
		const VAO& GetVAO() const { return m_vao; }
		const VBO& GetVBO() const { return m_vbo; }

	private:
		EBO m_ebo;
		VAO m_vao;
		VBO m_vbo;

		bool m_ready = true; //used to prevent render calls for uninitialized meshes
	};

	class Model
	{
	public:
		Model(const char* path);

		//TODO move to MeshRenderer
		void Render();

	private:
		std::vector<Mesh> m_meshes;
		const char* directory;

		void LoadModel(const char* path);
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<MeshTexData> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	};
}