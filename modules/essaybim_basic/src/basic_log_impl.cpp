#include "basic_log_impl.h"

#include <spdlog/sinks/stdout_color_sinks.h>

#include <iostream>

namespace EB
{
    LogImpl::LogImpl(const std::string& name)
        : m_RawLogger(*spdlog::stdout_color_mt(name))
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        m_RawLogger.set_level(spdlog::level::trace);
    }

    void LogImpl::trace(const char* fmt)
    {
        m_RawLogger.trace(fmt);
    }

    void LogImpl::info(const char* fmt)
    {
        m_RawLogger.info(fmt);
    }

    void LogImpl::warn(const char* fmt)
    {
        m_RawLogger.warn(fmt);
    }

    void LogImpl::error(const char* fmt)
    {
        m_RawLogger.error(fmt);
    }

    void LogImpl::critical(const char* fmt)
    {
        m_RawLogger.critical(fmt);
    }

}