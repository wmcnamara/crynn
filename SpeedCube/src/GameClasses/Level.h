#pragma once
#include <Crynn.h>

class Level : protected Behaviour, protected Input, public Transform
{
public:
	Level();
private:
	//Vertices to represent a plane
	float m_vertices[30] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,	
	};

	Mesh* m_mesh;
	Shader* m_shader;	
	Texture* m_texture;
	MeshRenderer* m_renderer;

	void Update(double deltaTime) override;
	void Start() override;
	void InputCommands() override;
};

