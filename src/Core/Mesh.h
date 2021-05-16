#pragma once
#include "glm/glm.hpp"
#include "../Utility/Debug.h"
#include "../Utility/Timer.h"
#include "Buffers/Buffers.h"
#include "glad/glad.h"
#include "Rendering/Shader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace crynn
{
	enum VertexAttribFlags
	{
		VertexAttribNone = (1 << 0),
		VertexAttribTexCoords = (1 << 2),
		VertexAttribNormVec = (1 << 3),

		VertexAttribSTL = VertexAttribNormVec //Vertex attributes for an STL file
	};

	//Model vertex data
	struct Vertex 
	{
		Vec3 Pos;
		Vec3 Normal;
		Vec2 TexCoord;
	};

	//Internal model mesh texture data
	struct MeshTexData 
	{
		unsigned int id = 0;
		std::string type;
		std::string path;
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

		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<MeshTexData> textures;
		
		const GLuint& GetVAOID() const { return m_vao; }
		const GLuint& GetVBOID() const { return m_vbo; }

		void Render(const Shader& shader) const;
	private:
		GLuint m_ebo = 0;
		GLuint m_vao = 0;
		GLuint m_vbo = 0;
	};

	//Adapted model loading from
	//https://learnopengl.com/Model-Loading/Model

	class Model
	{
	public:
		Model(const char* path);

		void Render(const Shader& shader) const;

	private:
		std::vector<Mesh> m_meshes;
		std::string directory;

		void LoadModel(std::string path);
		void ProcessNode(aiNode* node, const aiScene* scene);
		Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<MeshTexData> LoadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
		std::vector<MeshTexData> textures_loaded;
	};
}