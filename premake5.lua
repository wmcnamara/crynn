workspace "Crynn"
	startproject "SpeedCube"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

project "Crynn"
	kind "StaticLib"
	language "C++"
	runtime "Debug"

	targetdir = "bin"
	objdir = "bin/obj"

	files
	{
		"src/**.h",
		"src/**.hpp",
		"src/**.cpp",
		"lib/thirdparty/glad/glad/glad.c",
		"lib/thirdparty/imgui/imgui.h",
		"lib/thirdparty/imgui/imgui.cpp",
		"lib/thirdparty/imgui/imconfig.h",
		"lib/thirdparty/imgui/imgui_draw.cpp",
		"lib/thirdparty/imgui/imgui_impl_glfw.cpp",
		"lib/thirdparty/imgui/imgui_impl_glfw.h",
		"lib/thirdparty/imgui/imgui_impl_opengl3.cpp",
		"lib/thirdparty/imgui/imgui_impl_opengl3.h",
		"lib/thirdparty/imgui/imgui_internal.h",
		"lib/thirdparty/imgui/imgui_widgets.cpp",
		"lib/thirdparty/stb_image.h",
		"lib/thirdparty/stb_perlin.h",
		"data/shaders/Standard.vert",
		"data/shaders/Standard.frag",

		"premake5.lua",
		"README.md"
	}

	includedirs
	{
		"src/",
		"lib/thirdparty",
		"lib/thirdparty/glm",
		"lib/thirdparty/glad",
		"lib/thirdparty/imgui",
		"lib/thirdparty/glfw/include"
	}

	libdirs
	{
		"lib/thirdparty/glfw/lib"
	}

	links { "glfw3.lib", "opengl32.lib" }

	filter "system:Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CRYNN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines
		{
			"CRYNN_DEBUG"
		}
		symbols "On"
		runtime "Debug"