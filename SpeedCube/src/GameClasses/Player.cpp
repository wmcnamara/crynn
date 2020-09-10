#include "Player.h"

Player::Player()
{	
	m_mesh = new Mesh(m_vertices, NULL, 180, 0, false);
	m_shader = new Shader("data/shaders/Standard.vert", "data/shaders/Standard.frag");
	m_texture = new Texture("data/assets/crate.jpg");
	m_camera = new Camera(vec3(0, 0, -3), Projection::Perspective);	
	m_renderer = new MeshRenderer(m_mesh, m_texture, m_shader, &transformMatrix);
}

Player::~Player()
{
	delete m_renderer;
	delete m_mesh;
	delete m_shader;
	delete m_texture;
	delete m_camera;
}

void Player::Render()
{
	glEnable(GL_DEPTH_TEST);
	m_renderer->Render();
}

void Player::InputCommands()
{
	if (Input::GetKey(KeyCode::ESC))
		Application::Instance().Quit();

	if (Input::GetKey(KeyCode::D))
		Translate(vec3(1, 0, 0));
	
	if (Input::GetKey(KeyCode::A))
		Translate(vec3(-1, 0, 0));

	if (Input::GetKey(KeyCode::G)) 
		SetPosition(0, 0, 0); //Reset pos
}

void Player::Update(double deltaTime)
{
	//Move cube forward
	Translate(vec3(0, 0, deltaTime * -movementSpeed));
	Render();
}

void Player::Start()
{	
	m_camera->Rotate(20.0f, vec3(1, 0, 0));
	m_camera->Translate(vec3(0, -0.6f, 0));
}
