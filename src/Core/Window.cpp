#include "Window.h"
#include "Input.h"
#include "../Utility/IO.h"

namespace crynn
{
	void SizeCallback(GLFWwindow* window, int width, int height)
	{
		Window::instance().OnWindowResize.Invoke(width, height);
	}

	void CloseCallback(GLFWwindow* window) 
	{
		Application::OnBeforeClose.Invoke();
	}

	Window::Window(const char* name, unsigned int width, unsigned int height)
	{
		//Glfw
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_SAMPLES, 4);
		
		m_glfwWindow = glfwCreateWindow(width, height, name, NULL, NULL);
		
		if (m_glfwWindow == NULL)
		{
			Debug::Log("Failed to create GLFW window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(m_glfwWindow);
		glfwSetFramebufferSizeCallback(m_glfwWindow, SizeCallback);

		UpdateWindowSize();

		//Subscribe the window resize event. 
		OnWindowResize.AddHandler([this](int width, int height)
			{
				UpdateWindowSize();
			});


		glfwSetWindowCloseCallback(m_glfwWindow, [](GLFWwindow* window) { Application::OnBeforeClose.Invoke(); });

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
		ImGui_ImplGlfw_InitForOpenGL(m_glfwWindow, true);
		ImGui_ImplOpenGL3_Init("#version 330 core");
		// Setup Dear ImGui style
		ImGui::StyleColorsDark();

		Debug::Log("Window Created");
	}
	
	GLFWwindow* Window::GetGLFWWindow()
	{
		return m_glfwWindow;
	}

	Window::~Window()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
		glfwDestroyWindow(m_glfwWindow);
		glfwTerminate();
	}

	const Vec2Int& Window::GetSize()
	{
		return m_screenSize;
	}

	const Vec2Int& Window::GetFrameBufSize()
	{
		return m_frameBufSize;
	}

	void Window::SetWindowName(std::string_view str)
	{
		glfwSetWindowTitle(m_glfwWindow, str.data());
	}

	void Window::SetWindowSize(int x, int y)
	{
		glfwSetWindowSize(m_glfwWindow, x, y);

		int fbX, fbY;
		glfwGetFramebufferSize(m_glfwWindow, &fbX, &fbY);

		m_screenSize = Vec2Int(x, y);
		m_frameBufSize = Vec2Int(fbX, fbY);
	}

	//Processes input, runs glClear and creates an IMGUI frame.
	void Window::BeforeRender(FrameEventData data)
	{		
		glfwPollEvents();
		data.inputComponent->PollInput();

		//setup IMGUI
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//clear buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//TODO Move this out
		//Create dockspace
		//ImGui::DockSpaceOverViewport(ImGui::GetWindowViewport(), ImGuiDockNodeFlags_None);

		//Setup viewport
		glViewport(0, 0, (int)m_screenSize.x, (int)m_screenSize.y); //Set the default viewport.

	}

	//Called after rendering code. Ends IMGUI frames, swaps buffers, and polls events.
	void Window::AfterRender()
	{
		// Render dear imgui into screen
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(m_glfwWindow);
	}

	void Window::UpdateWindowSize()
	{
		int width, height, frameBufWidth, frameBufHeight;
		glfwGetWindowSize(m_glfwWindow, &width, &height);
		glfwGetFramebufferSize(m_glfwWindow, &frameBufWidth, &frameBufHeight);

		m_screenSize = Vec2Int(width, height);
		m_frameBufSize = Vec2Int(frameBufWidth, frameBufHeight);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(m_glfwWindow);
	}

}