#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Shader.h"

using namespace glm;

enum class Projection
{
	Orthographic,
	Perspective
};

class Camera
{
public:
	Camera(vec3 _position, vec3 _target, Projection projType) :
		position(position),
		target(target),
		m_projType(projType)
	{
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); //TODO

		UpdatePositionData();
		UpdateProjectionData();	
	}

	// camera Attributes
	vec3 position;
	vec3 front;
	vec3 up;
	vec3 right;
	vec3 worldUp;
	vec3 target;

    mat4 GetProjection() const { return projection; }
	mat4 view = mat4(1.0f);

	void Run() { UpdatePositionData(); UpdateProjectionData(); }
	static void Input();
private:
	mat4 projection;
	Projection m_projType;

	void UpdatePositionData();
	void UpdateProjectionData();
};

