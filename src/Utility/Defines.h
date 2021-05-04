#pragma once

#define NODISCARD [[nodiscard]]
#define DLLEXPORT extern "c" __declspec(dllexport)

#ifdef _WIN32 
#define CRYNN_WINDOWS
#endif

#ifdef _WIN64
#define CRYNN_WINDOWS
#endif