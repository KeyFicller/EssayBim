#include "basic_time_step_impl.h"

#include "basic_log.h"
#include "basic_time_step.h"

#include <chrono>

namespace EB
{

    TimeStepImpl::TimeStepImpl(float time /*= 0.f*/)
        : m_Time(time)
    {

    }

    EB::TimeStep TimeStepImpl::deltaTime()
    {
        static bool init = false;
        static long long last = 0;

        auto now = std::chrono::high_resolution_clock::now();
        long long cur = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
        TimeStep timeStep((cur - last) / 1000.f);
        last = cur;
        if (!init) {
            init = true;
            EB_CORE_INFO("Initialized delta time counting...");
            return TimeStep(0.f);
        }
        return timeStep;
    }

    TimeStepImpl::operator float() const
    {
        return m_Time;
    }

    float TimeStepImpl::seconds() const
    {
        return m_Time;
    }

    float TimeStepImpl::mileseconds() const
    {
        return m_Time * 1000.f;
    }

    void TimeStepImpl::operator = (float time)
    {
        m_Time = time;
    }

}