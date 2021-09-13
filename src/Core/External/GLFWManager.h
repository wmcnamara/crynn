#pragma once
#include <atomic>

//Configuration for the opengl versioning and anti aliasing samples for GLFW
//Change these to whatever you desire 

constexpr inline int glfwMajorVersion = 3;
constexpr inline int glfwMinorVersion = 3;
constexpr inline int AASamples = 4;

//TODO Write all GLFW function subscriptions in here and call it from the application start.
//This will clean up the GLFW code in Window and Application
class GLFWManager
{
public: 
	static GLFWManager& Instance() 
	{
		static GLFWManager S;
		return S;
	}
private:
	GLFWManager();
	~GLFWManager();
};

