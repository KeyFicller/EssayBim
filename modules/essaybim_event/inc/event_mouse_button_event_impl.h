#pragma once

#include "event_event_base_impl.h"

namespace EB
{
    class MouseButtonEventImpl : public EventImpl
    {
    public:
        MouseButtonEventImpl(Event* pFacade, int mouseButton);
    public:
        int button() const;
        std::string toString() const override;
    protected:
        int m_Button;
    };

    class MouseButtonPressedEventImpl : public MouseButtonEventImpl
    {
    public:
        MouseButtonPressedEventImpl(Event* pFacade, int mouseButton, int repeatCount);
    public:
        int repeats() const;
        std::string toString() const override;
    protected:
        int m_Repeats;
    };

    class MouseButtonReleasedEventImpl : public MouseButtonEventImpl
    {
    public:
        MouseButtonReleasedEventImpl(Event* pFacade, int mouseButton);
    };
}