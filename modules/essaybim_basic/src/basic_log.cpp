#include "basic_log.h"

#include <iostream>

namespace EB
{
    Log::Log(const std::string& name)
    {
        (void)(name);
    }

    Log& Log::core()
    {
        static Log instance("Core");
        return instance;
    }

    Log& Log::client()
    {
        static Log instance("Client");
        return instance;
    }

    void Log::trace(const char* fmt)
    {
        std::cout << fmt << std::endl;
    }

}