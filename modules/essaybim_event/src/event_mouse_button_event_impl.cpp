#include "event_mouse_button_event_impl.h"

#include <sstream>

namespace EB
{

    MouseButtonEventImpl::MouseButtonEventImpl(Event* pFacade, int mouseButton)
        : EventImpl(pFacade), m_Button(mouseButton)
    {

    }

    int MouseButtonEventImpl::button() const
    {
        return m_Button;
    }

    std::string MouseButtonEventImpl::toString() const
    {
        std::stringstream ss;
        ss << m_pFacade->name() << ": " << m_Button;
        return ss.str();
    }

    MouseButtonPressedEventImpl::MouseButtonPressedEventImpl(Event* pFacade, int mouseButton)
        : MouseButtonEventImpl(pFacade, mouseButton)
    {

    }

    MouseButtonReleasedEventImpl::MouseButtonReleasedEventImpl(Event* pFacade, int mouseButton)
        : MouseButtonEventImpl(pFacade, mouseButton)
    {

    }

}