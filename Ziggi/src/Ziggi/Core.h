#pragma once

#ifdef ZG_PLATFORM_WINDOWS
	#ifdef ZG_BUILD_DLL
		#define ZIGGI_API __declspec(dllexport)
	#else	
		#define ZIGGI_API __declspec(dllimport)
	#endif
#else
	#error Ziggi only supports Windows!
#endif