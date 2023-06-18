#pragma once

#include "event_event_dispatcher.h"

namespace EB
{
    class EventDispatcherImpl
    {
    public:
        EventDispatcherImpl(Event& event);
    public:
        Event& event();
    protected:
        Event& m_Event;
    };
}