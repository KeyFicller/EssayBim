#include "basic_log.h"

#include <iostream>

int main()
{
    EB::Log::core().trace("hello world.");
    EB::Log::core().trace("hello world %d.", 0);

    EB_CORE_ERROR("error at %d for %s", 123, "failed");

    return 0;
}