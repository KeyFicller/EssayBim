#include "basic_log.h"
#include "basic_assert.h"
#include "basic_time_step.h"
#include "basic_instrument.h"

#include <iostream>
#include <windows.h>

int main()
{
    EB_PROFILE_BEGIN("main", "result.json");

    EB::Log::core().trace("hello world.");
    EB::Log::core().trace("hello world %d.", 0);

    EB_CORE_ERROR("error at %d for %s", 123, "failed");

    std::string str = "hello";
    EB_CORE_ERROR("error at %s", str.c_str());

    EB_CORE_INFO("Time : %f", EB::TimeStep::deltaTime().seconds());
    {
        EB_PROFILE_SCOPED("Sleeping");
        Sleep(2000);
    }
    EB_CORE_INFO("Time : %f", EB::TimeStep::deltaTime().seconds());
    
    EB_ASSERT(true);

    EB_PROFILE_END();

    return 0;
}