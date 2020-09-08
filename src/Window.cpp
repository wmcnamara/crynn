#include "Window.h"

namespace Crynn
{
	void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	//TODO Fix
	void SizeCallback(GLFWwindow* window, int width, int height)
	{
		Application::Instance().OnWindowResize.Invoke(width, height);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(glfwWindow);
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
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//TODO Move this out
		//Create dockspace
		//ImGui::DockSpaceOverViewport(ImGui::GetWindowViewport(), ImGuiDockNodeFlags_None);

		glViewport(0, 0, m_screenSize.x, m_screenSize.y); //Set the default viewport.

		//Setup polling, new frames and clear buffers
		glfwPollEvents();
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
	}

	Window::Window(const char* name, int width, int height)
	{
		Debug::ClearOutputLogs();
		Debug::Log("Crynn Debug Started...");

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
			Debug::Log("Failed to create GLFW window", Debug::Error);
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(glfwWindow);

		glfwSetFramebufferSizeCallback(glfwWindow, SizeCallback);
		glfwSetKeyCallback(glfwWindow, InputCallback);

		//Get the window size, and framebuffer dimensions, and setup sizing.
		int scrWidth = 0, scrHeight = 0, frameBufWidth = 0, frameBufHeight = 0;
		glfwGetWindowSize(glfwWindow, &scrWidth, &scrHeight);
		glfwGetFramebufferSize(glfwWindow, &frameBufWidth, &frameBufHeight);

		m_screenSize = ImVec2(scrWidth, scrHeight);
		m_frameBufSize = ImVec2(frameBufWidth, frameBufHeight);

		Application::Instance().glfwWindow = glfwWindow; 

		//Glad
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			Debug::Log("Failed to initialize GLAD", Debug::Error);
			return;
		}

		//Init IMGUI
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		//ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
		ImGui_ImplOpenGL3_Init("#version 330 core");
		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		Application::Instance().OnWindowResize.AddHandler([this](int width, int height) 
		{
			UpdateWindowSize();
		});
	}

	void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Application::Instance().OnInput.Invoke();
	}
}