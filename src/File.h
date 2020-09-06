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
	//Contains the filepath retrieved from the picker.
	struct GetFileArgs
	{
		std::string filePath;
	};

	class File
	{
	public:
		static std::string GetFile();
	};
}