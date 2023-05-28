#include "basic_log.h"

#include <iostream>

int main()
{
    EB::Log::core().trace("hello world.");

    return 0;
}