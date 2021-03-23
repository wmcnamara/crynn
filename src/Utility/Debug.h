#pragma once
#include "glad/glad.h"
#include "glm/glm.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Defines.h"

namespace crynn
{
	/// <summary>
	/// Collection of functions to assist with debugging.
	/// These are only ran in debug configurations, or when the CRYNN_DEBUG macro is defined.
	/// File log functions are very slow.
	/// </summary>
	class Debug
	{
	public:
		static void Log(const std::stringstream& msg); ///Writes msg to std::cout.
		static void Log(const char* msg); ///Writes msg to std::cout.

		static void LogToFile(const char* msg); /// Logs to output.log in the working directory. This function is not fast.
		static void LogToFile(const std::stringstream& msg); /// Logs to output.log in the working directory. This function is not fast.

		static void LogMatrix4(const glm::mat4& matrix);
		static void LogGLErr(); /// Logs glGetError to std::cout and output.log
		static void ClearOutputLogs(); /// Clears output.log
	};
}