#pragma once
#include "File.h"
#include "glad/glad.h"
#include "Timer.h"
namespace Crynn
{
	class Debug
	{
	public:
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
		static void LOGGLERR();
		static void ClearOutputLogs();
	};
}