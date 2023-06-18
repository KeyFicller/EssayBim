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

    MouseButtonPressedEvent::MouseButtonPressedEvent(int mouseButton, int repeatCount)
        : MouseButtonEvent(*new MouseButtonPressedEventImpl(this, mouseButton, repeatCount))
    {

    }

    int MouseButtonPressedEvent::repeats() const
    {
        return EB_IMPL(MouseButtonPressedEvent)->repeats();
    }

    MouseButtonReleasedEvent::MouseButtonReleasedEvent(int mouseButton)
        : MouseButtonEvent(*new MouseButtonReleasedEventImpl(this, mouseButton))
    {

    }

}