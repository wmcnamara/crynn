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

#include "assimp/scene.h"
class File
{
public:
	static std::string GetFile();

private:
};

//Contains the filepath retrieved from the picker.
struct GetFileArgs 
{
	std::string filePath;
};

//Contains the filepaths retrieved from the picker.
struct GetFilesArgs 
{
	size_t numOfFiles;
	std::string* filePaths;
};