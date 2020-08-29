#include "Window.h"

void InputCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

//TODO Fix
void SizeCallback(GLFWwindow* window, int width, int height) 
{
	Window::Instance().SetSize(width, height);
	Window::Instance().OnWindowResize.Invoke(ImVec2(width, height));
}

Window::~Window()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

ImVec2 Window::GetFrameBufSize()
{
	int width, height;
	glfwGetFramebufferSize(m_window, &width, &height);

	return ImVec2(width, height);
}

//Processes input, runs glClear and creates an IMGUI frame.
void Window::BeforeRender()
{
	//Setup polling, new frames and clear buffers
	glfwPollEvents();

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Measure speed
	double currentTime = glfwGetTime();
	static int internalFrameCount;
	internalFrameCount++;

	// If a second has passed.
	if (currentTime - previousTime >= 1.0)
	{
		// Display the frame count here any way you want.
		frameCount = internalFrameCount;
		internalFrameCount = 0;
		previousTime = currentTime;
	}

	//Create dockspace
	ImGui::DockSpaceOverViewport(ImGui::GetWindowViewport(), ImGuiDockNodeFlags_None);
}

//Called after rendering code. Ends IMGUI frames, swaps buffers, and polls events.
void Window::AfterRender()
{
	// Render dear imgui into screen
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(m_window);
}


Window::Window()
{
	Debug::ClearOutputLogs();
	Debug::Log("WMEngine Debug Started...", Message);

	//Glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	//Window //TODO
	m_window = glfwCreateWindow(DEFAULT_SCR_WIDTH, DEFAULT_SCR_HEIGHT, "WMEngine", NULL, NULL);
	if (m_window == NULL)
	{
		Debug::Log("Failed to create GLFW window", Error);
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(m_window);

	//Glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Debug::Log("Failed to initialize GLAD", Error);
		return;
	}

	glfwSetFramebufferSizeCallback(m_window, SizeCallback);

	//Init IMGUI
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	//ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(m_window, true);
	ImGui_ImplOpenGL3_Init("#version 330 core");
	// Setup Dear ImGui style
	ImGui::StyleColorsDark();

	//Get the window framebuffer dimensions, and setup sizing.
	int width, height;
	glfwGetFramebufferSize(m_window, &width, &height);

	screenSize = ImVec2(width, height);
	
	//Invoke OnWindowStart with the args object.
	OnWindowStart.Invoke(OnWindowStartArgs{ ImVec2(width, height) }); 

	glfwSetKeyCallback(m_window, InputCallback);
}

void InputCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}