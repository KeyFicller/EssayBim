#pragma once

#include <string>

namespace EB
{
    class LogImpl final
    {
        friend class Log;
    public:
        explicit LogImpl(const std::string& name);

    public:
        void trace(const char* fmt);
    };
}