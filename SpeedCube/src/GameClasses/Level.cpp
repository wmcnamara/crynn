#include "Level.h"

Level::Level()
{
	m_mesh = new Mesh(m_vertices, NULL, 30, 0, false); 
	m_shader = new Shader("data/shaders/Standard.vert", "data/shaders/Standard.frag");	
	m_texture = new Texture("data/assets/wall.jpg");
	m_renderer = new MeshRenderer(m_mesh, m_texture, m_shader, &transformMatrix);
}

void Level::Update(double deltaTime)
{
	m_renderer->Render();
}

void Level::Start()
{
	Transform::Translate(vec3(0, -1, 0));
	Transform::Scale(vec3(10, 0, -60));
	Transform::Rotate(90.0f, vec3(1, 0, 0));
}

void Level::InputCommands()
{
	if (Input::GetKey(KeyCode::SPACE))
		m_renderer->active = !m_renderer->active;
}
