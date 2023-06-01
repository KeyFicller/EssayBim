#include "basic_time_step.h"

#include "basic_time_step_impl.h"

namespace EB
{

    TimeStep::TimeStep(float time /*= 0.f*/)
    {
        EB_IMPL = createScoped<TimeStepImpl>(time);
    }

    TimeStep::TimeStep(const TimeStep& other)
    {
        EB_IMPL = createScoped<TimeStepImpl>(*other.m_pImpl);
    }

    TimeStep::~TimeStep()
    {
    }

    TimeStep TimeStep::deltaTime()
    {
        return TimeStepImpl::deltaTime();
    }

    TimeStep::operator float() const
    {
        return static_cast<float>(*EB_IMPL);
    }

    TimeStep& TimeStep::operator=(const TimeStep& other)
    {
        *EB_IMPL = other.seconds();
        return *this;
    }

    float TimeStep::seconds() const
    {
        return EB_IMPL->seconds();
    }

    float TimeStep::mileseconds() const
    {
        return EB_IMPL->mileseconds();
    }

    void TimeStep::operator=(float time)
    {
        (*EB_IMPL) = time;
    }

}