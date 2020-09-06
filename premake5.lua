workspace "Crynn"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Crynn"
	location "src"
	kind "SharedLib"
	language "C++"

	targetDir = ("bin/" .. outputDir .. "/%{prj.name}")
	objDir = ("bin-int/" .. outputDir .. "/%{prj.name}")

	files 
	{
		"src/**.h"
		"src/**.cpp"
	}

	include 
	{
		"src\lib\thirdparty\assimp\include"
		"src\lib\thirdparty\glad"
		"src\lib\thirdparty\glfw\include"
		"src\lib\thirdparty\glm"
		"src\lib\thirdparty\imgui"
		"src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"CRYNN_PLATFORM_WINDOWS"
		}

		postbuildcommands 
		{
			("")
		}

	filter "configuration:Debug"