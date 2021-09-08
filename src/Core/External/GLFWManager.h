#pragma once
#include <atomic>

//TODO Write all GLFW function subscriptions in here and call it from the application start.
//This will clean up the GLFW code in Window and Application
class GLFWManager
{
public:
	GLFWManager(int glfwMajorVersion = 3, int glfwMinorVersion = 3, int AASamples = 4);
	~GLFWManager();

private:
	static GLFWManager m_instance;
};

