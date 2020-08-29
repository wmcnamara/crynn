#pragma once
#include "glad/glad.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"
#include <future>
#include <mutex>

class MeshRenderer
{
public:
	MeshRenderer(Mesh* mesh, Texture* texture, Shader* shader);

	void Render();

	bool active = true;
	glm::mat4 model = glm::mat4(1.0f);

	const Mesh* GetMesh() const { return m_mesh; }
private:
	Mesh* m_mesh;
	Texture* m_texture;
	Shader* m_shader;
	bool m_indexed;
};

