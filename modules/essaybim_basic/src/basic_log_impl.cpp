#include "basic_log_impl.h"

#include <iostream>

namespace EB
{

    LogImpl::LogImpl(const std::string& name)
    {
        (void)(name);
    }

    void LogImpl::trace(const char* fmt)
    {
        std::cout << fmt << std::endl;
    }

}