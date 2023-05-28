#pragma once

namespace EB
{
    class TimeStep;

    class TimeStepImpl
    {
    public:
        explicit TimeStepImpl(float time = 0.f);

    public:
        static TimeStep deltaTime();

    public:
        operator float() const;
        float seconds() const;
        float mileseconds() const;
        void operator = (float time);

    private:
        /* < delta time stored in seconds > */
        float m_Time = 0.f;
    };
}