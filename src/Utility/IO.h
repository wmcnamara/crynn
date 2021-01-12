#pragma once
#include "stb_image.h"
#include "imgui/imgui.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <shobjidl.h> 
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <memory>
#include "Core/Event.h"
#include "Core/Window.h"
#include "GLFW/glfw3.h"

namespace crynn
{
	/// <summary>
	/// IO related functions to allow user to open and manipulate files
	/// </summary>
	class IO
	{		
	public:	
		/// <summary>
		/// Initialises IO events like OnFileDrop, and must be called before they work.
		/// Called in the constructor for the window.
		/// </summary>
		static void Init();

		/// <summary>
		/// Opens a picker that allows the user to select a file.
		/// Works on windows exclusively.
		/// </summary>
		/// <returns>string containing the selected filepath.</returns>
		static std::string GetFile();

		/// <summary>
		/// Event called when the user drags files from the operating system into the application. Useful for imports.
		/// The event dispatches a single file as the parameter, but is invoked however many files the user drops a file.
		/// For exmaple, if the user drops 3 files, OnFileDrop will be invoked 3 times with the corresponding paths.
		/// </summary>
		static inline Event<const char*> OnFileDrop;
	};
}