#include "event_key_event.h"

#include "event_key_event_impl.h"

namespace EB
{

    KeyEvent::KeyEvent(int keyCode)
        : Event(*new KeyEventImpl(this, keyCode))
    {
        
    }

    KeyEvent::KeyEvent(KeyEventImpl& impl)
        : Event(impl)
    {

    }

    int KeyEvent::key() const
    {
        return EB_IMPL(KeyEvent)->key();
    }

    KeyReleasedEvent::KeyReleasedEvent(int keyCode)
        : KeyEvent(*new KeyReleasedEventImpl(this, keyCode))
    {

    }

    KeyPressedEvent::KeyPressedEvent(int keyCode, int repeatCount)
        : KeyEvent(*new KeyPressedEventImpl(this, keyCode, repeatCount))
    {

    }

    int KeyPressedEvent::repeats() const
    {
        return EB_IMPL(KeyPressedEvent)->repeats();
    }

    KeyTypedEvent::KeyTypedEvent(int keyCode)
        : KeyEvent(*new KeyTypedEventImpl(this, keyCode))
    {

    }

}