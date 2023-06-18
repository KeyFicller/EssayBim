#include "event_event_dispatcher.h"

#include "event_event_dispatcher_impl.h"

namespace EB
{

    EventDispatcher::EventDispatcher(Event& event)
    {
        EB_IMPL() = createScoped<EventDispatcherImpl>(event);
    }

    EventDispatcher::~EventDispatcher()
    {
        EB_IMPL().reset();
    }

    Event& EventDispatcher::event()
    {
        return EB_IMPL()->event();
    }
}