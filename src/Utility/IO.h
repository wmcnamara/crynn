#pragma once
#include "stb_image.h"
#include "imgui.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include <shobjidl.h> 
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <memory>
#include "Core/Event.h"

namespace crynn
{
	/// <summary>
	/// File related functions to allow user to open files.
	/// </summary>
	class IO
	{		
	public:	
		/// Structure containing the filepath retrieved from the picker.
		struct GetFileArgs
		{
			std::string filePath;
		};

		/// <summary>
		/// Opens a picker that allows the user to select a file.
		/// Works on windows exclusively.
		/// </summary>
		/// <returns>A GetFileArgs object containing the selected filepath.</returns>
		static GetFileArgs GetFile();

		/// <summary>
		/// Event called when the user drags files from the operating system into the application. Useful for imports.
		/// The event dispatches a single file as the parameter, but is invoked however many files the user drops a file.
		/// For exmaple, if the user drops 3 files, OnFileDrop will be invoked 3 times with the corresponding paths.
		/// </summary>
		static inline Event<const char*> OnFileDrop;
	};
}