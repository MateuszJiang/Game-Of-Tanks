#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace GameOfTanks {

	class Log
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


// core log macros
#define STATE_CORE_TRACE(...)		::GameOfTanks::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define STATE_CORE_INFO(...)		::GameOfTanks::Log::GetCoreLogger()->info(__VA_ARGS__)
#define STATE_CORE_WARN(...)		::GameOfTanks::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define STATE_CORE_ERROR(...)		::GameOfTanks::Log::GetCoreLogger()->error(__VA_ARGS__)
#define STATE_CORE_FATAL(...)		::GameOfTanks::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define STATE_TRACE(...)			::GameOfTanks::Log::GetClientLogger()->trace(__VA_ARGS__)
#define STATE_INFO(...)				::GameOfTanks::Log::GetClientLogger()->info(__VA_ARGS__)
#define STATE_WARN(...)				::GameOfTanks::Log::GetClientLogger()->warn(__VA_ARGS__)
#define STATE_ERROR(...)			::GameOfTanks::Log::GetClientLogger()->error(__VA_ARGS__)
#define STATE_FATAL(...)			::GameOfTanks::Log::GetClientLogger()->fatal(__VA_ARGS__)
