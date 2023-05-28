#pragma once

#include <spdlog/spdlog.h>

#include <string>

namespace EB
{
    class LogImpl final
    {
    public:
        explicit LogImpl(const std::string& name);

    public:
        void trace(const char* fmt);
        void info(const char* fmt);
        void warn(const char* fmt);
        void error(const char* fmt);
        void critical(const char* fmt);

    private:
        spdlog::logger m_RawLogger;
    };
}