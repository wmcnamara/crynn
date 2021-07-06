#pragma once
/*
	You can add defines to the top of this file to have them apply to specific crynn components that may use them.

	EXAMPLE DEFINES:

	#define CRYNN_SHOW_FPS //shows the FPS of the program in the window title
*/

/////////PUT YOUR DEFINES HERE////////////



#define NODISCARD [[nodiscard]]
#define DLLEXPORT extern "c" __declspec(dllexport)

#ifdef _WIN32 
#define CRYNN_WINDOWS
#endif

#ifdef _WIN64
#define CRYNN_WINDOWS
#endif