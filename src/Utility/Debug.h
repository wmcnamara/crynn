#pragma once
#include "File.h"
#include "glad/glad.h"
#include "Timer.h"
namespace Crynn
{
	/// <summary>
	/// Collection of functions to assist with debugging.
	/// </summary>
	class Debug
	{
	public:
		/// <summary>
		/// Changes the appearance of your message in the console.
		/// </summary>
		enum MsgType
		{
			Error, //Displays in red.
			Warning, //Displays in yellow.
			Message, //Meant for any message. No text color modifications.
			Success //Denotes the success of any operation. Displays in green.
		};

		//Writes msg to output.log, and std::cout.
		static void Log(const std::stringstream& msg, MsgType msgType);
		static void Log(const char* msg, MsgType msgType);
		static void Log(const char* msg); //Logs as MsgType::Message

		/// <summary>
		/// Logs glGetError to std::cout and output.log
		/// </summary>
		static void LogGLErr();

		/// <summary>
		/// Clears output.log
		/// </summary>
		static void ClearOutputLogs();
	};
}