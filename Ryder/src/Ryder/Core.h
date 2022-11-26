#pragma once

#ifdef RY_PLATFORM_WINDOWS
	#ifdef RY_BUILD_DLL
		#define RYDER_API __declspec(dllexport)
	#else 
		#define RYDER_API __declspec(dllimport)
	#endif
#else
	#error Ryder only supports Windows!
#endif
