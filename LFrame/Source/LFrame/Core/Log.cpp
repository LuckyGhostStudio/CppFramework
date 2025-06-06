#include "lpch.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace LFrame
{
    Ref<spdlog::logger> Log::s_CoreLogger;
    Ref<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");             // 日志格式：时间 名字 实际信息

        s_CoreLogger = spdlog::stdout_color_mt("LFrame");
        s_CoreLogger->set_level(spdlog::level::trace);      // 设置层级

        s_ClientLogger = spdlog::stdout_color_mt("LFrameApp");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}