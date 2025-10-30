#pragma once

#ifdef SMC_PLATFORM_WINDOWS
	#ifdef SMC_BUILD_DLL
		#define SMC_API __declspec(dllexport)
	#else
		#define SMC_API __declspec(dllimport)
	#endif
#else
	#error SMC only supports Windows!
#endif
