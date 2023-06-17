#include "event_application_event.h"

#include "event_application_event_impl.h"

namespace EB
{

    WindowResizedEvent::WindowResizedEvent(unsigned int width, unsigned int height)
        : Event(*new WindowResizedEventImpl(this, width, height))
    {

    }

    unsigned int WindowResizedEvent::width() const
    {
        return EB_IMPL(WindowResizedEvent)->width();
    }

    unsigned int WindowResizedEvent::height() const
    {
        return EB_IMPL(WindowResizedEvent)->height();
    }

    WindowClosedEvent::WindowClosedEvent()
        : Event(*new WindowClosedEventImpl(this))
    {

    }

}