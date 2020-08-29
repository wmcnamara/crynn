#pragma once
#include "Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Light
{
public:
	Light();
	Light(glm::vec3 color);

	Light(Mesh mesh, glm::vec3 color)
	{

	}
};

