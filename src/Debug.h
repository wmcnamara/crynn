#pragma once
#include "IO.h"
#define LOGERR() std::cout << glGetError() << std::endl;

enum MsgType
{
	Error, //Displays in red.
	Warning, //Displays in yellow.
	Message, //Meant for any message. No text color modifications.
	Success //Denotes the success of any operation. Displays in green.
};

namespace Debug
{
	//Writes msg to output.log, and std::cout.
	static void Log(const std::stringstream& msg, MsgType msgType)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		std::ofstream log;
		log.open("output.log", std::ios_base::app);

		switch (msgType) 
		{
			case Error:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				break;
			case Warning:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			case Message:
				break;
			case Success:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				break;
		}

		std::cout << msg.rdbuf() << std::endl;
		log << msg.rdbuf() << std::endl;

		log.close();
	}

	static void Log(const char* msg, MsgType msgType)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		std::ofstream log;
		log.open("output.log", std::ios_base::app);

		switch (msgType)
		{
			case Error:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				break;
			case Warning:
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN); //Yellow
				break;
			case Message:
				SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //White
				break;
			case Success:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				break;
		}

		std::cout << msg << std::endl;
		log << msg << std::endl;

		log.close();
	}

	static void ClearOutputLogs()
	{
		std::ofstream log;

		log.open("output.log");
			log << " " << std::endl;
		log.close();
	}
};

