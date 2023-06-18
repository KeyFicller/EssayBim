#include "event_event_dispatcher_impl.h"

namespace EB
{
    
    EventDispatcherImpl::EventDispatcherImpl(Event& event)
        : m_Event(event)
    {

    }

    Event& EventDispatcherImpl::event()
    {
        return m_Event;
    }
}