#include "event_mouse_event_impl.h"

#include <sstream>

namespace EB
{

    MouseMovedEventImpl::MouseMovedEventImpl(Event* pFacade, float x, float y)
        : EventImpl(pFacade), m_X(x), m_Y(y)
    {

    }

    std::string MouseMovedEventImpl::toString() const
    {
        std::stringstream ss;
        ss << m_pFacade->name() << ": (" << m_X << ", " << m_Y << ")";
        return ss.str();
    }

    float MouseMovedEventImpl::x() const
    {
        return m_X;
    }

    float MouseMovedEventImpl::y() const
    {
        return m_Y;
    }

    MouseScrolledEventImpl::MouseScrolledEventImpl(Event* pFacade, float x, float y)
        : EventImpl(pFacade), m_X(x), m_Y(y)
    {

    }

    std::string MouseScrolledEventImpl::toString() const
    {
        std::stringstream ss;
        ss << m_pFacade->name() << ": (" << m_X << ", " << m_Y << ")";
        return ss.str();
    }

    float MouseScrolledEventImpl::x() const
    {
        return m_X;
    }

    float MouseScrolledEventImpl::y() const
    {
        return m_Y;
    }

}