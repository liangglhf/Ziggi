#pragma once

//#include<memory>

#include"core.h"
#include"spdlog/spdlog.h"
#include"spdlog/fmt/ostr.h"

namespace Ziggi {


	class ZIGGI_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core log macros
#define ZG_CORE_ERROR(...)	::Ziggi::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZG_CORE_INFO(...)	::Ziggi::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZG_CORE_WARN(...)	::Ziggi::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZG_CORE_TRACE(...)	::Ziggi::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZG_CORE_FATAL(...)	::Ziggi::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define ZG_ERROR(...)		::Ziggi::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZG_INFO(...)		::Ziggi::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZG_WARN(...)		::Ziggi::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZG_TRACE(...)		::Ziggi::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZG_FATAL(...)		::Ziggi::Log::GetClientLogger()->fatal(__VA_ARGS__)