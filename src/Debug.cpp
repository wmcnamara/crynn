#include "Debug.h"

void Crynn::Debug::Log(const std::stringstream& msg, MsgType msgType)
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
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case Success:
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		break;
	}

	std::cout << msg.rdbuf() << '\n';
	log << msg.rdbuf() << '\n';

	log.close();
}

void Crynn::Debug::Log(const char* msg, MsgType msgType)
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

void Crynn::Debug::Log(const char* msg)
{
	std::ofstream log;
	log.open("output.log", std::ios_base::app);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //White

	std::cout << msg << '\n';
	log << msg << '\n';
	log.close();
}

void Crynn::Debug::LOGGLERR()
{
	std::cout << glGetError() << '\n';
}

void Crynn::Debug::ClearOutputLogs()
{
	std::ofstream log;

	log.open("output.log");
	log << " " << '\n';
	log.close();
}
