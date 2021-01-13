#include "Debug.h"

namespace crynn
{
	void Debug::Log(const std::stringstream& msg)
	{
#ifdef CRYNN_DEBUG
		std::cout << std::fixed << msg.rdbuf() << '\n';
#endif
	}

	void Debug::Log(const char* msg)
	{
#ifdef CRYNN_DEBUG
		std::cout << std::fixed << msg << '\n';
#endif
	}

	void Debug::LogToFile(const char* msg)
	{
#ifdef CRYNN_DEBUG
		//TODO safely cache the log stream so that it doesnt need to be reopened and closed all the time
		std::ofstream log;

		log.open("output.log");
		log << msg << "\n";
		log.close();
#endif
	}

	void Debug::LogToFile(const std::stringstream& msg)
	{
#ifdef CRYNN_DEBUG
		std::ofstream log;

		log.open("output.log");
		log << msg.rdbuf() << '\n';
		log.close();
#endif
	}

	void Debug::LogMatrix4(const glm::mat4& matrix)
	{
#ifdef CRYNN_DEBUG
		std::cout << "Matrix 4:" << "\n";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << matrix[j][i] << " ";;
			}
			std::cout << "\n";
		}
		std::cout << "\n\n";
#endif
	}

	void Debug::LogGLErr()
	{
#ifdef CRYNN_DEBUG
		std::stringstream output;		
		output << "GL ERROR: " << glGetError() << '\n';

		std::cout << output.rdbuf() << '\n';
		LogToFile(output);
#endif
	}

	void Debug::ClearOutputLogs()
	{
#ifdef CRYNN_DEBUG
		std::ofstream log;

		log.open("output.log");
		log << "";
		log.close();
#endif
	}
}