#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Ryder 
{
	class RYDER_API Log
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

//Core Log Macros
#define RY_CORE_TRACE(...)     ::Ryder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RY_CORE_INFO(...)      ::Ryder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RY_CORE_WARN(...)      ::Ryder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RY_CORE_ERROR(...)     ::Ryder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RY_CORE_FATAL(...)     ::Ryder::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define RY_CLIENT_TRACE(...)   ::Ryder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RY_CLIENT_INFO(...)    ::Ryder::Log::GetClientLogger()->info(__VA_ARGS__)
#define RY_CLIENT_WARN(...)    ::Ryder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RY_CLIENT_ERROR(...)   ::Ryder::Log::GetClientLogger()->error(__VA_ARGS__)
#define RY_CLIENT_FATAL(...)   ::Ryder::Log::GetClientLogger()->fatal(__VA_ARGS__)

