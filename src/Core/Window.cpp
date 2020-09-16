#include "Window.h"

namespace Crynn
{
	//Forward declarations of GLFW event functions
	void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void SizeCallback(GLFWwindow* window, int width, int height);

	Window::Window(const char* name, int width, int height)
	{
		Debug::ClearOutputLogs();

		//Glfw
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);

		//Window
		//Set the glfwWindow.
		glfwWindow = glfwCreateWindow(width, height, name, NULL, NULL);

		if (glfwWindow == NULL)
		{
			Debug::Log("Failed to create GLFW window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(glfwWindow);

		glfwSetFramebufferSizeCallback(glfwWindow, SizeCallback);
		glfwSetKeyCallback(glfwWindow, InputCallback);

		//Retrieve and set window size data
		int winWidth = 0, winHeight = 0;
		glfwGetWindowSize(glfwWindow, &winWidth, &winHeight);
		m_screenSize = ImVec2(winWidth, winHeight);

		//Retrieve and set framebuffer size data
		int frameBufWidth = 0, frameBufHeight = 0;
		glfwGetFramebufferSize(glfwWindow, &frameBufWidth, &frameBufHeight);
		m_frameBufSize = ImVec2(frameBufWidth, frameBufHeight);

		//Set the application instance to point to the window we just created. 
		//This is for easy cross engine access.
		Application::Instance().glfwWindow = glfwWindow;

		//Load glad
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Debug::Log("Failed to initialize GLAD");
			return;
		}

		//Init IMGUI
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
		ImGui_ImplOpenGL3_Init("#version 330 core");
		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		//Subscribe the window resize event. 
		Application::Instance().OnWindowResize.AddHandler([this](int width, int height)
		{
			UpdateWindowSize();
		});

		Debug::Log("Window Created");
	}

	Window::~Window()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		glfwDestroyWindow(glfwWindow);
		glfwTerminate();
	}

	const ImVec2& Window::GetSize()
	{
		return m_screenSize;
	}

	const ImVec2& Window::GetFrameBufSize()
	{
		return m_frameBufSize;
	}

	//Processes input, runs glClear and creates an IMGUI frame.
	void Window::BeforeRender()
	{		
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//TODO Move this out
		//Create dockspace
		//ImGui::DockSpaceOverViewport(ImGui::GetWindowViewport(), ImGuiDockNodeFlags_None);

		glViewport(0, 0, m_screenSize.x, m_screenSize.y); //Set the default viewport.

		//Setup polling, new frames and clear buffers
	}

	//Called after rendering code. Ends IMGUI frames, swaps buffers, and polls events.
	void Window::AfterRender()
	{
		// Render dear imgui into screen
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(glfwWindow);
	}

	void Window::UpdateWindowSize()
	{
		int width, height, frameBufWidth, frameBufHeight;
		glfwGetWindowSize(glfwWindow, &width, &height);
		glfwGetFramebufferSize(glfwWindow, &frameBufWidth, &frameBufHeight);

		m_screenSize = ImVec2(width, height);
		m_frameBufSize = ImVec2(frameBufWidth, frameBufHeight);

		Debug::Log("OnWindowResize Dispatched!");
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(glfwWindow);
	}

	//GLFW event functions
	void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Application::Instance().OnInput.Invoke(window, key, scancode, action, mods);
	}

	void SizeCallback(GLFWwindow* window, int width, int height)
	{
		Application::Instance().OnWindowResize.Invoke(width, height);
	}
}