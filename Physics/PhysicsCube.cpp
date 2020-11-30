#include "PhysicsCube.h"

PhysicsCube::PhysicsCube(Mesh* mesh, Shader* shader, Texture* texture) :
	m_mesh(mesh),
	m_shader(shader),
	m_texture(texture),
	m_renderer(std::make_unique<MeshRenderer>(mesh, texture, shader, &GetMatrix())) {}

void PhysicsCube::Update(double deltaTime)
{
	/*
	double tSqr = pow(deltaTime, 2);
	static double displacement = 0;
	displacement += (g / 2.0) * tSqr; //gravity
	*/

	float xPos = 0; 
	float yPos = 0; 

	xPos += sin(Application::GetTime()) / 20;
	yPos += sin(Application::GetTime()) / 20;

	//x += sin(deltaTime);
	//float yPos = (a * pow(x, 2)) + b * x + c; //Quadratic
	Translate(xPos, yPos, 0);
}
