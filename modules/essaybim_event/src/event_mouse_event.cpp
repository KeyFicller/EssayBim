#include "event_mouse_event.h"

#include "event_mouse_event_impl.h"

namespace EB
{

    MouseMovedEvent::MouseMovedEvent(float x, float y)
        : Event(*new MouseMovedEventImpl(this, x, y))
    {

    }

    float MouseMovedEvent::x() const
    {
        return EB_IMPL(MouseMovedEvent)->x();
    }

    float MouseMovedEvent::y() const
    {
        return EB_IMPL(MouseMovedEvent)->y();
    }

    MouseScrolledEvent::MouseScrolledEvent(float x, float y)
        : Event(*new MouseScrolledEventImpl(this, x, y))
    {

    }

    float MouseScrolledEvent::x() const
    {
        return EB_IMPL(MouseScrolledEvent)->x();
    }

    float MouseScrolledEvent::y() const
    {
        return EB_IMPL(MouseScrolledEvent)->y();
    }

}