#include "basic_log.h"
#include "basic_assert.h"

#include <iostream>

int main()
{
    EB::Log::core().trace("hello world.");
    EB::Log::core().trace("hello world %d.", 0);

    EB_CORE_ERROR("error at %d for %s", 123, "failed");

    std::string str = "hello";
    EB_CORE_ERROR("error at %s", str.c_str());
    
    EB_ASSERT(false);

    return 0;
}