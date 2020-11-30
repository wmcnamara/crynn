#pragma once
#include <Crynn.h>
#include <array>
using namespace Crynn;

class PhysicsCube : public CrynnObject
{
public:
	PhysicsCube(Mesh* mesh, Shader* shader, Texture* texture);

	float GetVel() { return velocity; }
	float GetAcc() { return acceleration; }
private:
	std::unique_ptr<MeshRenderer> m_renderer;

	Mesh* m_mesh;
	Shader* m_shader;
	Texture* m_texture;

	void Update(double deltaTime) override;
	AABB boundingBox{ *this, vec3(1, 1, 1) };

	float velocity = 0.0f;
	float acceleration = 0.0f;
	float previousVelocity = 0.0f; //Used to calculate acceleration

	float a = -1, b = 0.01, c = 0.01, x = 0.0f; //quadratic
};

const double g = -9.81;