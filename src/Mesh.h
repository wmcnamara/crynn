#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include "Debug.h"

//Attributes are evaluated in this order, with position before all of them.
enum MeshAttribFlags
{
	MeshAttribFlags_TexCoords = 1, //Accepted as a float* with 2 elements representing texture coordinates.
	MeshAttribFlags_Color = 2, //Accepted as a float* with 4 elements representing RGBA.
};

/*
struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture
{
	unsigned int id;
	std::string type;
};
*/
class Mesh
{
public:
	/* //TODO
	Mesh(
		Vertex* vertices,
		unsigned int* indices,
		Texture* textures,
		size_t numOfTextures,
		size_t numOfVertices,
		size_t numOfIndices,
		bool useEBO);
	*/
	Mesh(
		float* vertices,
		unsigned int* indices,
		size_t numOfVertices,
		size_t numOfIndices,
		bool useEBO);
	~Mesh();

	const unsigned int VertexCount() const { return m_numOfVertices; }
	const unsigned int IndexCount() const { return m_numOfIndices; }

	const unsigned int GetVAO() const { return VAO; }
	const unsigned int GetVBO() const { return VBO; }

	const bool Indexed() const { return m_useEBO; } //Is this mesh using an EBO?

private:
	unsigned int VBO = 0, VAO = 0, EBO = 0;

	float* m_vertices;	
	size_t m_numOfVertices;

	unsigned int* m_indices;
	size_t m_numOfIndices;

	/*
	Texture* m_textures;
	size_t m_numOfTextures;
	*/

	bool m_useEBO;
};
