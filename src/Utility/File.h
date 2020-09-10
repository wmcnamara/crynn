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

namespace Crynn
{
	/// <summary>
	/// File related functions to allow user to open files.
	/// </summary>
	class File
	{		
	public:	
		/// Structure containing the filepath retrieved from the picker.
		struct GetFileArgs
		{
			std::string filePath;
		};

		/// <summary>
		/// Opens a picker that allows the user to select a file.
		/// </summary>
		/// <returns>A GetFileArgs object containing the selected filepath.</returns>
		static GetFileArgs GetFile();
	};
}