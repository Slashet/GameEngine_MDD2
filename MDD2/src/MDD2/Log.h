#pragma once

#include <memory>
#include "core.h"
#include "spdlog/spdlog.h"

namespace MDD2
{
	class MDD2_API Log
	{
		public:
			static void  Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}



// Core log macros
#define MDD2_CORE_TRACE(...)    ::MDD2::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MDD2_CORE_INFO(...)    ::MDD2::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MDD2_CORE_WARN(...)    ::MDD2::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MDD2_CORE_ERROR(...)    ::MDD2::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MDD2_CORE_FATAL(...)    ::MDD2::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client log macros

#define MDD2_TRACE(...)    ::MDD2::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MDD2_INFO(...)    ::MDD2::Log::GetClientLogger()->info(__VA_ARGS__)
#define MDD2_WARN(...)    ::MDD2::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MDD2_ERROR(...)    ::MDD2::Log::GetClientLogger()->error(__VA_ARGS__)
#define MDD2_FATAL(...)    ::MDD2::Log::GetClientLogger()->fatal(__VA_ARGS__)
