#include "basic_time_step.h"

#include "basic_time_step_impl.h"

namespace EB
{
    EB_IMPL_DEFAULT_COPY_IMPLEMENT(TimeStep);

    TimeStep::TimeStep(float time /*= 0.f*/)
    {
        EB_IMPL = createScoped<TimeStepImpl>(time);
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