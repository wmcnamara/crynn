#include "Debug.h"

namespace Crynn
{
	void Debug::Log(const std::stringstream& msg, MsgType msgType)
	{
		//This console color text stuff is windows specific
		#if defined (__WIN_32__)
		//Grab a handle to the console
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		switch (msgType)
		{
		case Error:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			break;
		case Warning:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
			break;
		case Message:
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			break;
		case Success:
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			break;
		}
		#endif

		//Log to cout
		std::cout << msg.rdbuf() << '\n';

		//Dump to output.log
		std::ofstream log;
		log.open("output.log", std::ios_base::app);
		log << msg.rdbuf() << '\n';
		log.close();
	}

	void Debug::Log(const char* msg, MsgType msgType)
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

		std::cout << msg << '\n';
		log << msg << '\n';

		log.close();
	}

	void Debug::Log(const char* msg)
	{
		std::ofstream log;
		log.open("output.log", std::ios_base::app);

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //White

		std::cout << msg << '\n';
		log << msg << '\n';
		log.close();
	}

	void Debug::LogGLErr()
	{
		std::stringstream output;		
		output << glGetError() << '\n';

		Debug::Log(output, MsgType::Error);
	}

	void Debug::ClearOutputLogs()
	{
		std::ofstream log;

		log.open("output.log");
		log << "";
		log.close();
	}
}