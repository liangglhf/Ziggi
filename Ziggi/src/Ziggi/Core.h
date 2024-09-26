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


#ifdef ZG_ENABLE_ASSERTS
	#define ZG_ASSERT(x,...){if(!(x)){ZG_ERROR("Assertion Failed:{0}",__VA_ARGS__); __debugerbreak();}}
	#define ZG_CORE_ASSERT(x,...){if(!(x)){ZG_ERROR("Assertion Failed:{0}",__VA_ARGS__); __debugerbreak();}}
#else
	#define ZG_ASSERT(x,...)
	#define ZG_CORE_ASSERT(x,...)
#endif



#define BIT(x) (1 << x)