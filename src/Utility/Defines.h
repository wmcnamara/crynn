#pragma once

#define NODISCARD [[nodiscard]]
#define DLLEXPORT extern "c" __declspec(dllexport)

#ifdef _DEBUG 
#define CRYNN_DEBUG
#elif
#define CRYNN_RELEASE
#endif

#ifdef _WIN32 
#define CRYNN_WINDOWS
#endif

#ifdef _WIN64
#define CRYNN_WINDOWS
#endif

#ifdef NDEBUG
#define CRYNN_RELEASE
#endif