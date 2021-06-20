#pragma once
#pragma warning (disable : 4005)

#include <Windows.h>
#include "stb_image.h"
#include "imgui/imgui.h"
#include <string>
#include <iostream>

#include <shobjidl.h> 
#include <stdlib.h>
#include <fstream>
#include <exception>
#include <ostream>
#include <sstream>
#include <memory>
#include <filesystem>
#include "../Core/Event.h"
#include "../Core/Window.h"
#include "GLFW/glfw3.h"

namespace crynn
{
	namespace fs = std::filesystem;

	//Relevant file data returned from GetMediaFile.
	struct GetFileData 
	{
		bool succeeded = false; //does the file exist?
		std::string absoluteFilePath = "";
	};

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

		//Returns a boolean indicating whether a file at a given path exists
		static [[nodiscard]] bool FileExists(const char* relativePath);

		/// <summary>
		/// Opens a picker that allows the user to select an image.
		/// Works on windows exclusively.
		/// </summary>
		/// <returns>string containing the selected image filepath.</returns>
		static [[nodiscard]] std::string OpenImageFilePicker();

		/// <summary>
		/// Event called when the user drags files from the operating system into the application. Useful for imports.
		/// The event dispatches a single file as the parameter, but is invoked however many files the user drops a file.
		/// For exmaple, if the user drops 3 files, OnFileDrop will be invoked 3 times with the corresponding paths.
		/// </summary>
		static inline Event<const char*> OnFileDrop;
		 
		//Allocates and loads a file into a string.
		//Returns an empty string if the file fails to load
		static [[nodiscard]] std::string LoadFileStr(const char* relativePath);

		//Adds a directory that will be searched for a file
		//Expects a path relative to the exe / working directory.
		//Returns a boolean indicating if the suggested path was found.
		static bool AddMediaPath(const char* path);

		//Searches working directory and media paths for a file with the relative path @param name. 
		//Returns the first file found matching the given name.
		//Avoid duplicate filenames to avoid clashes from this function
		//Returnsa GetFileData object with info about the requested file.
		static [[nodiscard]] GetFileData GetMediaFile(const char* name) = delete;

	private:
		static inline std::vector<fs::path> mediaPaths;
	};
}