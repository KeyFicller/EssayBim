#include "event_mouse_button_event.h"

#include "event_mouse_button_event_impl.h"

namespace EB
{

    MouseButtonEvent::MouseButtonEvent(int mouseButton)
        : Event(*new MouseButtonEventImpl(this, mouseButton))
    {

    }

    MouseButtonEvent::MouseButtonEvent(MouseButtonEventImpl& impl)
        : Event(impl)
    {

    }

    int MouseButtonEvent::button() const
    {
        return EB_IMPL(MouseButtonEvent)->button();
    }

    MouseButtonPressedEvent::MouseButtonPressedEvent(int mouseButton)
        : MouseButtonEvent(*new MouseButtonPressedEventImpl(this, mouseButton))
    {

    }

    MouseButtonReleasedEvent::MouseButtonReleasedEvent(int mouseButton)
        : MouseButtonEvent(*new MouseButtonReleasedEventImpl(this, mouseButton))
    {

    }

}