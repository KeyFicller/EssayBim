#include "event_key_event_impl.h"

#include <sstream>

namespace EB
{

    KeyEventImpl::KeyEventImpl(Event* pFacade, int keyCode)
        : EventImpl(pFacade), m_KeyCode(keyCode)
    {

    }

    int KeyEventImpl::key() const
    {
        return m_KeyCode;
    }

    std::string KeyEventImpl::toString() const
    {
        std::stringstream ss;
        ss << m_pFacade->name() << ": " << m_KeyCode;
        return ss.str();
    }

    KeyReleasedEventImpl::KeyReleasedEventImpl(Event* pFacade, int keyCode)
        : KeyEventImpl(pFacade, keyCode)
    {

    }

    std::string KeyReleasedEventImpl::toString() const
    {
        std::stringstream ss;
        ss << m_pFacade->name() << ": " << m_KeyCode;
        return ss.str();
    }

    KeyPressedEventImpl::KeyPressedEventImpl(Event* pFacade, int keyCode, int repeatCount)
        : KeyEventImpl(pFacade, keyCode), m_Repeats(repeatCount)
    {

    }

    int KeyPressedEventImpl::repeats() const
    {
        return m_Repeats;
    }

    std::string KeyPressedEventImpl::toString() const
    {
        std::stringstream ss;
        ss << m_pFacade->name() << ": " << m_KeyCode << " (" << m_Repeats << ") repeats";
        return ss.str();
    }

    KeyTypedEventImpl::KeyTypedEventImpl(Event* pFacade, int keyCode)
        : KeyEventImpl(pFacade, keyCode)
    {

    }

    std::string KeyTypedEventImpl::toString() const
    {
        std::stringstream ss;
        ss << m_pFacade->name() << ": " << m_KeyCode;
        return ss.str();
    }

}