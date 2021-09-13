#include "GLFWManager.h"
#include <GLFW/glfw3.h>
#include <iostream>

GLFWManager::GLFWManager()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glfwMajorVersion);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glfwMinorVersion);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, AASamples);

	if (glfwInit() == GLFW_TRUE) 
	{
		std::cout << "GLFW successfully initialized...\n";
	}
	else
	{
		throw std::exception("GLFW failed to initialize!");
	}
}

GLFWManager::~GLFWManager()
{
	std::cout << "Terminating GLFW\n";
	glfwTerminate();
}
