#pragma once


#ifdef MDD_PLATFORM_WINDOWS
	#ifdef MDD_BUILD_DLL
		#define MDD2_API __declspec(dllexport)
	#else
		#define MDD2_API __declspec(dllimport)
	#endif
#else
	#error MDD2 Windows is supported!
#endif
